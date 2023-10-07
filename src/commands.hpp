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

        if (command.existsArg("-n", "--namespace"))
        {
            std::cout << "namespace: " << command.getArg("-n", "--namespace") << std::endl;
        }
        else
        {
            std::cout << "namespace: "
                      << "default" << std::endl;
        }

        // throw NotImplementedException();
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