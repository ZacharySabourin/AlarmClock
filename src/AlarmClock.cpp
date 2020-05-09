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
        time_t alarmTime;
        tm *tmOne;
        int hours, minutes, seconds;

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

        double timeDifference()
        {
            return difftime(alarmTime, time(NULL));
        }

        void displayClock()
        {
            system("clear");

            cout << setfill(' ') << setw(55) << "         TIMER         \n"; 
            cout << setfill(' ') << setw(55) << " --------------------------\n"; 
            cout << setfill(' ') << setw(29); 
            cout << "| " << setfill('0') << setw(2) << hours << " hrs | "; 
            cout << setfill('0') << setw(2) << minutes << " min | "; 
            cout << setfill('0') << setw(2) << seconds << " sec |" << endl; 
            cout << setfill(' ') << setw(55) << " --------------------------\n";
        }

        void countdown()
        {

            
        }
    };
}
