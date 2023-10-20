#include "exportaddressentry.h"

namespace pe
{

    ExportDirectoryEntry::ExportDirectoryEntry(const char *pe_data, DWORD export_address_rva, DWORD name_raw_offset, DWORD biased_ordinal)
    {
        SetExportDirectoryEntryData(pe_data, export_address_rva, name_raw_offset, biased_ordinal);
    }
    
    void ExportDirectoryEntry::SetExportDirectoryEntryData(const char *pe_data, DWORD export_address_rva, DWORD name_raw_offset, DWORD biased_ordinal)
    {
        field_vector_.push_back(
            Field{"Export Address RVA", 
            export_address_rva, 
            4
        });
        field_vector_.push_back(
            Field{"Ordinal", 
            biased_ordinal, 
            4
        });

        if (pe_data != nullptr && name_raw_offset != DWORD(-1))
        {
            field_str_vector_.push_back(
                FieldStr{"Export Name",
                MemoryToString(pe_data + name_raw_offset)
            });
        }
    }

    Field ExportDirectoryEntry::GetFieldByName(const std::string &name)
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

    FieldStr ExportDirectoryEntry::GetFieldStrByName(const std::string &name)
    {
        for (auto& ele: field_str_vector_)
        {
            if (ele.name == name)
            {
                return ele;
            }
        }
        return FieldStr();
    }

    std::string ExportDirectoryEntry::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        s.append(pad_str + "Export Directory Entry:\n\n");
        for (auto& field: field_vector_)
        {
            s.append(pad_str + field.name + ": " + ToHex(field.value) + "\n");
        }
        for (auto& field: field_str_vector_)
        {
            s.append(pad_str + field.name + ": " + field.value + "\n");
        }
        return s;
    }

}
