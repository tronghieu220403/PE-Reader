#ifndef PEREADER_PEHEADER_EXPORTDIRECTORYTABLE_EXPORTDIRECTORYTABLE_H_
#define PEREADER_PEHEADER_EXPORTDIRECTORYTABLE_EXPORTDIRECTORYTABLE_H_

#include "ulti/everything.h"
#include "pestructure/sectionheaders/sectiontable.h"

namespace pe
{
    class ExportDirectoryTable
    {
    private:
        std::vector<Field> field_vector_;
        std::shared_ptr<SectionTable> section_table_;
    public:

        ExportDirectoryTable() = default;
        explicit ExportDirectoryTable(const char* pe_data, int offset, std::shared_ptr<SectionTable> section_table);

        void SetSectionTable(std::shared_ptr<SectionTable> section_table);

        void SetExportDirectoryTableData(const char* pe_data, int offset);

        Field GetFieldByName(const std::string &name);
    };
}

#endif