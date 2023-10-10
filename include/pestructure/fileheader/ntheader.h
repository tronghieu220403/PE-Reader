#ifndef PEREADER_PEHEADER_NTHEADER_H_
#define PEREADER_PEHEADER_NTHEADER_H_

#include "ulti/everything.h"
#include "pestructure/fileheader/cofffileheader.h"
#include "pestructure/fileheader/optionalheader.h"

namespace pe
{
    class NtHeader
    {
    private:
        Field signature_;
        std::shared_ptr<CoffFileHeader> file_header_;
        std::shared_ptr<OptionalHeader> optional_header_;
    public:

        NtHeader() = default;
        explicit NtHeader(const char* nt_data);

        void SetNtHeaderData(const char* nt_data);

        std::shared_ptr<CoffFileHeader> GetCoffFileHeader() const;
        void SetCoffFileHeader(const std::shared_ptr<CoffFileHeader> file_header);

        std::shared_ptr<OptionalHeader> GetOptionalHeader() const;
        void SetOptionalHeader(const std::shared_ptr<OptionalHeader> optional_header);

    };
}

#endif