#include "ulti/everything.h"
#include "pestructure/fileheader/dosheader.h"
#include "pestructure/fileheader/ntheader.h"
#include "pestructure/sectionheaders/sectiontable.h"

std::string file_path = "E:\\Download\\user32.dll";

int main()
{
    std::filesystem::path p{file_path};
    unsigned long long size =  std::filesystem::file_size(p);
    std::ifstream inp(file_path, std::ios_base::binary);
    std::vector<char> v(size);
    inp.read((char *)v.data(), size);

    pe::DosHeader dos_header(v.data());
    std::cout << dos_header.ToString(0);

    pe::NtHeader nt_header(v.data() + dos_header.GetLfanew());
    std::cout<<"\n\n"<<nt_header.ToString(0);

    DWORD section_offset = nt_header.GetOptionalHeader()->GetStandardFieldByName("Magic").value == PE64 ? 0x200 : (0x200 - 128 + 92);

    std::shared_ptr<pe::SectionTable> section_table = std::make_shared<pe::SectionTable>(v.data() + section_offset, nt_header.GetCoffFileHeader()->GetFieldByName("NumberOfSections").value);

    
}