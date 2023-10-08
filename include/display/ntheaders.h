#ifndef PEREADER_DISPLAY_NTHEADER_H_
#define PEREADER_DISPLAY_NTHEADER_H_

#include "ulti/everything.h"
#include "display/fileheader.h"
#include "display/optionalheader.h"

namespace pe
{
    class NtHeaders
    {
        private:
            std::shared_ptr<FileHeader> file_header_;
            std::shared_ptr<OptionalHeader> optional_header_;
        public:

        NtHeaders(std::vector<char> file_header_data, std::vector<char> optional_header_data);

        std::shared_ptr<FileHeader> GetFileHeader() const;
        void SetFileHeader(const std::shared_ptr<FileHeader> file_header);

        std::shared_ptr<OptionalHeader> GetOptionalHeader() const;
        void SetOptionalHeader(const std::shared_ptr<OptionalHeader> file_header);

    }

}

#endif