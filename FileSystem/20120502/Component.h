#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <filesystem>
namespace fs = std::filesystem;

class Component {
private:
    std::string name;
public:
    Component(const std::wstring& path);
    std::string getName();
    virtual uintmax_t getSize() = 0;
    virtual void showAllChildren(int level = 1) = 0;
};
Component::Component(const std::wstring& path) {
    fs::path file(path);
    this->name = file.filename().generic_string();
    if (this->name == "") this->name = "Folder hien tai";
}
std::string Component::getName() {
    return name;
};
#endif // !COMPONENT_H
