#include <iostream>
#include "AlarmClock.cpp"

int main()
{
    AlarmClock *alarmClock;
    char *time;

    std::cout << "Set the alarm in the specified format (ex: Mar 21 11:22:43 AM)" << std::endl << ">";
    std::cin >> time;

    alarmClock = new AlarmClock(time);

    alarmClock->timer();

    return 0;
}

