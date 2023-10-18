#include "exportaddressentry.h"

namespace pe
{

    ExportDirectoryEntry::ExportDirectoryEntry(const char *pe_data, int export_address_rva_offset, int name_pointer_rva_offset, int biased_ordinal, std::shared_ptr<SectionTable> section_table):
        section_table_(section_table)
    {

    }

    void ExportDirectoryEntry::SetSectionTable(std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }
    
    void ExportDirectoryEntry::SetExportDirectoryEntryData(const char *pe_data, int export_address_rva_offset, int name_pointer_rva_offset, int biased_ordinal)
    {
        // Phải check xem export_address_rva là Export RVA hay Forwarder RVA, nếu là export RVA thì mới có name_pointer_rva
    }

    Field ExportDirectoryEntry::GetFieldByName(const std::string &name)
    {
        return Field();
    }

    Field ExportDirectoryEntry::GetFieldStrByName(const std::string &name)
    {
        return Field();
    }
}
