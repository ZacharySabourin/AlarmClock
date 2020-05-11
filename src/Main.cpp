#include <iostream>
#include "AlarmClock.cpp"

int main()
{
    AlarmClock *alarmClock;
    string time;

    cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << endl << ">";
    getline(cin, time);

    char *alarm = &time[0];

    alarmClock = new AlarmClock(alarm);
    alarmClock->timer();

    return 0;
}

