#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYTABLE_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYTABLE_H_

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
        WORD version_;
        SectionTable section_table_;
    public:

        ImportDirectoryTable() = default;
        explicit ImportDirectoryTable(const char* pe_data, SectionTable& section_table, DataDiretoryTable& data_dir_table, WORD version_);

        void SetSectionTable(const SectionTable& section_table);
        void SetVersion(WORD version);

        void SetImportDirectoryTableData(const char* pe_data, int offset);

        ImportDirectoryEntry GetImportDirectoryEntryByDllName(const std::string& name) const;

    };
}

#endif