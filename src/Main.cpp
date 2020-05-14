#include <iostream>
#include "AlarmClock.cpp"

int main()
{
    AlarmClock *alarmClock;
    string alarmTime;

    cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << endl << ">";
    getline(cin, alarmTime);

    char *alarmPtr = &alarmTime[0];

    alarmClock = new AlarmClock(alarmPtr);
    alarmClock->timer();

    return 0;
}