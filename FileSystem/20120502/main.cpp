//config c++17
#include <iostream>
#include <filesystem>
#include "File.h"
#include "Folder.h"

namespace fs = std::filesystem;

int main()
{
    std::wstring path;
    std::cout << "Nhap duong dan: ";
    getline(std::wcin, path);
    if (fs::exists(path)) {     
        try {
            if (fs::is_directory(path)) {
                Folder root(path);
                std::cout << "Ten folder: " << root.getName() << '\n';
                std::cout << "Kich thuoc cua " << root.getName() << ": " << root.getSize() << " bytes\n";
                int q;
                std::cout << "-----------------------------------\n";
                std::cout << "1. Liet ke con truc tiep.\n";
                std::cout << "2. Liet ke tat ca con.\n";
                std::cout << "Nhap yeu cau (1->2): "; std::cin >> q;
                if (q == 1) root.showChildren(); else root.showAllChildren();
            }
            else {
                File root(path);
                std::cout << "Ten file: " << root.getName() << '\n';
                std::cout << "Kich thuoc cua " << root.getName() << ": " << root.getSize() << " bytes";
            }
        }
        catch (std::exception e) {
            std::cout << "Ten file con hoac folder con khong duoc la tieng Viet co dau\n";
        }
    }
    else {
        std::cout << "Duong dan khong ton tai\n";
    }
    system("pause");
}