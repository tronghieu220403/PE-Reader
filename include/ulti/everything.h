#ifndef PEREADER_ULTI_EVERYTHING_H_
#define PEREADER_ULTI_EVERYTHING_H_

#include <Windows.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <format>
#include <filesystem>

namespace pe
{

    typedef struct Field
    {
        std::string name;
        unsigned long long value;
        WORD size;
    };

    typedef struct FieldStr
    {
        std::string name;
        std::string value;
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

    inline std::string MemoryToString(const char *data)
    {
        std::string res;
        for (int i = 0; data[i] != 0; i++)
        {
            res.push_back(char(data[i]));
        }
        return res;
    }

    inline std::wstring MemoryToWstring(const WCHAR *data)
    {
        std::wstring res;
        for (int i = 0; data[i] != 0; i++)
        {
            res.push_back(WCHAR(data[i]));
        }
        return res;
    }

    inline std::wstring MemoryToWstring(const WCHAR *data, int size)
    {
        std::wstring res;
        for (int i = 0; i < size; i++)
        {
            res.push_back(WCHAR(data[i]));
        }
        return res;
    }

    inline std::string ToHex(unsigned long long value)
    {
        return "0x" + std::format("{:x}", value);
    }
}

#endif