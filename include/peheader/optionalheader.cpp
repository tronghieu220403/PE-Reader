#include "optionalheader.h"

namespace pe
{
    OptionalHeader::OptionalHeader(std::vector<char> pe_data, int begin_offset):
        data_directory_vector_(std::make_shared<std::vector<DataDiretory>>())
    {
        int offset = begin_offset - 4;
        data_directory_vector_->push_back(DataDiretory(
            "Export Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Import Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Resource Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Exception Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Certificate Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Base Relocation Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Debug",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Architecture",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Global Ptr",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "TLS Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Load Config Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Bound Import Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Import Address Table",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Delay-Load Import Tables",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "CLR Runtime Header",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
        );

        data_directory_vector_->push_back(DataDiretory(
            "Reserved",
            MemoryToUint32(&(pe_data[offset += 4])), 
            MemoryToUint32(&(pe_data[offset += 4])))
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

    void OptionalHeader::AddElementToDataDirectories(const std::string &name, const IMAGE_DATA_DIRECTORY &image_data_directory)
    {
        data_directory_vector_->push_back(DataDiretory(name, image_data_directory));
    }

    void OptionalHeader::AddElementToDataDirectories(const DataDiretory &data)
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
