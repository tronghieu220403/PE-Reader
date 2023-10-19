#include "resourcedirectoryidentry.h"

namespace pe
{
    ResourceDirectoryIdEntry::ResourceDirectoryIdEntry(const char *pe_data, DWORD offset, DWORD raw_base_offset)
    {

    }

    void ResourceDirectoryIdEntry::SetResourceDirectoryIdEntry(const char *pe_data, DWORD offset, DWORD raw_base_offset)
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