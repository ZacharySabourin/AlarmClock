#include <iostream>
#include <vector>
#include <memory>
#include "./headers/MusicPlayer.h"
#include "./headers/Song.h"

std::vector<std::unique_ptr<Song>> songs;

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
