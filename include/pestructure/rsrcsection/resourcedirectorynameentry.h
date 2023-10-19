#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYNAMEENTRY_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYNAMEENTRY_H_

#include "ulti/everything.h"
#include "pestructure/rsrcsection/resourcedirectorytable.h"
#include "pestructure/rsrcsection/resourcedataentry.h"

namespace pe
{
    class ResourceDirectoryNameEntry
    {
    private:
        std::vector<Field> field_vector_;
        ResourceDirectoryTable table_;
        ResourceDataEntry data_;
    public:
        ResourceDirectoryNameEntry() = default;
        ResourceDirectoryNameEntry(const char* pe_data, DWORD offset);
        
        void SetResourceDirectoryNameEntry(const char* pe_data, DWORD offset);

        Field GetFieldByName(const std::string& name);
    };
}

#endif