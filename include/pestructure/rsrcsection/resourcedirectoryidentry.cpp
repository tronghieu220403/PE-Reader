#include "resourcedirectoryidentry.h"

namespace pe
{
    ResourceDirectoryIdEntry::ResourceDirectoryIdEntry(const char *pe_data, DWORD offset, DWORD raw_base_offset):
        raw_base_offset_(raw_base_offset)
    {
        SetResourceDirectoryIdEntry(pe_data, offset);
    }

    void ResourceDirectoryIdEntry::SetResourceDirectoryIdEntry(const char *pe_data, DWORD offset)
    {
        Clean();
        if (raw_base_offset_ == DWORD(-1))
        {
            return;
        }

        DWORD id = MemoryToInt32(pe_data + offset);

        field_vector_.push_back(
            Field{"Integer ID", id, 4}
        );

        DWORD second_offset = MemoryToInt32(pe_data + offset + 4);

        if ((second_offset & 0x80000000) == 0) // Data Entry Offset
        {
            field_vector_.push_back(
                Field{"Data Entry Offset", second_offset, 4}
            );

            data_ = new ResourceDataEntry(pe_data, raw_base_offset_ + second_offset);
        }
        else // Subdirectory Offset
        {
            field_vector_.push_back(
                Field{"Subdirectory Offset", second_offset, 4}
            );

            table_ = new ResourceDirectoryTable(pe_data, raw_base_offset_ + second_offset - 0x80000000, raw_base_offset_);
        }

    }

    Field ResourceDirectoryIdEntry::GetFieldByName(const std::string &name)
    {
        for (auto& ele: field_vector_)
        {
            if (ele.name == name)
            {
                return ele;
            }
        }
        return Field();
    }

    void ResourceDirectoryIdEntry::Clean()
    {
        field_vector_.clear();
        if (table_ != nullptr)
        {
            delete table_;
            table_ = nullptr;
        }

        if (data_ != nullptr)
        {
            delete data_;
            data_ = nullptr;
        }
    }

    ResourceDirectoryIdEntry::~ResourceDirectoryIdEntry()
    {
        Clean();
    }

    std::string ResourceDirectoryIdEntry::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        for (auto& field: field_vector_)
        {
            s.append(pad_str + field.name + ": " + ToHex(field.value) + "\n");
        }
        s.append("\n");

        if (table_ != nullptr)
        {
            s.append(table_->ToString(pad + 1));
        }

        if (data_ != nullptr)
        {
            s.append(data_->ToString(pad + 1));
        }

        return s;
    }
}