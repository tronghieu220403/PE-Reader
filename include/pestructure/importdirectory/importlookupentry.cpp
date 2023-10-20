#include "importlookupentry.h"

namespace pe
{
    ImportLookupEntry::ImportLookupEntry(WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;
    }

    void ImportLookupEntry::SetVersion(WORD version)
    {
        version_ = version;
    }

    void ImportLookupEntry::SetSectionTable(const std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    ImportLookupEntry::ImportLookupEntry(const char *pe_data, int offset, std::shared_ptr<SectionTable> section_table, WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;
        section_table_ = section_table;
        SetImportLookupEntryData(pe_data, offset);
    }

    void ImportLookupEntry::SetImportLookupEntryData(const char *pe_data, int offset)
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
                entry_ = HintNameTable(pe_data, section_table_->ConvertRvaToRawAddress(rva));
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
                entry_ = HintNameTable(pe_data, section_table_->ConvertRvaToRawAddress(rva));
            }
        }
        
    }

    bool ImportLookupEntry::IsOrdinalFlag() const
    {
        return false;
    }

    bool ImportLookupEntry::IsNameFlag() const
    {
        return false;
    }
    
    Field ImportLookupEntry::GetFieldByName(const std::string &name)
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

    std::string ImportLookupEntry::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        for (auto& field: field_vector_)
        {
            s.append(pad_str + field.name + ": " + ToHex(field.value) + "\n");
            if (field.name == "Hint/Name Table RVA")
            {
                s.append("\n" + entry_.ToString(pad+1));
            }
        }
        return s;

    }

}
