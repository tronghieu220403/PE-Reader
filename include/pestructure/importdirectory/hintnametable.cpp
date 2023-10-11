#include "hintnametable.h"

namespace pe
{
    HintNameTable::HintNameTable(const char *pe_data, int offset)
    {
        SetImportLookupEntry(pe_data, offset);
    }

    void HintNameTable::SetImportLookupEntry(const char *pe_data, int offset)
    {
        offset -= 2;
        hint_ = Field{"Hint", 
            MemoryToUint32(pe_data + (offset += 2)), 
            2};
        name_ =
            FieldStr{"Name", 
            MemoryToString(pe_data + offset)};
    }
}
