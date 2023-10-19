#ifndef PEREADER_PEHEADER_DATADIRECTORIES_DATADIRECTORY_H_
#define PEREADER_PEHEADER_DATADIRECTORIES_DATADIRECTORY_H_

#include "ulti/everything.h"

namespace pe
{
    class DataDiretory
    {
    private:
        std::string name_;
        IMAGE_DATA_DIRECTORY data_;

    public:
        DataDiretory() = default;
        DataDiretory(const std::string& name, const IMAGE_DATA_DIRECTORY& data);

        DataDiretory(const std::string& name, const DWORD virtual_address, const DWORD size);

        std::string GetName() const;
        void SetName(const std::string& name);

        IMAGE_DATA_DIRECTORY GetData() const;
        void SetData(const IMAGE_DATA_DIRECTORY& data);

        DWORD GetDataSize() const;
        void SetDataSize(const DWORD size);

        DWORD GetDataRelativeVirtualAddress() const;
        void SetDataRelativeVirtualAddress(const DWORD virtual_address);

        std::string ToString(int pad);
    };
}

#endif