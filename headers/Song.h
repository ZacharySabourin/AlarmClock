#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
    private:
        std::string songUrl; 
        
    public:
        Song(std::string songLink);
        ~Song();
        void playSong();
};

#endif