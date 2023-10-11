#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTLOOKUPENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTLOOKUPENTRY_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/hintnametable.h"
#include "pestructure/sectionheaders/sectiontable.h"

namespace pe
{
    class ImportLookupEntry
    {
    private:
        std::vector<Field> field_vector_;
        HintNameTable entry_;
        WORD version_;
        SectionTable section_table_;
    public:

        ImportLookupEntry() = default;
        explicit ImportLookupEntry(WORD version);
        explicit ImportLookupEntry(const char* pe_data, int offset, SectionTable& section_header, WORD version);

        void SetVersion(WORD version);
        void SetSectionTable(SectionTable section_table);

        void SetImportLookupEntryData(const char* pe_data, int offset);

        bool IsOrdinalFlag() const;
        bool IsNameFlag() const;

        Field GetFieldByName(const std::string& name);

    };
}

#endif