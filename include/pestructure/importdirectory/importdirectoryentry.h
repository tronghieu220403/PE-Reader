#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_IMPORTDIRECTORYENTRY_H_

#include "ulti/everything.h"

namespace pe
{
    class ImportDirectoryEntry
    {
    private:
        Field signature_;
    public:

        ImportDirectoryEntry() = default;
        explicit ImportDirectoryEntry(const char* imp_dir_entry_data);

        void ImportDirectoryEntry(const char* imp_dir_entry_data);

    };
}

#endif