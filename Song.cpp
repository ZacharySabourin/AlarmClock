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
            system("xdg -open ");
        }
};