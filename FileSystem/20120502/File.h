#pragma once
#ifndef FILE_H
#define FILE_H
#include <filesystem>
#include "Component.h"

namespace fs = std::filesystem;

class File : public Component {
private:
    uintmax_t size;
public:
    File(const std::wstring& path);
    uintmax_t getSize();
    void showAllChildren(int level);
};
File::File(const std::wstring& path) : Component::Component(path) {
    this->size = fs::file_size(path);
}
uintmax_t File::getSize() {
    return size;
}
void File::showAllChildren(int level = 1) {};
#endif // !FILE_H
