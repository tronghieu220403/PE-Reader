#ifndef PEREADER_PEHEADER_COFFFILEHEADER_H_
#define PEREADER_PEHEADER_COFFFILEHEADER_H_

#include "ulti/everything.h"

namespace pe
{
    class CoffFileHeader
    {
    private:
        std::vector<Field> file_header_vector_;
    public:
        CoffFileHeader() = default;
        explicit CoffFileHeader(const char* file_header_data);

        void SetUpCoffFileHeaderVector(const char* file_header_data);
        Field GetFieldByName(const std::string& name);

        std::string ToString(int pad);
    };

}

#endif