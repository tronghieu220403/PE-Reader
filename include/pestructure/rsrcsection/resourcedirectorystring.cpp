#include "resourcedirectorystring.h"

namespace pe
{
    ResourceDirectoryString::ResourceDirectoryString(const char *pe_data, DWORD offset)
    {
        SetResourceDirectoryString(pe_data, offset);
    }

    void ResourceDirectoryString::SetResourceDirectoryString(const char *pe_data, DWORD offset)
    {
        WORD size = MemoryToUint16((const char*)pe_data + offset);
        SetContent(MemoryToWstring((const WCHAR*)(pe_data + offset + 2), size));
    }

    void ResourceDirectoryString::SetContent(const std::wstring& content)
    {
        content_ = content;
    }

    std::wstring ResourceDirectoryString::GetContent() const
    {
        return content_;
    }
}