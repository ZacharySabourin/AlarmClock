#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <time.h>

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
            delete tmAlarm;
            delete tmCur;
        }

        void displayClock()
        {
            system("clear");

            std::cout << "Alarm for: " << asctime(tmAlarm) << std::endl;
            std::cout << std::setfill(' ') << std::setw(50) << "        TIMER         " << std::endl; 
            std::cout << std::setfill(' ') << std::setw(51) << "------------------------" << std::endl; 
            std::cout << std::setfill(' ') << std::setw(29); 
            std::cout << "| " << std::setfill('2') << std::setw(2) << tmCur->tm_hour << "  :  "; 
            std::cout << std::setfill('0') << std::setw(2) << tmCur->tm_min << "  :  "; 
            std::cout << std::setfill('0') << std::setw(2) << tmCur->tm_sec << "   |" << std::endl; 
            std::cout << std::setfill(' ') << std::setw(51) << "------------------------\n";
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

            std::cout << std::endl << "TIME IS UP!" << std::endl;
        }
};