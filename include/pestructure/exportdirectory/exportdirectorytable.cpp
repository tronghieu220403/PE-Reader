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

    }

    void ExportDirectoryTable::SetExportDirectoryTableData(const char *pe_data, int offset)
    {
        field_vector_.clear();

        field_vector_.push_back(Field{
            "Export Flags",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;

        field_vector_.push_back(Field{
            "Time Stamp",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;

        field_vector_.push_back(Field{
            "Major Version",
            MemoryToUint64(pe_data + offset),
            2
        });
        offset += 2;

        field_vector_.push_back(Field{
            "Minor Version",
            MemoryToUint64(pe_data + offset),
            2
        });
        offset += 2;

        field_vector_.push_back(Field{
            "Ordinal Base",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;
        
        field_vector_.push_back(Field{
            "Address Table Entries",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;
        
        field_vector_.push_back(Field{
            "Number of Name Pointers",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;
        
        field_vector_.push_back(Field{
            "Export Address Table RVA",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;

        field_vector_.push_back(Field{
            "Name Pointer RVA",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;

        field_vector_.push_back(Field{
            "Ordinal Table RVA",
            MemoryToUint64(pe_data + offset),
            4
        });
        offset += 4;
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
