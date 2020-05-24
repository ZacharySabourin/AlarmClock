#include <iostream>
#include <fstream>
#include "../headers/MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
    
}

MusicPlayer::~MusicPlayer()
{

}

void MusicPlayer::playSong()
{
    srand((unsigned) time(0));
    int index = (rand() % songs.size());
    songs[index]->playSong();
}

bool MusicPlayer::loadPlayer()
{
    std::ifstream songFile("urls.txt");

    if(!songFile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return false;
    }

    std::string songUrl;

    while(getline(songFile, songUrl))
        songs.push_back(std::make_unique<Song>(songUrl));

    songFile.close(); 
    std::cout << "PLAYING SONG..." << std::endl;
    return true;
}
