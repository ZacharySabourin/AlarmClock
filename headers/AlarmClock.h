#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

namespace AlarmClock
{
    class AlarmClock
    {
    public:
        AlarmClock(char *alarm);
        ~AlarmClock();
        double timeDifference();
    };
}

#endif