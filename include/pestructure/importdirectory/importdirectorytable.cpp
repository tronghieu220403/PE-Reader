#include "importdirectorytable.h"

namespace pe
{
    ImportDirectoryTable::ImportDirectoryTable(const char* pe_data, std::shared_ptr<SectionTable> section_table, DataDiretoryTable& data_dir_table, WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;

        DataDiretory import = data_dir_table.GetDataDirectoryByName("Import Table");
        DWORD rva = import.GetDataRelativeVirtualAddress();
        DWORD sz = import.GetDataSize();

        SectionHeader section_header = section_table->FindSectionByRva(rva, sz);
        if (section_header.GetFieldByName("ImageBase").value == 0)
        {
            return;
        }
        DWORD raw_offset = rva - static_cast<DWORD>(section_header.GetFieldByName("VirtualAddress").value) + static_cast<DWORD>(section_header.GetFieldByName("PointerToRawData").value);

        SetImportDirectoryTableData(pe_data, raw_offset);

    }

    void ImportDirectoryTable::SetSectionTable(const std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    void ImportDirectoryTable::SetVersion(WORD version)
    {
        version_ = version;
    }

    void ImportDirectoryTable::SetImportDirectoryTableData(const char *pe_data, DWORD offset)
    {
        if (version_ != 0x20B && version_ != 0x10B)
        {
            return;
        }
        entry_vector_.clear();
        while(true)
        {
            bool end_of_table = true;
            for (int i = 0; i < 20; i++)
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
            entry_vector_.push_back(ImportDirectoryEntry(pe_data, offset, section_table_, version_));
            offset += 20;
        }
    }
    
    std::string ImportDirectoryTable::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        s.append(pad_str + "Import Directory Table:\n\n");
        for (auto& entry: entry_vector_)
        {
            s.append(entry.ToString(pad+1)+"\n");
        }
        return s;

    }

}
