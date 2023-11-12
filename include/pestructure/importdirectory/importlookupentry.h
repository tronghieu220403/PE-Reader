#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTLOOKUPENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTLOOKUPENTRY_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/hintnameentry.h"
#include "pestructure/sectionheaders/sectiontable.h"

namespace pe
{
    class ImportLookupEntry
    {
    private:
        std::vector<Field> field_vector_;
        HintNameEntry entry_;
        WORD version_;
        std::shared_ptr<SectionTable> section_table_ = std::make_shared<SectionTable>();
    public:

        ImportLookupEntry() = default;
        explicit ImportLookupEntry(WORD version);
        explicit ImportLookupEntry(const char* pe_data, int offset, std::shared_ptr<SectionTable> section_header, WORD version);

        void SetVersion(WORD version);
        void SetSectionTable(const std::shared_ptr<SectionTable> section_table);

        void SetImportLookupEntryData(const char* pe_data, int offset);

        bool IsOrdinalFlag() const;
        bool IsNameFlag() const;

        Field GetFieldByName(const std::string& name);

        std::string ToString(int pad);
        
    };
}

#endif