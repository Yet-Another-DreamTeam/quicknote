#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>

namespace commands
{
    void add(int argc, char *argv[])
    {
        std::cout << "add" << std::endl;
    }

    void list(int argc, char *argv[])
    {
        std::cout << "list" << std::endl;
    }

    void view(int argc, char *argv[])
    {
        std::cout << "view" << std::endl;
    }

    void edit(int argc, char *argv[])
    {
        std::cout << "edit" << std::endl;
    }

    void remove(int argc, char *argv[])
    {
        std::cout << "remove" << std::endl;
    }

    void search(int argc, char *argv[])
    {
        std::cout << "search" << std::endl;
    }

    // not implemented
    void collect(int argc, char *argv[])
    {
        // lpstd::NotImplementedException();
        std::cout << "collect" << std::endl;
    }

    void help(int argc, char *argv[])
    {
        std::cout << "help" << std::endl;
    }

} // namespace commands

#endif