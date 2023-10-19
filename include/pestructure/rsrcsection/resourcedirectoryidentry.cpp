#include "resourcedirectoryidentry.h"

namespace pe
{
    ResourceDirectoryIdEntry::ResourceDirectoryIdEntry(const char *pe_data, DWORD offset)
    {

    }

    void ResourceDirectoryIdEntry::SetResourceDirectoryIdEntry(const char *pe_data, DWORD offset)
    {

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
}