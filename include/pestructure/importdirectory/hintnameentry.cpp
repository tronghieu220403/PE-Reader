#include "hintnameentry.h"

namespace pe
{
    HintNameEntry::HintNameEntry(const char *pe_data, int offset)
    {
        SetHintNameEntry(pe_data, offset);
    }

    void HintNameEntry::SetHintNameEntry(const char *pe_data, int offset)
    {
        hint_ = Field{"Hint", 
            MemoryToUint16(pe_data + offset), 
            2};
        offset += 2;
        name_ =
            FieldStr{"Name", 
            MemoryToString(pe_data + offset)};
        if ( ((size_t)offset + name_.value.size() + 1) % 2 == 1)
        {
            pad_ = 2;
        }
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
        return static_cast<int>(name_.value.size()) + 2 + pad_;
    }

    std::string HintNameEntry::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        s.append(pad_str + "Hint: " + ToHex(GetHintField().value) + "\n");
        s.append(pad_str + "Name: " + GetNameField().value + "\n");
        return s;
    }

}
