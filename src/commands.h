#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include "../lib/lpstd/lpstd.hpp"

using namespace lpstd::exceptions;

namespace commands
{
    void add(int argc, char *argv[])
    {
        std::cout << "add" << std::endl;
        throw NotImplementedException();
    }

    void list(int argc, char *argv[])
    {
        std::cout << "list" << std::endl;
        throw NotImplementedException();
    }

    void view(int argc, char *argv[])
    {
        std::cout << "view" << std::endl;
        throw NotImplementedException();
    }

    void edit(int argc, char *argv[])
    {
        std::cout << "edit" << std::endl;
        throw NotImplementedException();
    }

    void remove(int argc, char *argv[])
    {
        std::cout << "remove" << std::endl;
        throw NotImplementedException();
    }

    void search(int argc, char *argv[])
    {
        std::cout << "search" << std::endl;
        throw NotImplementedException();
    }

    // not implemented
    void collect(int argc, char *argv[])
    {
        std::cout << "collect" << std::endl;
        throw NotImplementedException();
    }

    void help(int argc, char *argv[])
    {
        std::cout << "help" << std::endl;
        throw NotImplementedException();
    }

} // namespace commands

#endif