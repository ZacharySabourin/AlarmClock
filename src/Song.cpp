#include <iostream>
#include "../headers/Song.h"

Song::Song(std::string songLink)
{
    songUrl = songLink;
}

Song::~Song()
{

}

void Song::playSong()
{
    /*
        WSL: cmd.exe /C start <link>
        MacOS: open <link>
        Windows: start <link>
        Linux: xdg-open <link>
    */
    std::string command = "cmd.exe /C start ";
    command.append(songUrl);

    char *commandPtr = &command[0];
    system(commandPtr);
}