#include "optionalheader.h"

namespace pe
{
    OptionalHeader::OptionalHeader(const char* optional_data):
        data_directory_vector_(std::make_shared<std::vector<DataDiretory>>())
    {
        SetUpStandardFieldVector(optional_data);

        if (standard_field_vector_[0].value == 0x10b)
        {
            SetUpWindowsSpecificFieldVector(optional_data + 28);
            SetUpDataDiretoryVector(optional_data + 96);
        }
        else if (standard_field_vector_[0].value == 0x20b)
        {
            SetUpWindowsSpecificFieldVector(optional_data + 24);
            SetUpDataDiretoryVector(optional_data + 112);
        }
    }

    void OptionalHeader::SetUpStandardFieldVector(const char *standard_fields_data_)
    {
        int offset = 0;

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

    void OptionalHeader::SetUpWindowsSpecificFieldVector(const char *windows_specific_fields_data_)
    {
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

    void OptionalHeader::SetUpDataDiretoryVector(const char* data_directories_data)
    {
        int offset = -4;
        data_directory_vector_->push_back(DataDiretory(
            "Export Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Import Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Resource Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Exception Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Certificate Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Base Relocation Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Debug",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Architecture",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Global Ptr",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "TLS Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Load Config Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Bound Import Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Import Address Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Delay-Load Import Tables",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "CLR Runtime Header",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Reserved",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );
    }

    std::shared_ptr<std::vector<DataDiretory>> OptionalHeader::GetDataDirectoryVector() const
    {
        return data_directory_vector_;
    }

    void OptionalHeader::SetDataDirectoryVector(const std::shared_ptr<std::vector<DataDiretory>>& data_directory_vector)
    {
        data_directory_vector_ = data_directory_vector;
    }

    void OptionalHeader::AddElementToDataDirectoryVector(const std::string &name, const IMAGE_DATA_DIRECTORY &image_data_directory)
    {
        data_directory_vector_->push_back(DataDiretory(name, image_data_directory));
    }

    void OptionalHeader::AddElementToDataDirectoryVector(const DataDiretory &data)
    {
        data_directory_vector_->push_back(data);
    }

    DataDiretory OptionalHeader::GetDataDirectoryByName(const std::string &name)
    {
        std::vector<DataDiretory>& v = *data_directory_vector_.get();
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].GetName() == name)
            {
                return v[i];
            }
        }
        return DataDiretory();
    }
}
