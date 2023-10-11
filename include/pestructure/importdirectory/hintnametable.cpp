#include "hintnametable.h"

namespace pe
{
    HintNameTable::HintNameTable(const char *pe_data, int offset)
    {
        SetHintNameTable(pe_data, offset);
    }

    void HintNameTable::SetHintNameTable(const char *pe_data, int offset)
    {
        HintNameEntry entry;

        while(true)
        {
            entry = HintNameEntry(pe_data, offset);
            if (entry.GetNameField().value.size() == 0)
            {
                break;
            }
            entry_.push_back(entry);
        }
    }
}
