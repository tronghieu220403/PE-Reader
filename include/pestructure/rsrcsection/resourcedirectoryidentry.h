#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYIDENTRY_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYIDENTRY_H_

#include "ulti/everything.h"
#include "pestructure/rsrcsection/resourcedirectorytable.h"
#include "pestructure/rsrcsection/resourcedataentry.h"

namespace pe
{
    class ResourceDirectoryIdEntry
    {
    private:
        std::vector<Field> field_vector_;
        ResourceDirectoryTable table_;
        ResourceDataEntry data_;
    public:
        ResourceDirectoryIdEntry() = default;
        ResourceDirectoryIdEntry(const char* pe_data, DWORD offset);
        
        void SetResourceDirectoryIdEntry(const char* pe_data, DWORD offset);

        Field GetFieldByName(const std::string& name);
    };
}

#endif