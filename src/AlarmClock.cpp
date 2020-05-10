#include <iostream>
#include <iomanip>
#include <time.h>
#include "../headers/AlarmClock.h"

using namespace std;

namespace AlarmClock
{
    class AlarmClock
    {   
    private:
        time_t currentTime, alarmTime;
        tm *tmOne;

    public:
        AlarmClock(char *alarm)
        {            
            if(strptime(alarm, "%b %d %r", tmOne) == NULL)
                std::cout << "Error formatting time" << std::endl;

            alarmTime = mktime(tmOne);
        }

        ~AlarmClock()
        {

        }

        int timeDifference()
        {
            return difftime(alarmTime, time(NULL));
        }

    //FIX THE TIME
        void displayClock()
        {
            system("clear");

            cout << "Alarm set for : "
            cout << setfill(' ') << setw(55) << "         TIMER         \n"; 
            cout << setfill(' ') << setw(55) << " --------------------------\n"; 
            cout << setfill(' ') << setw(29); 
            cout << "| " << setfill('0') << setw(2) << tmOne->tm_hour << " hrs | "; 
            cout << setfill('0') << setw(2) << tmOne->tm_min << " min | "; 
            cout << setfill('0') << setw(2) << tmOne->tm_sec << " sec |" << endl; 
            cout << setfill(' ') << setw(55) << " --------------------------\n";
        }

        void countdown()
        {

            
        }
    };
}
