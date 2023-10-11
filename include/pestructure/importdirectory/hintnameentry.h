#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMEENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMEENTRY_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/hintnameentry.h"

namespace pe
{
    class HintNameEntry
    {
    private:
        std::vector<HintNameEntry> entry_;
    public:

        HintNameEntry() = default;
        explicit HintNameEntry(const char* pe_data, int offset);

        void SetHintNameTable(const char* pe_data, int offset);

        
    };
}

#endif