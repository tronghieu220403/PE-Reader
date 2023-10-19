#include "resourcedataentry.h"

namespace pe 
{
    ResourceDataEntry::ResourceDataEntry(const char *pe_data, DWORD offset)
    {

    }

    void ResourceDataEntry::SetResourceDataEntry(const char *pe_data, DWORD offset)
    {

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