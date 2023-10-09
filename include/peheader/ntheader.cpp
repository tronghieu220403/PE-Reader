#include "ntheader.h"

namespace pe
{
    NtHeader::NtHeader(const char* nt_data)
    {
        SetNtHeaderData(nt_data);
    }

    void NtHeader::SetNtHeaderData(const char *nt_data)
    {
        signature_ = {"Signature", MemoryToUint32(nt_data), 4};
        if (signature_.value !=0x4550)
        {
            return;
        }
        SetCoffFileHeader(std::make_shared<CoffFileHeader>(nt_data + 4));
        SetOptionalHeader(std::make_shared<OptionalHeader>(nt_data + 24));
    }

    std::shared_ptr<CoffFileHeader> NtHeader::GetCoffFileHeader() const
    {
        return file_header_;
    }

    void NtHeader::SetCoffFileHeader(const std::shared_ptr<CoffFileHeader> file_header)
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