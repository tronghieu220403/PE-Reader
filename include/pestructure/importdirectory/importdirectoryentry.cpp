#include "importdirectoryentry.h"

namespace pe
{
    ImportDirectoryEntry::ImportDirectoryEntry(const char *pe_data, int offset, std::shared_ptr<SectionTable> section_table, WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;
        section_table_ = section_table;

        SetImportDirectoryEntry(pe_data, offset);
    }

    void ImportDirectoryEntry::SetSectionTable(std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    void ImportDirectoryEntry::SetVersion(WORD version)
    {
        version_ = version;
    }

    void ImportDirectoryEntry::SetImportDirectoryEntry(const char *pe_data, int offset)
    {
        if (version_ != 0x20B && version_ != 0x10B)
        {
            return;
        }

        field_vector_.clear();
        offset -= 4;

        DWORD ilt_rva = MemoryToUint32(pe_data + (offset += 4));

        field_vector_.push_back(
            Field{"Import Lookup Table RVA", 
            ilt_rva, 
            4}
        );
        import_lookup_table_ = ImportLookupTable(pe_data, section_table_->ConvertRvaToRawAddress(ilt_rva), section_table_, version_);

        field_vector_.push_back(
            Field{"Time/Date Stamp", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Forwarder Chain", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Name RVA", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Import Address Table RVA", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );
    }

    std::string ImportDirectoryEntry::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        for (auto& field: field_vector_)
        {
            s.append(pad_str + field.name + ": " + ToHex(field.value) + "\n");
        }
        s.append("\n");
        s.append(import_lookup_table_.ToString(pad+1));
        return s;
    }

}
