#include <iostream>
#include <vector>
#include <memory>
#include "../headers/MusicPlayer.h"

MusicPlayer::MusicPlayer(std::vector<std::string> &songList)
{
    for(auto it = songList.begin(); it != songList.end(); ++it)
        songs.push_back(std::make_unique<Song>(*it));
}

MusicPlayer::~MusicPlayer()
{
    songs.clear();
}

void MusicPlayer::playSong()
{
    srand((unsigned) time(0));
    int index = (rand() % songs.size());
    songs[index]->playSong();
}
