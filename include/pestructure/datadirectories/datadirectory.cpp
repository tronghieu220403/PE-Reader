#include "datadirectory.h"

namespace pe
{
    DataDiretory::DataDiretory(const std::string &name, const IMAGE_DATA_DIRECTORY &data)
    {
        SetName(name);
        SetData(data);
    }

    DataDiretory::DataDiretory(const std::string& name, const DWORD virtual_address, const DWORD size)
    {
        SetName(name);
        SetDataRelativeVirtualAddress(virtual_address);
        SetDataSize(size);
    }

    std::string DataDiretory::GetName() const {
        return name_;
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

    void DataDiretory::SetDataRelativeVirtualAddress(const DWORD virtual_address)
    {
        data_.VirtualAddress = virtual_address;
    }

    std::string DataDiretory::ToString(int pad)
    {
        std::string s;
        std::string pad_str(pad * 4, ' ');
        std::string pad_str_sub(pad * 4 + 2, ' ');
        s.append(pad_str + GetName() + ":\n"); 
        s.append(pad_str_sub + "RVA:  " + ToHex(GetDataRelativeVirtualAddress()) + "\n"); 
        s.append(pad_str_sub + "Size: " + ToHex(GetDataSize()) + "\n");
        return s;
    }
}