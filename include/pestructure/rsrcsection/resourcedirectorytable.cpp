#include "resourcedirectorytable.h"

namespace pe
{
    ResourceDirectoryTable::ResourceDirectoryTable(const char *pe_data, std::shared_ptr<SectionTable> section_table, std::shared_ptr<DataDiretoryTable> data_dir_table)
    {
        DataDiretory import = data_dir_table->GetDataDirectoryByName("Resource Table");
        DWORD rva = import.GetDataRelativeVirtualAddress();
        DWORD sz = import.GetDataSize();

        SectionHeader section_header = section_table->FindSectionByRva(rva, sz);
        if (section_header.GetFieldByName("ImageBase").value == 0)
        {
            return;
        }
        DWORD raw_offset = rva - static_cast<DWORD>(section_header.GetFieldByName("VirtualAddress").value) + static_cast<DWORD>(section_header.GetFieldByName("PointerToRawData").value);
        raw_base_offset_ = raw_offset;
        SetResourceDirectoryTable(pe_data, raw_offset);
    }

    ResourceDirectoryTable::ResourceDirectoryTable(const char *pe_data, DWORD offset, DWORD raw_base_offset):
        raw_base_offset_(raw_base_offset)
    {
        SetResourceDirectoryTable(pe_data, offset);
    }

    void ResourceDirectoryTable::SetResourceDirectoryTable(const char *pe_data, DWORD offset)
    {
        DWORD n_name_entries;
        DWORD n_id_entries;

        field_vector_.push_back(
            Field{"Characteristics", 
            MemoryToUint32(pe_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"Time Stamp", 
            MemoryToUint32(pe_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"Major Version", 
            MemoryToUint16(pe_data + offset), 
            2}
        );
        offset += 2;

        field_vector_.push_back(
            Field{"Minor Version", 
            MemoryToUint16(pe_data + offset), 
            4}
        );
        offset += 2;

        n_name_entries = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(
            Field{"Number of Name Entries", 
            n_name_entries, 
            4}
        );
        offset += 4;

        n_id_entries = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(
            Field{"Number of ID Entries", 
            n_id_entries,
            4}
        );
        offset += 4;
        
        for (DWORD i=0 ; i< n_name_entries; ++i)
        {
            name_entry_vector_.push_back(new ResourceDirectoryNameEntry(pe_data, offset, raw_base_offset_));
            offset += 8;
        }

        for (DWORD i=0 ; i< n_id_entries; ++i)
        {
            id_entry_vector_.push_back(new ResourceDirectoryIdEntry(pe_data, offset, raw_base_offset_));
            offset += 8;
        }

    }

    Field ResourceDirectoryTable::GetFieldByName(const std::string &name)
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

    void ResourceDirectoryTable::Clean()
    {
        field_vector_.clear();
        for (int i = 0; i < id_entry_vector_.size(); i++)
        {
            delete id_entry_vector_[i];
        }
        id_entry_vector_.clear();

        for (int i = 0; i < name_entry_vector_.size(); i++)
        {
            delete name_entry_vector_[i];
        }
        name_entry_vector_.clear();

    }

    ResourceDirectoryTable::~ResourceDirectoryTable()
    {
        Clean();
    }

    std::string ResourceDirectoryTable::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        std::string sub_pad_str(pad * 4 + 2, ' ');
        s.append(pad_str + "Resource Directory Table:\n\n");
        for (auto& field: field_vector_)
        {
            s.append(sub_pad_str + field.name + ": " + ToHex(field.value) + "\n");
        }
        s.append("\n");
        for (int i = 0; i < id_entry_vector_.size(); i++)
        {
            s.append(sub_pad_str + "Resource Directory ID Entry number " + std::to_string(i+1) + ":\n");
            s.append(id_entry_vector_[i]->ToString(pad+1));
        }
        id_entry_vector_.clear();

        for (int i = 0; i < name_entry_vector_.size(); i++)
        {
            s.append(sub_pad_str + "Resource Directory Name Entry number " + std::to_string(i+1) + ":\n");
            s.append(id_entry_vector_[i]->ToString(pad+1));
        }

        return s;
    }
}
