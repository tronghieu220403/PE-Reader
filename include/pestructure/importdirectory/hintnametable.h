#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMETABLE_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMETABLE_H_

#include "ulti/everything.h"

namespace pe
{
    class HintNameTable
    {
    private:
        Field hint_;
        FieldStr name_;
    public:

        HintNameTable() = default;
        explicit HintNameTable(const char* pe_data, int offset);

        void SetImportLookupEntry(const char* pe_data, int offset);

        
    };
}

#endif