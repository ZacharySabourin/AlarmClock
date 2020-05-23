#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
    public:
        Song(std::string songLink);
        ~Song();
        void playSong();
};

#endif