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

    void ImportLookupTable::SetSectionTable(SectionTable section_table)
    {
        section_table_ = section_table;
    }

    ImportLookupTable::ImportLookupTable(const char *pe_data, int offset, SectionTable& section_table, WORD version)
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
        field_vector_.clear();
        if (version_ == 0x10B)
        {
            if ((MemoryToUint32(pe_data + offset) & 0x80000000) == 1)
            {
                // Import by ordinal
                field_vector_.push_back(Field{
                    "Ordinal Number",
                    MemoryToUint32(pe_data + offset) & 0x0000ffff,
                    2
                });
            }
            else
            {
                DWORD rva = MemoryToUint32(pe_data + offset) & 0xffffffff;
                field_vector_.push_back(Field{
                    "Hint/Name Table RVA",
                    rva,
                    4
                });
                entry_ = HintNameTable(pe_data, section_table_.ConvertRvaToRawAddress(rva));

            }
        }
        else
        {
            if ((MemoryToUint64(pe_data + offset) & 0x8000000000000000) == 1)
            {
                // Import by ordinal
                field_vector_.push_back(Field{
                    "Ordinal Number",
                    MemoryToUint64(pe_data + offset) & 0x000000000000ffff,
                    2
                });
            }
            else
            {
                // Import by name
                DWORD rva = MemoryToUint32(pe_data + offset) & 0xffffffff;
                field_vector_.push_back(Field{
                    "Hint/Name Table RVA",
                    rva,
                    4
                });
                entry_ = HintNameTable(pe_data, section_table_.ConvertRvaToRawAddress(rva));
            }
        }
        
    }

    bool ImportLookupTable::IsOrdinalFlag() const
    {
        return false;
    }

    bool ImportLookupTable::IsNameFlag() const
    {
        return false;
    }
    
    Field ImportLookupTable::GetFieldByName(const std::string &name)
    {
        for (auto& field: field_vector_)
        {
            if (field.name == name)
            {
                return field;
            }
        }
        return Field();
    }
}
