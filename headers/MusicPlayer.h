#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <vector>
#include <string>
#include "Song.h"

class MusicPlayer
{
    public:
        MusicPlayer(std::vector<std::string> &songList);
        ~MusicPlayer();
        void playSong();
};

#endif