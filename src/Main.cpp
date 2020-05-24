#include "../headers/AlarmClock.h"
#include "../headers/MusicPlayer.h"

int main()
{
    AlarmClock *alarmClock = new AlarmClock();
    alarmClock->setAlarm();
    alarmClock->startTimer();

    MusicPlayer *player = new MusicPlayer();
    if(player->loadPlayer())
        player->playSong();

    return 0;
}