#ifndef PEREADER_DISPLAY_OPTIONALHEADER_H_
#define PEREADER_DISPLAY_OPTIONALHEADER_H_

#include "ulti/everything.h"
#include "peheader/datadirectory.h"
#include "peheader/peconstants.h"

namespace pe
{
    class OptionalHeader
    {
    private:
        std::vector<Field> standard_field_vector_;
        std::vector<Field> windows_specific_field_vector_;
        std::shared_ptr<std::vector<DataDiretory>> data_directory_vector_;
    
    public:
        OptionalHeader() = default;
        explicit OptionalHeader(const char* option_data);

        // For Standard fields

        void SetUpStandardFieldVector(const char* standard_fields_data_);
        Field GetStandardFieldByName(const std::string& name);

        // For Windows-specific fields

        void SetUpWindowsSpecificFieldVector(const char* windows_specific_fields_data_);
        Field GetWindowsSpecificFieldByName(const std::string& name);

        // For Data directories

        void SetUpDataDiretoryVector(const char* data_directories_data);

        void AddElementToDataDirectoryVector(const std::string& name, const IMAGE_DATA_DIRECTORY& image_data_directory);
        void AddElementToDataDirectoryVector(const DataDiretory& data);

        DataDiretory GetDataDirectoryByName(const std::string& name);

    protected:

        /*

        // For Standard fields

        std::vector<Field> GetStandardFieldVector() const;
        void SetStandardFieldVector(const std::vector<Field>& standard_field_vector);

        // For Windows-specific fields

        std::vector<Field> GetWindowsSpecificFieldVector() const;
        void SetStandardFieldVector(const std::vector<Field>& windows_specific_field_vector);

        */
        
        // For Data directories

        std::shared_ptr<std::vector<DataDiretory>> GetDataDirectoryVector() const;

        void SetDataDirectoryVector(const std::shared_ptr<std::vector<DataDiretory>>& data_directory_vector);

    };
}

#endif