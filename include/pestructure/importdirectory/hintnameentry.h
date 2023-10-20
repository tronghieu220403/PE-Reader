#ifndef PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMEENTRY_H_
#define PEREADER_PEHEADER_IMPORTDIRECTORY_HINTNAMEENTRY_H_

#include "ulti/everything.h"
#include "pestructure/importdirectory/hintnameentry.h"

namespace pe
{
    class HintNameEntry
    {
    private:
        Field hint_;
        FieldStr name_;
        int pad_ = 1;
    public:

        HintNameEntry() = default;
        explicit HintNameEntry(const char* pe_data, int offset);

        void SetHintNameEntry(const char* pe_data, int offset);

        Field GetHintField() const;
        FieldStr GetNameField() const;
        int GetSize() const;

        std::string ToString(int pad);
        
    };
}

#endif