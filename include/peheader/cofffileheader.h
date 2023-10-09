#ifndef PEREADER_DISPLAY_COFFFILEHEADER_H_
#define PEREADER_DISPLAY_COFFFILEHEADER_H_

#include "ulti/everything.h"
#include "peheader/fileheader.h"
#include "peheader/optionalheader.h"

namespace pe
{
    class CoffFileHeader // Nt Header
    {
    private:
        std::shared_ptr<FileHeader> file_header_;
        std::shared_ptr<OptionalHeader> optional_header_;
    public:

        CoffFileHeader() = default;
        CoffFileHeader(const char* pe_data, int begin_offset);

        std::shared_ptr<FileHeader> GetFileHeader() const;
        void SetFileHeader(const std::shared_ptr<FileHeader> file_header);

        std::shared_ptr<OptionalHeader> GetOptionalHeader() const;
        void SetOptionalHeader(const std::shared_ptr<OptionalHeader> optional_header);

    };
}

#endif