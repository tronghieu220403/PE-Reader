#ifndef PEREADER_DISPLAY_OPTIONALHEADER_H_
#define PEREADER_DISPLAY_OPTIONALHEADER_H_

#include "ulti/everything.h"
#include "peheader/datadirectory.h"

namespace pe
{
    class OptionalHeader
    {
        private:
            std::shared_ptr<std::vector<DataDiretory>> data_directory_vector_;

        public:
            OptionalHeader() = default;
            OptionalHeader(std::vector<char> pe_data, int offset);

            std::shared_ptr<std::vector<DataDiretory>> GetDataDirectoryVector() const;

            void SetDataDirectoryVector(const std::shared_ptr<std::vector<DataDiretory>>& data_directories);

            void AddElementToDataDirectories(const std::string& name, const IMAGE_DATA_DIRECTORY& image_data_directory);

            void AddElementToDataDirectories(const DataDiretory& data);

            DataDiretory GetDataDirectoryByName(const std::string& name);
    }
}

#endif