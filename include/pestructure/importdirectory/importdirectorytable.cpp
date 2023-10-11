#include "importdirectorytable.h"

namespace pe
{
    ImportDirectoryTable::ImportDirectoryTable(const char* pe_data, SectionTable& section_table, DataDiretoryTable& data_dir_table, WORD version)
    {
        if (version != 0x20B && version != 0x10B)
        {
            return;
        }
        version_ = version;

        DataDiretory import = data_dir_table.GetDataDirectoryByName("Import Table");
        DWORD rva = import.GetDataRelativeVirtualAddress();
        DWORD sz = import.GetDataSize();

        SectionHeader section_header = section_table.FindSectionByRva(rva, sz);
        if (section_header.GetFieldByName("ImageBase").value == 0)
        {
            return;
        }
        int raw_offset = rva - section_header.GetFieldByName("VirtualAddress").value + section_header.GetFieldByName("PointerToRawData").value;

        SetImportDirectoryTableData(pe_data, raw_offset, data_dir_table);

    }

    void ImportDirectoryTable::SetVersion(WORD version)
    {
        version_ = version;
    }

    void ImportDirectoryTable::SetImportDirectoryTableData(const char *pe_data, int offset, DataDiretoryTable& data_dir_table)
    {
        /*
        if (version_ != 0x20B && version_ != 0x10B)
        {
            return;
        }
        entry_.clear();
        if (version_ == 0x10B)
        {
            for (int i = 0; MemoryToUint32(pe_data + offset + i) != 0 ; i+= 4)
            {
                entry_.push_back(ImportDirectoryEntry(

                ))
            }
        }
        else if (version_ == 0x20B)
        {
            for (int i = 0; MemoryToUint64(pe_data + offset + i) != 0 ; i+= 8)
            {
                
            }
        }
        */
    }
    
    ImportDirectoryEntry ImportDirectoryTable::GetImportDirectoryEntryByDllName(const std::string &name) const
    {
        return ImportDirectoryEntry();
    }
}
