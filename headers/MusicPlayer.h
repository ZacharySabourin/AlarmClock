#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <vector>
#include <string>
#include <memory>
#include "Song.h"

class MusicPlayer
{
    public:
        MusicPlayer();
        ~MusicPlayer();
        void playSong();
        bool loadPlayer();

    private:
        std::vector<std::unique_ptr<Song>> songs;
};

#endif