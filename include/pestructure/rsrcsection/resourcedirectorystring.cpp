#include "resourcedirectorystring.h"

namespace pe
{
    ResourceDirectoryString::ResourceDirectoryString(const char *pe_data, DWORD offset)
    {

    }

    void ResourceDirectoryString::SetResourceDirectoryString(const char *pe_data, DWORD offset)
    {

    }

    void ResourceDirectoryString::SetContent(const std::wstring &content)
    {
        content_ = content;
    }

    std::wstring ResourceDirectoryString::GetContent() const
    {
        return content_;
    }
}