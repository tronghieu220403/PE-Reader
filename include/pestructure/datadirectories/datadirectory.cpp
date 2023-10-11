#include "datadirectory.h"

namespace pe
{
    DataDiretory::DataDiretory(const std::string &name, const IMAGE_DATA_DIRECTORY &data)
    {
        SetName(name);
        SetData(data);
    }

    std::string DataDiretory::GetName() const {
        return name_;
    }

    DataDiretory::DataDiretory(const std::string& name, const DWORD virtual_address, const DWORD size)
    {
        SetName(name);
        SetDataVirtualAddress(virtual_address);
        SetDataSize(size);
    }

    void DataDiretory::SetName(const std::string& name) {
        name_ = name;
    }

    IMAGE_DATA_DIRECTORY DataDiretory::GetData() const {
        return data_;
    }

    void DataDiretory::SetData(const IMAGE_DATA_DIRECTORY& data) {
        data_ = data;
    }

    DWORD DataDiretory::GetDataSize() const
    {
        return data_.Size;
    }
    
    void DataDiretory::SetDataSize(const DWORD size)
    {
        data_.Size = size;
    }

    DWORD DataDiretory::GetDataRelativeVirtualAddress() const
    {
        return data_.VirtualAddress;
    }

    void DataDiretory::SetDataVirtualAddress(const DWORD virtual_address)
    {
        data_.VirtualAddress = virtual_address;
    }


}