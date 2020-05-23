#include <iostream>
#include "./headers/Song.h"

std::string songUrl;

Song::Song(std::string songLink)
{
    songUrl = songLink;
}

Song::~Song()
{

}

void Song::playSong()
{
    std::string command = "xdg -open ";
    command.append(songUrl);
    char *commandPtr = &command[0];
    system(commandPtr);
    delete commandPtr;
}