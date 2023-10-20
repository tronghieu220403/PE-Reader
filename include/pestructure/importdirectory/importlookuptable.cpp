#include "importlookuptable.h"

namespace pe
{
    ImportLookupTable::ImportLookupTable(WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;
    }

    void ImportLookupTable::SetVersion(WORD version)
    {
        version_ = version;
    }

    void ImportLookupTable::SetSectionTable(const std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    ImportLookupTable::ImportLookupTable(const char *pe_data, int offset, std::shared_ptr<SectionTable> section_table, WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;
        section_table_ = section_table;
        SetImportLookupTableData(pe_data, offset);
    }

    void ImportLookupTable::SetImportLookupTableData(const char *pe_data, int offset)
    {
        if (version_ != 0x20B && version_ != 0x10B)
        {
            return;
        }

        int data_size = version_ == 0x10B ? 4 : 8;

        import_lookup_entry_vector_.clear();
        while(true)
        {
            bool end_of_table = true;
            for (int i = 0; i < data_size; i++)
            {
                if (pe_data[offset + i] != 0)
                {
                    end_of_table = false;
                    break;
                }
            }
            if (end_of_table == true)
            {
                break;
            }
            import_lookup_entry_vector_.push_back(ImportLookupEntry(pe_data, offset, section_table_, version_));
            offset += data_size;
        }
    }

    std::string ImportLookupTable::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        s.append(pad_str + "Import Lookup Table:\n\n");
        for (auto& entry: import_lookup_entry_vector_)
        {
            s.append(entry.ToString(pad+1) + "\n");
        }
        return s;
    }
}
