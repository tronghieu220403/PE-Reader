#include "resourcedataentry.h"

namespace pe 
{
    ResourceDataEntry::ResourceDataEntry(const char *pe_data, DWORD offset)
    {
        SetResourceDataEntry(pe_data, offset);
    }

    void ResourceDataEntry::SetResourceDataEntry(const char *pe_data, DWORD offset)
    {
        field_vector_.clear();

        field_vector_.push_back(
            Field{"Data RVA", 
            MemoryToUint32(pe_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"Size", 
            MemoryToUint32(pe_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"Codepage", 
            MemoryToUint32(pe_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"Reserved", 
            MemoryToUint32(pe_data + offset), 
            4}
        );
        offset += 4;
    }

    Field ResourceDataEntry::GetFieldByName(const std::string &name)
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