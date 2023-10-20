#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYTABLE_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDIRECTORYTABLE_H_

#include "ulti/everything.h"
#include "pestructure/rsrcsection/resourcedirectoryidentry.h"
#include "pestructure/rsrcsection/resourcedirectorynameentry.h"
#include "pestructure/sectionheaders/sectiontable.h"
#include "pestructure/fileheader/optionalheader.h"

namespace pe
{
    class ResourceDirectoryIdEntry;
    class ResourceDirectoryNameEntry;

    class ResourceDirectoryTable
    {
    private:

        std::vector<Field> field_vector_;
        std::vector<ResourceDirectoryIdEntry *> id_entry_vector_;
        std::vector<ResourceDirectoryNameEntry *> name_entry_vector_;

        DWORD raw_base_offset_ = DWORD(-1);
    public:

        ResourceDirectoryTable() = default;
        ResourceDirectoryTable(const char* pe_data, std::shared_ptr<SectionTable> section_table, std::shared_ptr<DataDiretoryTable> data_dir_table);

        ResourceDirectoryTable(const char* pe_data, DWORD offset, DWORD raw_base_offset_);
        
        void SetResourceDirectoryTable(const char* pe_data, DWORD offset);

        Field GetFieldByName(const std::string& name);

        void Clean();

        ~ResourceDirectoryTable();

        std::string ToString(int pad);
    };
}

#endif