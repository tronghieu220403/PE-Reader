#include "cofffileheader.h"

namespace pe
{
    CoffFileHeader::CoffFileHeader(const char*, int begin_offset)
    {
        
    }

    std::shared_ptr<FileHeader> CoffFileHeader::GetFileHeader() const
    {
        return file_header_;
    }

    void CoffFileHeader::SetFileHeader(const std::shared_ptr<FileHeader> file_header)
    {
        file_header_ = file_header;
    }

    std::shared_ptr<OptionalHeader> CoffFileHeader::GetOptionalHeader() const
    {
        return optional_header_;
    }

    void CoffFileHeader::SetOptionalHeader(const std::shared_ptr<OptionalHeader> optional_header)
    {
        optional_header_ = optional_header;
    }
}