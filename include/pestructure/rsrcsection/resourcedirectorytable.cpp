#include "resourcedirectorytable.h"

namespace pe
{
    ResourceDirectoryTable::ResourceDirectoryTable(const char *pe_data, DWORD offset)
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
            // Do something

            offset += 8;
        }

        for (DWORD i=0 ; i< n_id_entries; ++i)
        {
            
            // Do something

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
}
