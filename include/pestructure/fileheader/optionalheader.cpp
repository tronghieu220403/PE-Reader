#include "optionalheader.h"

namespace pe
{
    OptionalHeader::OptionalHeader(const char* optional_data)
    {
        standard_field_vector_.clear();
        windows_specific_field_vector_.clear();
        SetStandardFieldVector(optional_data);

        if (standard_field_vector_[0].value == 0x10b)
        {
            SetWindowsSpecificFieldVector(optional_data + 28);
            SetDataDiretoryTable(optional_data + 96);
        }
        else if (standard_field_vector_[0].value == 0x20b)
        {
            SetWindowsSpecificFieldVector(optional_data + 24);
            SetDataDiretoryTable(optional_data + 112);
        }
    }

    void OptionalHeader::SetStandardFieldVector(const char *standard_fields_data_)
    {
        int offset = 0;
        standard_field_vector_.clear();

        standard_field_vector_.push_back(
            Field{"Magic", 
            MemoryToUint16(standard_fields_data_ + offset), 
            2}
        );
        offset += 2;

        standard_field_vector_.push_back(
            Field{"MajorLinkerVersion", 
            (unsigned long long)standard_fields_data_[offset], 
            1}
        );
        offset += 1;

        standard_field_vector_.push_back(
            Field{"MinorLinkerVersion", 
            (unsigned long long)standard_fields_data_[offset], 
            1}
        );
        offset += 1;

        standard_field_vector_.push_back(
            Field{"SizeOfCode", 
            MemoryToUint32(standard_fields_data_ + offset), 
            4}
        );
        offset += 4;

        standard_field_vector_.push_back(
            Field{"SizeOfInitializedData", 
            MemoryToUint32(standard_fields_data_ + offset), 
            4}
        );
        offset += 4;
        
        standard_field_vector_.push_back(
            Field{"SizeOfUninitializedData", 
            MemoryToUint32(standard_fields_data_ + offset), 
            4}
        );
        offset += 4;

        standard_field_vector_.push_back(
            Field{"AddressOfEntryPoint", 
            MemoryToUint32(standard_fields_data_ + offset), 
            4}
        );
        offset += 4;

        standard_field_vector_.push_back(
            Field{"BaseOfCode", 
            MemoryToUint32(standard_fields_data_ + offset), 
            4}
        );
        offset += 4;

        if (standard_field_vector_[0].value == 0x10b)
        {
            standard_field_vector_.push_back(
                Field{"BaseOfData", 
                MemoryToUint32(standard_fields_data_ + offset), 
                4}
            );
            offset += 4;
        }
    }

    Field OptionalHeader::GetStandardFieldByName(const std::string &name)
    {
        for (auto& ele: standard_field_vector_)
        {
            if (ele.name == name)
            {
                return ele;
            }
        }
        return Field();
    }

    void OptionalHeader::SetWindowsSpecificFieldVector(const char *windows_specific_fields_data_)
    {
        windows_specific_field_vector_.clear();
        WORD data_size = standard_field_vector_[0].value == 0x10b ? 4 : 8;
        int offset = 0;
        
        windows_specific_field_vector_.push_back(
            Field{"ImageBase", 
            data_size == 4 ? MemoryToUint32(windows_specific_fields_data_ + offset) : MemoryToUint64(windows_specific_fields_data_ + offset), 
            data_size}
        );
        offset += data_size;

        windows_specific_field_vector_.push_back(
            Field{"SectionAlignment", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"FileAlignment", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"MajorOperatingSystemVersion", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"MinorOperatingSystemVersion", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"MajorImageVersion", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"MinorImageVersion", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"MajorSubsystemVersion", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"MinorSubsystemVersion", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"Win32VersionValue", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"SizeOfImage", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"SizeOfHeaders", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"CheckSum", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"Subsystem", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"DllCharacteristics", 
            MemoryToUint16(windows_specific_fields_data_ + offset),
            2}
        );
        offset += 2;

        windows_specific_field_vector_.push_back(
            Field{"SizeOfStackReserve", 
            data_size == 4 ? MemoryToUint32(windows_specific_fields_data_ + offset) : MemoryToUint64(windows_specific_fields_data_ + offset), 
            data_size}
        );
        offset += data_size;

        windows_specific_field_vector_.push_back(
            Field{"SizeOfStackCommit", 
            data_size == 4 ? MemoryToUint32(windows_specific_fields_data_ + offset) : MemoryToUint64(windows_specific_fields_data_ + offset), 
            data_size}
        );
        offset += data_size;

        windows_specific_field_vector_.push_back(
            Field{"SizeOfHeapReserve", 
            data_size == 4 ? MemoryToUint32(windows_specific_fields_data_ + offset) : MemoryToUint64(windows_specific_fields_data_ + offset), 
            data_size}
        );
        offset += data_size;

        windows_specific_field_vector_.push_back(
            Field{"SizeOfHeapCommit", 
            data_size == 4 ? MemoryToUint32(windows_specific_fields_data_ + offset) : MemoryToUint64(windows_specific_fields_data_ + offset), 
            data_size}
        );
        offset += data_size;

        windows_specific_field_vector_.push_back(
            Field{"LoaderFlags", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;

        windows_specific_field_vector_.push_back(
            Field{"NumberOfRvaAndSizes", 
            MemoryToUint32(windows_specific_fields_data_ + offset),
            4}
        );
        offset += 4;
    }

    Field OptionalHeader::GetWindowsSpecificFieldByName(const std::string &name)
    {
        for (auto& ele: windows_specific_field_vector_)
        {
            if (ele.name == name)
            {
                return ele;
            }
        }
        return Field();
    }

    void OptionalHeader::SetDataDiretoryTable(const char* data_directories_data)
    {
        data_dir_table_.SetDataDiretoryTable(data_directories_data);
    }

    DataDiretoryTable OptionalHeader::GetDataDirectoryTable() const
    {
        return data_dir_table_;
    }

    void OptionalHeader::SetDataDirectoryTable(const DataDiretoryTable& data_dir_table)
    {
        data_dir_table_ = data_dir_table;
    }

    DataDiretory OptionalHeader::GetDataDirectoryByName(const std::string &name)
    {
        return data_dir_table_.GetDataDirectoryByName(name);
    }
}
