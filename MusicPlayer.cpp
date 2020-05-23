#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "./headers/Song.hpp"

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
};