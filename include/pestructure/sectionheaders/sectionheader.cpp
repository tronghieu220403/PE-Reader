#include "sectionheader.h"

namespace pe
{
    SectionHeader::SectionHeader(const char *section_header_data)
    {
        SetUpSectionHeader(section_header_data);
    }

    void SectionHeader::SetUpSectionHeader(const char *section_header_data)
    {
        int offset = 0;
        field_vector_.clear();

        field_vector_.push_back(
            Field{"ImageBase", 
            MemoryToUint64(section_header_data + offset), 
            8}
        );
        offset += 8;

        field_vector_.push_back(
            Field{"VirtualSize", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"VirtualAddress", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"SizeOfRawData", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"PointerToRawData", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"PointerToRelocations", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"PointerToLinenumbers", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;

        field_vector_.push_back(
            Field{"NumberOfRelocations", 
            MemoryToUint16(section_header_data + offset), 
            2}
        );
        offset += 2;

        field_vector_.push_back(
            Field{"NumberOfLinenumbers", 
            MemoryToUint16(section_header_data + offset), 
            2}
        );
        offset += 2;

        field_vector_.push_back(
            Field{"Characteristics", 
            MemoryToUint32(section_header_data + offset), 
            4}
        );
        offset += 4;
    }
    
    Field SectionHeader::GetFieldByName(const std::string &name)
    {
        for (auto& ele: field_vector_)
        {
            if (ele.name == name)
            {
                return ele;
            }
        }
        return Field();
    }

    std::string SectionHeader::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        for (auto& ele: field_vector_)
        {
            if (ele.name == "ImageBase")
            {
                unsigned long long value = ele.value;
                char t[8];
                memcpy(&t, &value, 8);
                s.append(pad_str + ele.name + ": " + t + "\n"); 
            }
            else
            {
                s.append(pad_str + ele.name + ": " + ToHex(ele.value) + "\n"); 
            }
        }

        return s;

    }
}
