#ifndef PEREADER_DISPLAY_DOSHEADER_H_
#define PEREADER_DISPLAY_DOSHEADER_H_

#include "ulti/everything.h"

namespace pe
{
    class DosHeader
    {
    private:
        IMAGE_DOS_HEADER dos_header_;
    public:
        DosHeader() = default;
        DosHeader(const char* pe_data);

        IMAGE_DOS_HEADER GetImageDosHeader() const;
        void SetImageDosHeader(const IMAGE_DOS_HEADER& dos_header);

        WORD GetMagicNumber() const;
        DWORD GetLfanew() const;

        bool IsValidExe() const;

        std::string ToString(int pad);        
    };

}

#endif