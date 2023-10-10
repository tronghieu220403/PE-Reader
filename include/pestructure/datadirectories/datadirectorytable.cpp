#include "datadirectorytable.h"

namespace pe
{

    DataDiretoryTable::DataDiretoryTable(const char *data_directories_data)
    {
        SetDataDiretoryTable(data_directories_data);
    }

    void DataDiretoryTable::SetDataDiretoryTable(const char *data_directories_data)
    {
        int offset = -4;
        entry_.clear();

        entry_.push_back(DataDiretory(
            "Export Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Import Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Resource Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Exception Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Certificate Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Base Relocation Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Debug",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Architecture",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Global Ptr",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "TLS Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Load Config Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Bound Import Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Import Address Table",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Delay-Load Import Tables",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "CLR Runtime Header",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

        entry_.push_back(DataDiretory(
            "Reserved",
            MemoryToUint32(&(data_directories_data[offset += 4])), 
            MemoryToUint32(&(data_directories_data[offset += 4])))
        );

    }
    
    DataDiretory DataDiretoryTable::GetDataDirectoryByName(const std::string &name)
    {
        for (int i = 0; i < entry_.size(); i++)
        {
            if (entry_[i].GetName() == name)
            {
                return entry_[i];
            }
        }
        return DataDiretory();
    }
}
