#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include "./headers/AlarmClock.hpp"
#include "./headers/MusicPlayer.hpp"


void startAlarm();
void startMusic();
int randomNumber(int &length);

int main()
{
    startAlarm();
    startMusic();

    return 0;
}

void startAlarm()
{
    AlarmClock *alarmClock;
    std::string alarmTime;
    std::regex timePattern("^\\d{4}\\/\\d{1,2}\\/\\d{1,2}\\s([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");

    while(!regex_match(alarmTime, timePattern))
    {
        std::cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << std::endl << ">";
        std::getline(std::cin, alarmTime);
    }
    
    char *alarmPtr = &alarmTime[0];

    alarmClock = new AlarmClock(*alarmPtr);
    alarmClock->timer();

    delete alarmPtr;
    delete alarmClock;
}

void startMusic()
{
    std::string fileName = "../urls.txt";
    std::ifstream songFile(fileName);

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
        int index;
    }
}

int randomNumber(int &length)
{
    return 0;
}