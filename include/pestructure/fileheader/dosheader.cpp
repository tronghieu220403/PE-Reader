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

    std::string DosHeader::ToString(int pad)
    {
        std::string pad_str(pad * 4, ' ');
        IMAGE_DOS_HEADER header = GetImageDosHeader();
        std::string s;
        s.append(pad_str + "e_emagic: " + ToHex(header.e_magic) + "\n");// Magic number
        s.append(pad_str + "e_cblp: " + ToHex(header.e_cblp) + "\n");// Bytes on last page of file
        s.append(pad_str + "e_cp: " + ToHex(header.e_cp) + "\n");// Pages in file
        s.append(pad_str + "e_crlc: " + ToHex(header.e_crlc) + "\n");// Relocations
        s.append(pad_str + "e_cparhdr: " + ToHex(header.e_cparhdr) + "\n");// Size of header in paragraphs
        s.append(pad_str + "e_minalloc: " + ToHex(header.e_minalloc) + "\n");// Minimum extra paragraphs needed
        s.append(pad_str + "e_maxalloc: " + ToHex(header.e_maxalloc) + "\n");// Maximum extra paragraphs needed
        s.append(pad_str + "e_ss: " + ToHex(header.e_ss) + "\n");// Initial (relative) SS value
        s.append(pad_str + "e_sp: " + ToHex(header.e_sp) + "\n");// Initial SP value
        s.append(pad_str + "e_csum: " + ToHex(header.e_csum) + "\n");// Checksum
        s.append(pad_str + "e_ip: " + ToHex(header.e_ip) + "\n");// Initial IP value
        s.append(pad_str + "e_cs: " + ToHex(header.e_cs) + "\n");// Initial (relative) CS value
        s.append(pad_str + "e_lfarlc: " + ToHex(header.e_lfarlc) + "\n");//File address of relocation table
        s.append(pad_str + "e_ovno: " + ToHex(header.e_ovno) + "\n");// Overlay number
        s.append(pad_str + "e_oemid: " + ToHex(header.e_oemid) + "\n");// OEM identifier (for e_oeminfo)
        s.append(pad_str + "e_oeminfo: " + ToHex(header.e_oeminfo) + "\n");// OEM information; e_oemid specific
        s.append(pad_str + "e_lfanew: " + ToHex(header.e_lfanew) + "\n");// File address of new exe header

        return s;
    }
}