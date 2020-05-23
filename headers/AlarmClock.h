#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

class AlarmClock
{
    public:
        AlarmClock(char *alarm);
        ~AlarmClock();
        void displayClock();
        void timer();
};

#endif