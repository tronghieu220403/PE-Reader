#include "sectiontable.h"

namespace pe
{

    SectionTable::SectionTable(const char *section_headers_data, int n_sections):
        n_sections_(n_sections)
    {
        SetSectionTable(section_headers_data);
    }

    void SectionTable::SetSectionTable(const char *section_headers_data)
    {
        section_header_.clear();
        for (int i = 0; i < n_sections_ ; i++)
        {
            section_header_.push_back(SectionHeader(section_headers_data));
            section_headers_data+=40;
        }
    }

    int SectionTable::GetNumberOfSections() const
    {
        return n_sections_;
    }

    void SectionTable::SetNumberOfSections(const int n_sections)
    {
        n_sections_ = n_sections;
    }

    SectionHeader SectionTable::FindSectionByVirtualAddress(DWORD addr)
    {
        for (auto& section: section_header_)
        {
            DWORD va = section.GetFieldByName("VirtualAddress").value;
            DWORD vs = section.GetFieldByName("VirtualSize").value;
            if (va <= addr && addr <= va + vs)
            {
                return section;
            }
        }
        return SectionHeader();
    }

    SectionHeader SectionTable::FindSectionByRawAddress(DWORD addr)
    {
        for (auto& section: section_header_)
        {
            DWORD ra = section.GetFieldByName("PointerToRawData").value;
            DWORD rs = section.GetFieldByName("SizeOfRawData").value;
            if (ra <= addr && addr <= ra + rs)
            {
                return section;
            }
        }
        return SectionHeader();
    }
}