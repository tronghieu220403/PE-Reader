#include "exportdirectorytable.h"

namespace pe
{
    ExportDirectoryTable::ExportDirectoryTable(const char *pe_data, std::shared_ptr<SectionTable> section_table, std::shared_ptr<DataDiretoryTable> data_dir_table):
    section_table_(section_table)
    {
        DataDiretory import = data_dir_table->GetDataDirectoryByName("Export Table");
        DWORD rva = import.GetDataRelativeVirtualAddress();
        DWORD sz = import.GetDataSize();

        SectionHeader section_header = section_table->FindSectionByRva(rva, sz);
        if (section_header.GetFieldByName("ImageBase").value == 0)
        {
            return;
        }
        DWORD raw_offset = rva - static_cast<DWORD>(section_header.GetFieldByName("VirtualAddress").value) + static_cast<DWORD>(section_header.GetFieldByName("PointerToRawData").value);

        SetExportDirectoryTableData(pe_data, raw_offset);
    }

    void ExportDirectoryTable::SetSectionTable(std::shared_ptr<SectionTable> section_table)
    {
        section_table_ = section_table;
    }

    void ExportDirectoryTable::SetExportDirectoryTableData(const char *pe_data, DWORD offset)
    {
        DWORD name_rva;
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

        name_rva = MemoryToUint32(pe_data + offset);
        field_vector_.push_back(Field{
            "Name RVA",
            name_rva,
            4
        });

        field_str_vector_.push_back(
            FieldStr{"Dll Name", MemoryToString(pe_data + section_table_->ConvertRvaToRawAddress(name_rva))}
        );

        offset += 4;

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

        SetExportDirectoryTableEntries(pe_data, n_functions, n_names, address_of_functions, address_of_names, address_of_nameordinals);
    }

    void ExportDirectoryTable::SetExportDirectoryTableEntries(const char *pe_data, DWORD n_functions, DWORD n_names, DWORD address_of_functions, DWORD address_of_names, DWORD address_of_nameordinals)
    {
        DWORD raw_address_of_functions = section_table_->ConvertRvaToRawAddress(address_of_functions);
        DWORD raw_address_of_names = section_table_->ConvertRvaToRawAddress(address_of_names);
        DWORD raw_address_of_nameordinals = section_table_->ConvertRvaToRawAddress(address_of_nameordinals);
        DWORD ordinal_base = static_cast<DWORD>(GetFieldByName("Ordinal Base").value);

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
                entry_vector_.push_back(
                    ExportDirectoryEntry(pe_data, func_rva, 
                        section_table_->ConvertRvaToRawAddress(
                        MemoryToUint32(pe_data + raw_address_of_names + ordinal * 4)
                    ),
                i + ordinal_base));
            }
            else
            {
                entry_vector_.push_back(
                    ExportDirectoryEntry(nullptr, func_rva, 
                    DWORD(-1), 
                    i + ordinal_base)
                );
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

    std::string ExportDirectoryTable::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        s.append(pad_str + "Export Directory Table:\n\n");
        for (auto& field: field_str_vector_)
        {
            s.append(pad_str + field.name + ": " + field.value + "\n");
        }
        for (auto& field: field_vector_)
        {
            s.append(pad_str + field.name + ": " + ToHex(field.value) + "\n");
        }
        s.append(pad_str + "Export Directory Entries:\n\n");
        for (auto& entry: entry_vector_)
        {
            s.append(entry.ToString(pad+1));
        }
        s.append("\n");
        return s;
    }
}
