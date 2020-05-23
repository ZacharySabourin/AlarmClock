#include <iostream>
#include <vector>
#include <memory>
#include "./headers/Song.h"

class MusicPlayer
{
    private:
        std::vector<std::unique_ptr<Song>> songs;

    public:
        MusicPlayer(std::vector<std::string> &songList)
        {
            for(auto it = songList.begin(); it != songList.end(); ++it)
                songs.push_back(std::make_unique<Song>(*it));
        }

        ~MusicPlayer()
        {

        }

        void playSong()
        {
            int index = (rand() % songs.size()) + 1;
            songs[index]->playSong();
        }
};