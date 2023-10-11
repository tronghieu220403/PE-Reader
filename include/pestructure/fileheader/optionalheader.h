#ifndef PEREADER_PEHEADER_OPTIONALHEADER_H_
#define PEREADER_PEHEADER_OPTIONALHEADER_H_

#include "ulti/everything.h"
#include "pestructure/datadirectories/datadirectorytable.h"
#include "pestructure/peconstants.h"

namespace pe
{
    class OptionalHeader
    {
    private:
        std::vector<Field> standard_field_vector_;
        std::vector<Field> windows_specific_field_vector_;
        DataDiretoryTable data_dir_table_;
    public:
        OptionalHeader() = default;
        explicit OptionalHeader(const char* option_data);

        // For Standard fields

        void SetStandardFieldVector(const char* standard_fields_data_);
        Field GetStandardFieldByName(const std::string& name);

        // For Windows-specific fields

        void SetWindowsSpecificFieldVector(const char* windows_specific_fields_data_);
        Field GetWindowsSpecificFieldByName(const std::string& name);

        // For Data directories

        void SetDataDiretoryTable(const char* data_directories_data);
        void SetDataDirectoryTable(const DataDiretoryTable& data_dir_table);
        DataDiretoryTable GetDataDirectoryTable() const;

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

    };
}

#endif