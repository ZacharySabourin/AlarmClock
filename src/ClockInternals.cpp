#include <iostream>
#include <time.h>
#include "ClockInternals.h"

namespace AlarmClock
{
    class ClockInternals
    {
    private:
        time_t currentTime, alarmTime;
        tm *tm1, *tm2;
        double remainingTime;

    public:
        ClockInternals(char *alarmTime)
        {
            currentTime = time(0);

            tm1 = localtime(&currentTime);

            if(strptime(alarmTime, "%b %d %r", tm2) == NULL)
                std::cout << "Error formatting time" << std::endl;
        }

        ~ClockInternals()
        {

        }

        double timeDifference()
        {

        }
    };
}


