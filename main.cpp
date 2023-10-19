#include "ulti/everything.h"
#include "pestructure/fileheader/dosheader.h"
#include "pestructure/fileheader/ntheader.h"

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
}