#ifndef PEREADER_DISPLAY_SECTIONHEADER_H_
#define PEREADER_DISPLAY_SECTIONHEADER_H_

#include "ulti/everything.h"

namespace pe
{
    class SectionHeader
    {
    private:
        std::vector<Field> section_header_;
    public:
        SectionHeader() = default;
        SectionHeader(const char* section_header_data);
        
        void SetUpSectionHeader(const char *section_header_data);

        Field GetFieldByName(const std::string& name);
    };
}

#endif