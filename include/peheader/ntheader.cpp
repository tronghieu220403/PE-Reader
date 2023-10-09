#include "cofffileheader.h"

namespace pe
{
    NtHeader::NtHeader(const char*, int begin_offset)
    {
        
    }

    std::shared_ptr<CoffFileHeader> NtHeader::GetFileHeader() const
    {
        return file_header_;
    }

    void NtHeader::SetFileHeader(const std::shared_ptr<CoffFileHeader> file_header)
    {
        file_header_ = file_header;
    }

    std::shared_ptr<OptionalHeader> NtHeader::GetOptionalHeader() const
    {
        return optional_header_;
    }

    void NtHeader::SetOptionalHeader(const std::shared_ptr<OptionalHeader> optional_header)
    {
        optional_header_ = optional_header;
    }
}