#include "resourcedirectorytable.h"

namespace pe
{
    ResourceDirectoryTable::ResourceDirectoryTable(const char *pe_data, DWORD offset)
    {

    }

    void ResourceDirectoryTable::SetResourceDirectoryTable(const char *pe_data, DWORD offset)
    {

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
