#include <iostream>
#include "../headers/AlarmClock.h"

using namespace AlarmClock;
using namespace std;

int main()
{
    AlarmClock::AlarmClock *alarmClock;
    char *time;

    cout << "Set the alarm in the specified format (ex: Mar 21 11:22:43 AM)" << endl << ">";
    cin >> time;

    alarmClock = new AlarmClock::AlarmClock(time);

    return 0;
}

