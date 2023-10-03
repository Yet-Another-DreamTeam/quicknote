#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
#include "../lib/lpstd/lpstd.hpp"

struct commandInfo
{
    std::string name;
    std::string description;
    void (*func)(int argc, char *argv[]);
};

class Command : public lpstd::Singleton<Command>
{

private:
    std::list<commandInfo> commands = {};

public:
    Command(/* args */)
    {
    }

    ~Command()
    {
    }

    void addCommand(std::string name, std::string description, void (*func)(int argc, char *argv[]))
    {
        commandInfo command;
        command.name = name;
        command.description = description;
        command.func = func;
        this->commands.push_back(command);
    }

    void execute(int argc, char *argv[])
    {
        std::string command = argv[1];
        std::vector<std::string> args;
        for (int i = 2; i < argc; i++)
        {
            args.push_back(argv[i]);
        }

        for (auto &commandInfo : this->commands)
        {
            if (commandInfo.name == command)
            {
                commandInfo.func(argc, argv);
                return;
            }
        }
        std::cout << "Command not found" << std::endl;
    }
};

#endif // COMMAND_H