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

}

void MusicPlayer::playSong()
{
    int index = (rand() % songs.size()) + 1;
    songs[index]->playSong();
}
