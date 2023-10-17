#ifndef PEREADER_PEHEADER_EXPORTDIRECTORYENTRY_EXPORTDIRECTORYENTRY_H_
#define PEREADER_PEHEADER_EXPORTDIRECTORYENTRY_EXPORTDIRECTORYENTRY_H_

#include "ulti/everything.h"
#include "pestructure/sectionheaders/sectiontable.h"

namespace pe
{
    class ExportDirectoryEntry
    {
    private:
        std::vector<Field> field_vector_;
        std::vector<FieldStr> field_str_vector_;
        std::shared_ptr<SectionTable> section_table_;
    public:

        ExportDirectoryEntry() = default;
        explicit ExportDirectoryEntry(const char* pe_data, int export_address_rva, int name_pointer_rva, int ordinal, std::shared_ptr<SectionTable> section_table_);

        void SetSectionTable(std::shared_ptr<SectionTable> section_table_);

        void SetExportDirectoryEntryData(const char* pe_data, int offset);

        Field GetFieldByName(const std::string &name);
        Field GetFieldStrByName(const std::string &name);

    };
}

#endif