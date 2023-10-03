#include "./main.h"

int main(int argc, char *argv[])
{
    command.addCommand("add", "add a note", commands::add);
    command.addCommand("list", "list all notes", commands::list);
    command.addCommand("view", "remove a note", commands::view);
    command.addCommand("edit", "edit a note", commands::edit);
    command.addCommand("remove", "remove a note", commands::remove);
    command.addCommand("search", "search quicknote", commands::search);
    command.addCommand("help", "show help", commands::help);

    command.execute(argc, argv);

    setup.runSetup();
    // std::cout << "quicknote!" << std::endl;
    return 0;
}