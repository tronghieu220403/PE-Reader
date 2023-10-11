#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTLOOKUPTABLE_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTLOOKUPTABLE_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/importlookupentry.h"

namespace pe
{
    class ImportLookupTable
    {
    private:
        std::vector<ImportLookupEntry> import_lookup_entry_;
        SectionTable section_table_;
        WORD version_;
    public:

        ImportLookupTable() = default;
        explicit ImportLookupTable(WORD version);
        explicit ImportLookupTable(const char* pe_data, int offset, SectionTable& section_header, WORD version);

        void SetSectionTable(SectionTable section_table);
        void SetVersion(WORD version);

        void SetImportLookupTableData(const char* pe_data, int offset);

    };
}

#endif