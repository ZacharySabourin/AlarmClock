#include <time.h>
#include "ClockInternals.h"

namespace AlarmClock
{
    class ClockInternals
    {
    private:
        time_t currentTime;
        time_t alarmTime;
        double remainingTime;

    public:
        ClockInternals()
        {
            currentTime = time(0);
        }

        ~ClockInternals()
        {

        }
};
}
