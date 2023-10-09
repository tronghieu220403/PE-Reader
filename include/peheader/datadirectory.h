#ifndef PEREADER_DISPLAY_DATADIRECTORIES_H_
#define PEREADER_DISPLAY_DATADIRECTORIES_H_

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

            DWORD GetDataVirtualAddress() const;
            void SetDataVirtualAddress(const DWORD virtual_address);


    }

}

#endif