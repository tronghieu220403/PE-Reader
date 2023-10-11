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

    Field HintNameEntry::GetHintField() const
    {
        return hint_;
    }

    FieldStr HintNameEntry::GetNameField() const
    {
        return name_;
    }

    int HintNameEntry::GetSize() const
    {
        return name_.value.size() + 2 + 1;
    }

}
