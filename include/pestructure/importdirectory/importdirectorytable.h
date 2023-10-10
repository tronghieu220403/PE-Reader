#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORY_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/importdirectoryentry.h"
#include "pestructure/fileheader/optionalheader.h"
#include "pestructure/sectionheaders/sectiontable.h"

namespace pe
{
    class ImportDirectoryTable
    {
    private:
        std::vector<ImportDirectoryEntry> entry_;
    public:

        ImportDirectoryTable() = default;
        explicit ImportDirectoryTable(SectionTable section_table, DataDiretoryTable data_dir_table);
        explicit ImportDirectoryTable(const char* imp_dir_table_data);

        void SetImportDirectoryTableData(const char* imp_dir_table_data);

        void GetImportDirectoryEntryByDllName(const std::string& name) const;

    };
}

#endif