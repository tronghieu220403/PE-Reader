#include "exportdirectorytable.h"

namespace pe
{
    ExportDirectoryTable::ExportDirectoryTable(const char *pe_data, int offset, std::shared_ptr<SectionTable> section_table):
    section_table_(section_table)
    {
        SetExportDirectoryTableData(pe_data, offset);
    }

    void ExportDirectoryTable::SetSectionTable(std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    void ExportDirectoryTable::SetExportDirectoryTableData(const char *pe_data, int offset)
    {
        unsigned int n_functions;
        unsigned int n_names;
        unsigned int address_of_functions;
        unsigned int address_of_names;
        unsigned int address_of_nameordinals;

        field_vector_.clear();

        field_vector_.push_back(Field{
            "Export Flags",
            MemoryToUint32(pe_data + offset),
            4
        });
        offset += 4;

        field_vector_.push_back(Field{
            "Time Stamp",
            MemoryToUint32(pe_data + offset),
            4
        });
        offset += 4;

        field_vector_.push_back(Field{
            "Major Version",
            MemoryToUint16(pe_data + offset),
            2
        });
        offset += 2;

        field_vector_.push_back(Field{
            "Minor Version",
            MemoryToUint16(pe_data + offset),
            2
        });
        offset += 2;

        field_vector_.push_back(Field{
            "Ordinal Base",
            MemoryToUint32(pe_data + offset),
            4
        });
        offset += 4;
        
        n_functions = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(Field{
            "Address Table Entries",
            n_functions,
            4
        });
        offset += 4;
        
        n_names = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(Field{
            "Number of Name Pointers",
            n_names,
            4
        });
        offset += 4;
        
        address_of_functions = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(Field{
            "Export Address Table RVA",
            address_of_functions,
            4
        });
        offset += 4;

        address_of_names = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(Field{
            "Name Pointer RVA",
            address_of_names,
            4
        });
        offset += 4;

        address_of_nameordinals = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(Field{
            "Ordinal Table RVA",
            address_of_nameordinals,
            4
        });
        offset += 4;


    }

    void ExportDirectoryTable::SetExportDirectoryTableEntries(const char *pe_data, int n_functions, int n_names, int address_of_functions, int address_of_names, int address_of_nameordinals)
    {
        // For each function i-th (i from 0 to n_names - 1), its address is Export_Address_Table_RVA[i]
        // Secondly check if its ordinal i appears in Ordinal_Table_RVA
        // If yes, i == Ordinal_Table_RVA[j], then the name of that function will be Name_Pointer_RVA[j]
    }

    Field ExportDirectoryTable::GetFieldByName(const std::string &name)
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
}
