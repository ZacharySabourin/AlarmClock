#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

class AlarmClock
{
    private:
        time_t alarmTime;
        time_t currentTime;
        struct tm *tmCur;
        struct tm *tmAlarm; 
        
    public:
        AlarmClock(char *alarm);
        ~AlarmClock();
        void displayClock();
        void timer();
};

#endif