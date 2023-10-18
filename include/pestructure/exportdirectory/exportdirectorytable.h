#ifndef PEREADER_PEHEADER_EXPORTDIRECTORYTABLE_EXPORTDIRECTORYTABLE_H_
#define PEREADER_PEHEADER_EXPORTDIRECTORYTABLE_EXPORTDIRECTORYTABLE_H_

#include "ulti/everything.h"
#include "pestructure/sectionheaders/sectiontable.h"
#include "pestructure/exportdirectory/exportaddressentry.h"

namespace pe
{
    class ExportDirectoryTable
    {
    private:
        std::vector<Field> field_vector_;
        std::shared_ptr<SectionTable> section_table_;
        std::vector<Field> entry_vector_;
    public:

        ExportDirectoryTable() = default;
        explicit ExportDirectoryTable(const char* pe_data, int offset, std::shared_ptr<SectionTable> section_table);

        void SetSectionTable(std::shared_ptr<SectionTable> section_table);

        void SetExportDirectoryTableData(const char* pe_data, int offset);

        void SetExportDirectoryTableEntries(const char* pe_data,int n_functions, int n_names, int address_of_functions, int address_of_names, int address_of_nameordinals);

        Field GetFieldByName(const std::string &name);
    };
}

#endif