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
        WORD version_ = 0;
        std::shared_ptr<SectionTable> section_table_;
    public:

        ImportDirectoryTable() = default;
        explicit ImportDirectoryTable(const char* pe_data, std::shared_ptr<SectionTable> section_table, DataDiretoryTable& data_dir_table, WORD version_);

        void SetSectionTable(const std::shared_ptr<SectionTable> section_table);
        void SetVersion(WORD version);

        void SetImportDirectoryTableData(const char* pe_data, DWORD offset);

        std::string ToString(int pad);

    };
}

#endif