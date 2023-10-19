#include "resourcedirectorynameentry.h"

namespace pe
{
    ResourceDirectoryNameEntry::ResourceDirectoryNameEntry(const char *pe_data, DWORD offset, DWORD raw_base_offset):
        raw_base_offset_(raw_base_offset)
    {
        SetResourceDirectoryNameEntry(pe_data, offset);
    }

    void ResourceDirectoryNameEntry::SetResourceDirectoryNameEntry(const char *pe_data, DWORD offset)
    {
        if (raw_base_offset_ == DWORD(-1))
        {
            return;
        }
        DWORD name_offset = MemoryToInt32(pe_data + offset);
        name_ = ResourceDirectoryString((const WCHAR*)pe_data, raw_base_offset_ + name_offset);

        DWORD second_offset = MemoryToInt32(pe_data + offset + 4);

        if ((second_offset & 0x80000000) == 0) // Data Entry Offset
        {
            data_ = ResourceDataEntry(pe_data, raw_base_offset_ + second_offset);
        }
        else // Subdirectory Offset
        {
            table_ = ResourceDirectoryTable(pe_data, raw_base_offset_ + second_offset - 0x80000000, raw_base_offset_);
        }
    }

    Field ResourceDirectoryNameEntry::GetFieldByName(const std::string &name)
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
}
