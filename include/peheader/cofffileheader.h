#ifndef PEREADER_DISPLAY_COFFFILEHEADER_H_
#define PEREADER_DISPLAY_COFFFILEHEADER_H_

#include "ulti/everything.h"

namespace pe
{
    class CoffFileHeader
    {
    private:
        IMAGE_FILE_HEADER file_header_;
    public:
        CoffFileHeader() = default;
        explicit CoffFileHeader(const char* buffer);
    };

}

#endif