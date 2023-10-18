#include "exportdirectorytable.h"

namespace pe
{
    ExportDirectoryTable::ExportDirectoryTable(const char *pe_data, DWORD offset, std::shared_ptr<SectionTable> section_table):
    section_table_(section_table)
    {
        SetExportDirectoryTableData(pe_data, offset);
    }

    void ExportDirectoryTable::SetSectionTable(std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    void ExportDirectoryTable::SetExportDirectoryTableData(const char *pe_data, DWORD offset)
    {
        DWORD n_functions;
        DWORD n_names;
        DWORD address_of_functions;
        DWORD address_of_names;
        DWORD address_of_nameordinals;

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
            "Number of Name Pointer",
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

    void ExportDirectoryTable::SetExportDirectoryTableEntries(const char *pe_data, DWORD n_functions, DWORD n_names, DWORD address_of_functions, DWORD address_of_names, DWORD address_of_nameordinals)
    {
        // For each function i-th (i from 0 to n_functions - 1), its address is Export_Address_Table_RVA[i]
        // Secondly check if its ordinal i appears in Ordinal_Table_RVA
        // If yes, i == Ordinal_Table_RVA[j], then the name of that function will be Name_PoDWORDer_RVA[j]
        DWORD raw_address_of_functions = section_table_->ConvertRvaToRawAddress(address_of_functions);
        DWORD raw_address_of_names = section_table_->ConvertRvaToRawAddress(address_of_names);
        DWORD raw_address_of_nameordinals = section_table_->ConvertRvaToRawAddress(address_of_nameordinals);
        DWORD ordinal_base = GetFieldByName("Ordinal Base").value;

        for (DWORD i = 0; i < n_functions; i++)
        {
            DWORD func_rva = MemoryToUint32(pe_data + raw_address_of_functions + i * 4);

            DWORD ordinal = DWORD(-1);
            for (DWORD j = 0; j < n_names; j++)
            {
                WORD ord = MemoryToUint16(pe_data + raw_address_of_nameordinals + j *2);
                if ((DWORD)ord == i)
                {
                    ordinal = j;
                    break;
                }
            }

            if (ordinal != DWORD(-1))
            {
                ExportDirectoryEntry(pe_data, func_rva, 
                section_table_->ConvertRvaToRawAddress(
                    MemoryToUint32(pe_data + raw_address_of_names + ordinal * 4)
                    ),
                i + ordinal_base);
            }
            else
            {
                ExportDirectoryEntry(nullptr, func_rva, 
                DWORD(-1), 
                i + ordinal_base);
            }
        }
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
