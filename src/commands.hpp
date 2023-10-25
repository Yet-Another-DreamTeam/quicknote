#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include "../lib/lpstd/lpstd.hpp"

using namespace lpstd::exceptions;

namespace commands
{

    Command &command = Command::Instance();

    void NotImplemented()
    {
        std::cout << "command: '" << command.getCurrentCommand().name << "' is not implemented" << std::endl;
        throw NotImplementedException();
    }

    void add()
    {
        std::cout << command.getCurrentCommand().name << std::endl;
        std::string command_namespace = "default";

        if (command.existsArg("-n", "--namespace"))
        {
            command_namespace = command.getArg("-n", "--namespace");
        }
        // throw NotImplementedException();
        std::cout << "namespace: " << command_namespace << std::endl;
    }

    void list()
    {
        NotImplemented();
    }

    void view()
    {
        NotImplemented();
    }

    void edit()
    {
        NotImplemented();
    }

    void remove()
    {
        NotImplemented();
    }

    void search()
    {
        NotImplemented();
    }

    void collect()
    {
        NotImplemented();
    }

    void help()
    {
        std::cout << command.getHelpAsString() << std::endl;
    }

} // namespace commands

#endif