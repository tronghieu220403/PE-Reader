#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYTABLE_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYTABLE_H_

#include "ulti/everything.h"
#include "pestructure/rsrcsection/resourcedirectoryidentry.h"
#include "pestructure/rsrcsection/resourcedirectorynameentry.h"

namespace pe
{
    class ResourceDirectoryTable
    {
    private:
        std::vector<Field> field_vector_;
        std::vector<ResourceDirectoryIdEntry> id_entry_vector;
        std::vector<ResourceDirectoryNameEntry> name_entry_vector;

        DWORD base_offset_ = DWORD(-1);
    public:
        ResourceDirectoryTable() = default;
        ResourceDirectoryTable(const char* pe_data, DWORD offset, DWORD base_offset_);
        
        void SetResourceDirectoryTable(const char* pe_data, DWORD offset);

        Field GetFieldByName(const std::string& name);
    };
}

#endif