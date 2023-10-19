#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYNAMEENTRY_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYNAMEENTRY_H_

#include "ulti/everything.h"
#include "pestructure/rsrcsection/resourcedirectorytable.h"
#include "pestructure/rsrcsection/resourcedataentry.h"
#include "pestructure/rsrcsection/resourcedirectorystring.h"

namespace pe
{
    class ResourceDirectoryNameEntry
    {
    private:
        std::vector<Field> field_vector_;
        ResourceDirectoryString name_;
        DWORD raw_base_offset_ = DWORD(-1);

        ResourceDirectoryTable table_;
        ResourceDataEntry data_;

    public:
        ResourceDirectoryNameEntry() = default;
        ResourceDirectoryNameEntry(const char* pe_data, DWORD offset, DWORD raw_base_offset);
        
        void SetResourceDirectoryNameEntry(const char* pe_data, DWORD offset);

        Field GetFieldByName(const std::string& name);
    };
}

#endif