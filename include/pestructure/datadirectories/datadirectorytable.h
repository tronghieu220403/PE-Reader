#ifndef PEREADER_PEHEADER_DATADIRECTORIES_DATADIRECTORYTABLE_H_
#define PEREADER_PEHEADER_DATADIRECTORIES_DATADIRECTORYTABLE_H_

#include "ulti/everything.h"
#include "pestructure/datadirectories/datadirectory.h"

namespace pe
{
    class DataDiretoryTable
    {
    private:    
        std::vector<DataDiretory> entry_vector_;
    public:
        DataDiretoryTable() = default;

        DataDiretoryTable(const char* data_directories_data);

        void SetDataDiretoryTable(const char* data_directories_data);

        DataDiretory GetDataDirectoryByName(const std::string& name);

        std::string ToString(int pad);
    };
}

#endif