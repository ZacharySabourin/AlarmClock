#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include "../headers/AlarmClock.h"
#include "../headers/MusicPlayer.h"

void startAlarm();
void startMusic();

int main()
{
    startAlarm();
    startMusic();

    return 0;
}

void startAlarm()
{
    std::string alarmTime;
    std::regex timePattern("^\\d{4}\\/\\d{1,2}\\/\\d{1,2}\\s([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");

    while(!regex_match(alarmTime, timePattern))
    {
        std::cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << std::endl << ">";
        std::getline(std::cin, alarmTime);
    }
    
    char *alarmPtr = &alarmTime[0];

    AlarmClock *alarmClock = new AlarmClock(alarmPtr);
    alarmClock->timer();
}

void startMusic()
{
    std::ifstream songFile;
    songFile.open("urls.txt");

    if(!songFile.is_open())
        std::cout << "Error opening file" << std::endl;
    
    else
    {
        std::vector<std::string> songList;
        std::string song;

        while(getline(songFile, song))
            songList.push_back(song);

        songFile.close();

        MusicPlayer *player = new MusicPlayer(songList);
        player->playSong();
    }
}