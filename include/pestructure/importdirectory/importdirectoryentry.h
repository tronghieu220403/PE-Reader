#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYENTRY_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/importlookuptable.h"

namespace pe
{
    class ImportDirectoryEntry
    {
    private:
        std::vector<FieldStr> field_str_vector_;
        std::vector<Field> field_vector_;
        ImportLookupTable import_lookup_table_;
        std::shared_ptr<SectionTable> section_table_;
        WORD version_;
    public:

        ImportDirectoryEntry() = default;
        explicit ImportDirectoryEntry(const char* pe_data, int offset, std::shared_ptr<SectionTable> section_table, WORD version);

        void SetSectionTable(std::shared_ptr<SectionTable> section_table);
        void SetVersion(WORD version);

        void SetImportDirectoryEntry(const char* pe_data, int offset);

        std::string ToString(int pad);

    };
}

#endif