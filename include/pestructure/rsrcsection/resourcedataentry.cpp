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

    std::string ResourceDataEntry::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        std::string sub_pad_str(pad * 4, ' ');
        s.append(pad_str + "Resource Data Entry:\n\n");
        for (auto& field: field_vector_)
        {
            s.append(sub_pad_str + field.name + ": " + ToHex(field.value) + "\n");
        }
        s.append("\n");
        return s;
    }
}