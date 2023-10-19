#include "resourcedirectorynameentry.h"

namespace pe
{
    ResourceDirectoryNameEntry::ResourceDirectoryNameEntry(const char *pe_data, DWORD offset)
    {

    }
    void ResourceDirectoryNameEntry::SetResourceDirectoryNameEntry(const char *pe_data, DWORD offset)
    {

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
