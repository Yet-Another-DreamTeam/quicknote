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
    std::string defaultCommandName = "help";

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

    std::string getHelpAsString()
    {
        std::string help = "";
        std::list<commandInfo> sortedCommands = this->commands;

        sortedCommands.sort([](const commandInfo &a, const commandInfo &b) {
            return a.name < b.name;
        });

        for (auto &commandInfo : sortedCommands)
        {
            help += commandInfo.name + " - " + commandInfo.description + "\n";
        }

        return help;
    }

    void callCommand(std::string command,int argc, char *argv[] )
    {
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

    void execute(int argc, char *argv[])
    {

        if (argc < 2)
        {
            std::cout << "Command not found \n" << std::endl;
            // throw lpstd::exceptions::ParameterException("argc < 2");

            this->callCommand(defaultCommandName, argc, argv);

            return;
        }

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