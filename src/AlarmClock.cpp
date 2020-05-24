#include <iostream>
#include <iomanip>
#include <regex>
#include <unistd.h>
#include "../headers/AlarmClock.h"

AlarmClock::AlarmClock()
{   
    tmAlarm = new tm();  
    tmAlarm->tm_isdst = -1;
    
    currentTime = time(0);
    tmCur = new tm();
    tmCur = localtime(&currentTime);
    tmCur->tm_isdst = -1;     
}

AlarmClock::~AlarmClock()
{

}

void AlarmClock::setAlarm()
{
    std::string tempTime;
    std::regex timePattern("^\\d{4}\\/\\d{1,2}\\/\\d{1,2}\\s([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");

    while(!regex_match(tempTime, timePattern))
    {
        std::cout << "Set the alarm in the specified format (ex: YYYY/MM/DD HH:mm)" << std::endl << ">";
        std::getline(std::cin, tempTime);
    }

    char *alarmPtr = &tempTime[0];
    strptime(alarmPtr, "%Y/%m/%d %R", tmAlarm);
    alarmTime = mktime(tmAlarm);
}

void AlarmClock::startTimer()
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

void AlarmClock::displayClock()
{
    system("clear");

    std::cout << "Alarm for: " << asctime(tmAlarm) << std::endl;
    std::cout << std::setfill(' ') << std::setw(50) << "        CLOCK         " << std::endl; 
    std::cout << std::setfill(' ') << std::setw(51) << "------------------------" << std::endl; 
    std::cout << std::setfill(' ') << std::setw(29); 
    std::cout << "| " << std::setfill('0') << std::setw(2) << tmCur->tm_hour << "   :   "; 
    std::cout << std::setfill('0') << std::setw(2) << tmCur->tm_min << "   :  "; 
    std::cout << std::setfill('0') << std::setw(2) << tmCur->tm_sec << "  |" << std::endl; 
    std::cout << std::setfill(' ') << std::setw(51) << "------------------------" << std::endl;
}