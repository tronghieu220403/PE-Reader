#include "hintnameentry.h"

namespace pe
{
    HintNameEntry::HintNameEntry(const char *pe_data, int offset)
    {
        SetHintNameEntry(pe_data, offset);
    }

    void HintNameEntry::SetHintNameEntry(const char *pe_data, int offset)
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
