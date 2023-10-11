#include "importdirectoryentry.h"

namespace pe
{
    ImportDirectoryEntry::ImportDirectoryEntry(const char *pe_data, int offset)
    {
        SetImportDirectoryEntry(pe_data, offset);
    }

    void ImportDirectoryEntry::SetImportDirectoryEntry(const char *pe_data, int offset)
    {
        field_vector_.clear();
        offset -= 4;

        field_vector_.push_back(
            Field{"Import Lookup Table RVA", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Time/Date Stamp", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Forwarder Chain", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Name RVA", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );

        field_vector_.push_back(
            Field{"Import Address Table RVA", 
            MemoryToUint32(pe_data + (offset += 4)), 
            4}
        );
    }
}
