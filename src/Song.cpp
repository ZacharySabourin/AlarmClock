#include <iostream>

using namespace std;

class Song
{
    private:
        string songUrl;

    public:
        Song(string songLink)
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