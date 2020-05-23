#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "../headers/Song.h"

using namespace std;

class MusicPlayer
{
    private:
        vector<unique_ptr<Song>> songs;

    public:
        MusicPlayer(vector<string> *songList)
        {
            for(auto it = songList->begin(); it != songList->end(); ++it)
                songs.push_back(make_unique<Song>(*it));
        }

        ~MusicPlayer()
        {

        }
};