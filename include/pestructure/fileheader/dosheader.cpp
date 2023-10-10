#include "dosheader.h"

namespace pe
{
    DosHeader::DosHeader(const char *pe_data)
    {
        memcpy(&dos_header_, pe_data, sizeof(IMAGE_DOS_HEADER));
    }

    IMAGE_DOS_HEADER DosHeader::GetImageDosHeader() const
    {
        return dos_header_;
    }

    void DosHeader::SetImageDosHeader(const IMAGE_DOS_HEADER &dos_header)
    {
        dos_header_ = dos_header;
    }

    WORD DosHeader::GetMagicNumber() const
    {
        return GetImageDosHeader().e_magic;
    }
    
    DWORD DosHeader::GetLfanew() const
    {
        return GetImageDosHeader().e_lfanew;
    }

    bool DosHeader::IsValidExe() const
    {
        return GetMagicNumber() == 0x5a4d;
    }
}