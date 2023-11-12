#ifndef PEREADER_PEHEADER_EXPORTDIRECTORYTABLE_EXPORTDIRECTORYTABLE_H_
#define PEREADER_PEHEADER_EXPORTDIRECTORYTABLE_EXPORTDIRECTORYTABLE_H_

#include "ulti/everything.h"
#include "pestructure/sectionheaders/sectiontable.h"
#include "pestructure/exportdirectory/exportaddressentry.h"
#include "pestructure/fileheader/optionalheader.h"

namespace pe
{
    class ExportDirectoryTable
    {
    private:
        std::vector<Field> field_vector_;
        std::vector<FieldStr> field_str_vector_;

        std::vector<ExportDirectoryEntry> entry_vector_;

        std::shared_ptr<SectionTable> section_table_ = std::make_shared<SectionTable>();
    public:

        ExportDirectoryTable() = default;
        explicit ExportDirectoryTable(const char* pe_data, std::shared_ptr<SectionTable> section_table, std::shared_ptr<DataDiretoryTable> data_dir_table);

        void SetSectionTable(std::shared_ptr<SectionTable> section_table);

        void SetExportDirectoryTableData(const char* pe_data, DWORD offset);

        void SetExportDirectoryTableEntries(const char* pe_data,DWORD n_functions, DWORD n_names, DWORD address_of_functions, DWORD address_of_names, DWORD address_of_nameordinals);

        Field GetFieldByName(const std::string &name);

        std::string ToString(int pad);
        
    };
}

#endif