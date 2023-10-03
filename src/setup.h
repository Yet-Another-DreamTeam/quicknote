

#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <filesystem>
#include <fstream>
#include "../lib/lpstd/lpstd.hpp"

class Setup : public lpstd::Singleton<Setup>
{
private:
public:
#ifdef _WIN32

    std::string home = getenv("USERPROFILE");
    std::string editor = "notepad.exe";
#else
    std::string home = getenv("HOME");
    std::string editor = "vim";
#endif
    Setup(/* args */)
    {
        home = home + "/.quicknote";

        runSetup();
    }

    ~Setup()
    {
    }

    void createFolder()
    {
#ifdef _WIN32
        mkdir((home).c_str());
#else
        mkdir((home).c_str(), 0777);
#endif
    }

    void runSetup()
    {

        if (!std::filesystem::exists(home))
            createFolder();
    }
};

#endif // SETUP_H