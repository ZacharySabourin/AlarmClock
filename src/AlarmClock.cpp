#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <time.h>

using namespace std;

class AlarmClock
{   
private:
    time_t alarmTime;
    time_t currentTime;
    struct tm *tmCur;
    struct tm *tmAlarm;

public:
    AlarmClock(char *alarm)
    {   
        tmAlarm = new tm();
        strptime(alarm, "%Y/%m/%d %R", tmAlarm);
        tmAlarm->tm_isdst = -1;

        alarmTime = mktime(tmAlarm);
        currentTime = time(0);

        tmCur = new tm();
        tmCur = localtime(&currentTime);
        tmCur->tm_isdst = -1;     
    }

    ~AlarmClock()
    {

    }

    void displayClock()
    {
        system("clear");

        cout << "Alarm for: " << asctime(tmAlarm) << endl;
        cout << setfill(' ') << setw(50) << "        TIMER         \n"; 
        cout << setfill(' ') << setw(51) << "------------------------\n"; 
        cout << setfill(' ') << setw(29); 
        cout << "| " << setfill('2') << setw(2) << tmCur->tm_hour << "  :  "; 
        cout << setfill('0') << setw(2) << tmCur->tm_min << "  :  "; 
        cout << setfill('0') << setw(2) << tmCur->tm_sec << "   |" << endl; 
        cout << setfill(' ') << setw(51) << "------------------------\n";
    }

    void timer()
    {
        while(difftime(alarmTime, currentTime) >= 0)
        {
            displayClock();
            sleep(1);
            currentTime = time(0);
            tmCur = localtime(&currentTime);        
        }            
    }
};