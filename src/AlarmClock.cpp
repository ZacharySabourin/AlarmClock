#include <iostream>
#include <time.h>
#include "../headers/AlarmClock.h"

namespace AlarmClock
{
    class AlarmClock
    {   
    private:
        time_t alarmTime;
        tm *tmOne;

    public:
        AlarmClock(char *alarm)
        {
            if(strptime(alarm, "%b %d %r", tmOne) == NULL)
                std::cout << "Error formatting time" << std::endl;

            alarmTime = mktime(tmOne);
        }

        ~AlarmClock()
        {

        }

        double timeDifference()
        {
            return difftime(alarmTime, time(NULL));
        }
    };
}
