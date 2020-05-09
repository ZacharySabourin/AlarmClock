#include <iostream>
#include "ClockInternals.h"

namespace AlarmClock
{
    class AlarmClock
    {
    private:
        ClockInternals *internals;

    public:
        AlarmClock()
        {
            internals = new ClockInternals();
        }

        ~AlarmClock()
        {

        }
    };
}
