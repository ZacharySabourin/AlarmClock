#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <time.h>

class AlarmClock
{   
private:
    time_t currentTime, alarmTime;
    tm *tmCur, *tmAlarm;

public:
    AlarmClock(char *alarm)
    {   
        currentTime - time(0);
        tmCur = localtime(&currentTime);

        if(strptime(alarm, "%b %d %r", tmAlarm) == NULL)
            std::cout << "Error formatting time" << std::endl;

        alarmTime = mktime(tmAlarm);
    }

    ~AlarmClock()
    {

    }

    void displayClock()
    {
        system("clear");

        std::cout << "Alarm set for : " << tmAlarm->tm_wday << " " << tmAlarm->tm_mday << " " << tmAlarm->tm_hour << ":" << tmAlarm->tm_min << std::endl;
        std::cout << std::setfill(' ') << std::setw(55) << "         TIMER         \n"; 
        std::cout << std::setfill(' ') << std::setw(55) << " --------------------------\n"; 
        std::cout << std::setfill(' ') << std::setw(29); 
        std::cout << "| " << std::setfill('0') << std::setw(2) << tmCur->tm_hour << " hrs | "; 
        std::cout << std::setfill('0') << std::setw(2) << tmCur->tm_min << " min | "; 
        std::cout << std::setfill('0') << std::setw(2) << tmCur->tm_sec << " sec |" << std::endl; 
        std::cout << std::setfill(' ') << std::setw(55) << " --------------------------\n";
    }

    void timer()
    {
        while(difftime(alarmTime, currentTime) > 0)
        {
            displayClock();
            currentTime = time(0);
            tmCur = localtime(&currentTime);
            sleep(1);
        }            
    }
};