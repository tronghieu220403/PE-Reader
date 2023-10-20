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
            entry_vector_.push_back(entry);
            offset += entry.GetSize();
        }
    }

    std::string HintNameTable::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        s.append(pad_str + "Hint/Name Talbe:\n\n");
        for (auto &entry: entry_vector_)
        {
            s.append(entry.ToString(pad+1) + "\n");
        }
        return s;
    }
}
