#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include <time.h>

class AlarmClock
{
    public:
        AlarmClock();
        ~AlarmClock();      
        void setAlarm();
        void startTimer();

    private:
        time_t alarmTime;
        time_t currentTime;
        struct tm *tmCur;
        struct tm *tmAlarm; 
        void displayClock();
};

#endif