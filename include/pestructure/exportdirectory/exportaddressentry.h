#ifndef PEREADER_PEHEADER_EXPORTDIRECTORYENTRY_EXPORTDIRECTORYENTRY_H_
#define PEREADER_PEHEADER_EXPORTDIRECTORYENTRY_EXPORTDIRECTORYENTRY_H_

#include "ulti/everything.h"
#include "pestructure/sectionheaders/sectiontable.h"

namespace pe
{
    class ExportDirectoryEntry
    {
    private:
        std::vector<Field> field_vector_;
        std::vector<FieldStr> field_str_vector_;
    public:

        ExportDirectoryEntry() = default;
        explicit ExportDirectoryEntry(const char* pe_data, 
            DWORD export_address_rva, 
            DWORD name_raw_offset,
            DWORD biased_ordinal
            );

        void SetExportDirectoryEntryData(const char* pe_data, DWORD export_address_rva, DWORD name_raw_offset, DWORD biased_ordinal);

        Field GetFieldByName(const std::string &name);
        FieldStr GetFieldStrByName(const std::string &name);

        std::string ToString(int pad);
    };
}

#endif