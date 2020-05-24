#include <iostream>
#include "../headers/Song.h"

Song::Song(std::string &songLink)
{
    songUrl = songLink;
}

Song::~Song()
{

}

void Song::playSong()
{
    /*
        wslCommand = "cmd.exe /C start ";
        macOSCommand = "open ";
        windowsCommand = "start ";
        linuxCommand = "xdg-open ";
    */
    std::string wslCommand = "cmd.exe /C start ";
    wslCommand.append(songUrl);

    char *commandPtr = &wslCommand[0];
    system(commandPtr);
}