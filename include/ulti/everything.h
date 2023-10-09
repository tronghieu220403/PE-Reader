#ifndef PEREADER_ULTI_EVERYTHING_H_
#define PEREADER_ULTI_EVERYTHING_H_

#include <Windows.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace pe
{

    typedef struct Field
    {
        std::string name;
        unsigned long long value;
        WORD size;
    };

    inline unsigned long long MemoryToUint64(const char *data)
    {
        unsigned long long res = 0;
        memcpy(&res, data, 8);
        return res;
    }

    inline long long MemoryToInt64(const char *data)
    {
        long long res = 0;
        memcpy(&res, data, 8);
        return res;
    }

    inline unsigned int MemoryToUint32(const char *data)
    {
        unsigned int res = 0;
        memcpy(&res, data, 4);
        return res;
    }

    inline int MemoryToInt32(const char *data)
    {
        int res = 0;
        memcpy(&res, data, 4);
        return res;
    }

    inline WORD MemoryToUint16(const char *data)
    {
        int res = 0;
        memcpy(&res, data, 2);
        return res;
    }

}

#endif