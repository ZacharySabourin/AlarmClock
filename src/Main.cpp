#include <iostream>
#include <regex>
#include "AlarmClock.cpp"

int main()
{
    AlarmClock *alarmClock;
    string alarmTime;
    regex timePattern("^\\d{4}\\/\\d{1,2}\\/\\d{1,2}\\s([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");

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