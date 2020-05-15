#include <iostream>
#include <regex>
#include "AlarmClock.cpp"

int main()
{
    AlarmClock *alarmClock;
    string alarmTime;
    regex timePattern("^");

    while(!regex_match(alarmTime, timePattern))
    {
        cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << endl << ">";
        getline(cin, alarmTime);
    }
    
    char *alarmPtr = &alarmTime[0];

    alarmClock = new AlarmClock(alarmPtr);
    alarmClock->timer();

    return 0;
}