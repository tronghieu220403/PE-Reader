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
        int n_sections_;

    public:
        SectionTable() = default;
        SectionTable(const char* section_headers_data, int n_sections);
        
        void SetSectionTable(const char *section_headers_data);

        int GetNumberOfSections() const;
        void SetNumberOfSections(const int n_sections);

        SectionHeader FindSectionByRva(DWORD addr, int size);
        SectionHeader FindSectionByRawAddress(DWORD addr, int size);

        DWORD ConvertRvaToRawAddress(DWORD addr);

        std::string ToString(int pad);
    };
}

#endif