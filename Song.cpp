#include <iostream>

class Song
{
    private:
        std::string songUrl;

    public:
        Song(std::string songLink)
        {
            songUrl = songLink;
        }

        ~Song()
        {

        }

        void playSong()
        {
            std::string command = "xdg -open ";
            command.append(songUrl);
            char *commandPtr = &command[0];
            system(commandPtr);
            delete commandPtr;
        }
};