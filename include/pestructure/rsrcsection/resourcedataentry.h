#ifndef PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDATAENTRY_H_
#define PEREADER_PEHEADER_PESTRUCTURE_RSRCSECTION_RESOURCEDATAENTRY_H_

#include "ulti/everything.h"

namespace pe
{
    class ResourceDataEntry
    {
    private:
        std::vector<Field> field_vector_;
    public:
        ResourceDataEntry() = default;
        ResourceDataEntry(const char* pe_data, DWORD offset);
        
        void SetResourceDataEntry(const char* pe_data, DWORD offset);

        Field GetFieldByName(const std::string& name);
    };
}

#endif