#include "cofffileheader.h"

namespace pe
{
    CoffFileHeader::CoffFileHeader(const char *file_header_data)
    {
        SetUpCoffFileHeaderVector(file_header_data);
    }
    
    void CoffFileHeader::SetUpCoffFileHeaderVector(const char *file_header_data)
    {
        int offset = 0;
        file_header_vector_.clear();
        
        file_header_vector_.push_back(
            Field{"Machine", 
            MemoryToUint16(file_header_data + offset), 
            2}
        );
        offset += 2;

        file_header_vector_.push_back(
            Field{"NumberOfSections", 
            MemoryToUint16(file_header_data + offset), 
            2}
        );
        offset += 2;

        file_header_vector_.push_back(
            Field{"TimeDateStamp", 
            MemoryToUint32(file_header_data + offset), 
            4}
        );
        offset += 4;

        file_header_vector_.push_back(
            Field{"TimeDateStamp", 
            MemoryToUint16(file_header_data + offset), 
            4}
        );
        offset += 4;

        file_header_vector_.push_back(
            Field{"PointerToSymbolTable", 
            MemoryToUint32(file_header_data + offset), 
            4}
        );
        offset += 4;

        file_header_vector_.push_back(
            Field{"NumberOfSymbols", 
            MemoryToUint32(file_header_data + offset), 
            4}
        );
        offset += 4;

        file_header_vector_.push_back(
            Field{"SizeOfOptionalHeader", 
            MemoryToUint16(file_header_data + offset), 
            2}
        );
        offset += 2;

        file_header_vector_.push_back(
            Field{"Characteristics", 
            MemoryToUint16(file_header_data + offset), 
            2}
        );
        offset += 2;

    }

    Field CoffFileHeader::GetFieldByName(const std::string &name)
    {
        for (auto& ele: file_header_vector_)
        {
            if (ele.name == name)
            {
                return ele;
            }
        }
        return Field();
    }
}
