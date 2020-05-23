#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include "../headers/AlarmClock.h"
#include "../headers/MusicPlayer.h"

using namespace std;

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
    AlarmClock *alarmClock;
    string alarmTime;
    regex timePattern("^\\d{4}\\/\\d{1,2}\\/\\d{1,2}\\s([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");

    while(!regex_match(alarmTime, timePattern))
    {
        cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << endl << ">";
        getline(cin, alarmTime);
    }
    
    char *alarmPtr = &alarmTime[0];

    alarmClock = new AlarmClock(alarmPtr);
    alarmClock->timer();

    delete alarmPtr;
    delete alarmClock;
}

void startMusic()
{
    string fileName = "../urls.txt";
    ifstream songFile(fileName);

    if(!songFile.is_open())
        cout << "Error opening file" << endl;
    
    else
    {
        vector<string> songList;
        string song;

        while(getline(songFile, song))
            songList.push_back(song);

        songFile.close();

        MusicPlayer *player = new MusicPlayer(&songList);
        int index;
    }
}

int randomNumber(int &length)
{

}