#include "exportaddressentry.h"

namespace pe
{

    ExportDirectoryEntry::ExportDirectoryEntry(const char *pe_data, int export_address_rva, int name_pointer_rva, int biased_ordinal, std::shared_ptr<SectionTable> section_table_)
    {

    }

    void ExportDirectoryEntry::SetSectionTable(std::shared_ptr<SectionTable> section_table_)
    {

    }
    
    void ExportDirectoryEntry::SetExportDirectoryEntryData(const char *pe_data, int offset)
    {

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
