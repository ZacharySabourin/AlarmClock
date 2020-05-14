#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <time.h>

using namespace std;

class AlarmClock
{   
private:
    time_t currentTime, alarmTime;
    struct tm *tmCur;
    struct tm *tmAlarm;

public:
    AlarmClock(char *alarm)
    {   
        currentTime = time(0);

        tmCur = new tm();
        tmCur = localtime(&currentTime);

        tmAlarm = new tm();
        if(strptime(alarm, "%Y/%m/%d %R", tmAlarm) == NULL)
            cout << "Error formatting time" << endl;        

        alarmTime = mktime(tmAlarm);
    }

    ~AlarmClock()
    {

    }

    void displayClock()
    {
        system("clear");

        cout << "Alarm for: " << put_time(tmAlarm, "%Y/%m/%d %R") << endl;
        cout << setfill(' ') << setw(50) << "        TIMER         \n"; 
        cout << setfill(' ') << setw(51) << "------------------------\n"; 
        cout << setfill(' ') << setw(29); 
        cout << "| " << setfill('2') << setw(2) << tmCur->tm_hour << "  :  "; 
        cout << setfill('2') << setw(2) << tmCur->tm_min << "  :  "; 
        cout << setfill('2') << setw(2) << tmCur->tm_sec << "   |" << endl; 
        cout << setfill(' ') << setw(51) << "------------------------\n";
    }

    void timer()
    {
        while(difftime(alarmTime, currentTime) > 0)
        {
            displayClock();
            sleep(1);
            currentTime = time(0);
            tmCur = localtime(&currentTime);        
        }            
    }
};