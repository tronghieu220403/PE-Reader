#ifndef PEREADER_DISPLAY_NTHEADER_H_
#define PEREADER_DISPLAY_NTHEADER_H_

#include "ulti/everything.h"
#include "peheader/fileheader.h"
#include "peheader/optionalheader.h"

namespace pe
{
    class NtHeader
    {
    private:
        std::shared_ptr<CoffFileHeader> file_header_;
        std::shared_ptr<OptionalHeader> optional_header_;
    public:

        NtHeader() = default;
        NtHeader(const char* pe_data, int begin_offset);

        std::shared_ptr<CoffFileHeader> GetFileHeader() const;
        void SetFileHeader(const std::shared_ptr<CoffFileHeader> file_header);

        std::shared_ptr<OptionalHeader> GetOptionalHeader() const;
        void SetOptionalHeader(const std::shared_ptr<OptionalHeader> optional_header);

    };
}

#endif