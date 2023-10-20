#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMETABLE_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMETABLE_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/hintnameentry.h"

namespace pe
{
    class HintNameTable
    {
    private:
        std::vector<HintNameEntry> entry_vector_;
    public:

        HintNameTable() = default;
        explicit HintNameTable(const char* pe_data, int offset);

        void SetHintNameTable(const char* pe_data, int offset);

        std::string ToString(int pad);
        
    };
}

#endif