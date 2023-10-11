#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYENTRY_H_

#include "ulti/everything.h"

namespace pe
{
    class ImportDirectoryEntry
    {
    private:
        std::vector<Field> field_vector_;
    public:

        ImportDirectoryEntry() = default;
        explicit ImportDirectoryEntry(const char* pe_data, int offset);

        void SetImportDirectoryEntry(const char* pe_data, int offset);

    };
}

#endif