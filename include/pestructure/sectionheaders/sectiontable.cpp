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

    SectionHeader SectionTable::FindSectionByRva(DWORD addr, int size)
    {
        for (auto& section: section_header_)
        {
            DWORD rva = section.GetFieldByName("VirtualAddress").value;
            DWORD vs = section.GetFieldByName("VirtualSize").value;
            if (rva <= addr && addr + size <= rva + vs)
            {
                return section;
            }
        }
        return SectionHeader();
    }

    SectionHeader SectionTable::FindSectionByRawAddress(DWORD addr, int size)
    {
        for (auto& section: section_header_)
        {
            DWORD ra = section.GetFieldByName("PointerToRawData").value;
            DWORD rs = section.GetFieldByName("SizeOfRawData").value;
            if (ra <= addr && addr + size <= ra + rs)
            {
                return section;
            }
        }
        return SectionHeader();
    }

    DWORD SectionTable::ConvertRvaToRawAddress(DWORD addr)
    {
        for (auto& section: section_header_)
        {
            DWORD ra = section.GetFieldByName("PointerToRawData").value;
            DWORD rva = section.GetFieldByName("VirtualAddress").value;
            DWORD vs = section.GetFieldByName("VirtualSize").value;

            if (rva <= addr && addr <= rva + vs)
            {
                return addr - rva + ra;
            }
        }

        return -1;
    }
}