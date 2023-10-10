#ifndef PEREADER_PEHEADER_SECTIONHEADERS_SECTIONTABLE_H_
#define PEREADER_PEHEADER_SECTIONHEADERS_SECTIONTABLE_H_

#include "ulti/everything.h"
#include "pestructure/sectionheaders/sectionheader.h"

namespace pe
{
    class SectionTable
    {
    private:
        std::vector<SectionHeader> section_header_;
    public:
        SectionTable() = default;
        SectionTable(const char* section_headers_data);
        
        void SetUpSectionTable(const char *section_headers_data);

    };
}

#endif