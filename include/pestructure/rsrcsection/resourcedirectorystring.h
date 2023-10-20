#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYSTRING_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYSTRING_H_

#include "ulti/everything.h"

namespace pe
{
    class ResourceDirectoryString
    {
    private:
        std::wstring content_;
    public:
        ResourceDirectoryString() = default;
        ResourceDirectoryString(const char* pe_data, DWORD offset);
        
        void SetResourceDirectoryString(const char* pe_data, DWORD offset);

        void SetContent(const std::wstring& content);
        std::wstring GetContent() const;

    };
}

#endif