#include <map> // For storing pre defined codes for days/years for the algorithm
#include <cmath>// for floor() function
#include <string>// For easier calendar printing
#include <iostream>

#pragma once // To not import things twice

// Helps the YearCalendar class by doing all the calculations
struct YearCalendarHelper{

    // Calculates the year code for the year
    int getYearCode(int year);

    int caluclateFirstDay(int year);

    std::map<int, int> yearList = {
        {2000, 6},
        {1900, 0},
        {1800, 2},
        {1700, 4}
    };

    // Use this map to find which day it is(Changed it to more sensisble code)
    std::map<int, int> dayList{
        {1, 0}, // Sunday
        {2, 1}, // Monday
        {3, 2}, // Tuesday
        {4, 3}, // Wednesday
        {5, 4}, // Thursday
        {6, 5}, // Friday
        {0, 6}  // Saturday
    };
        
    // Use this map to find which month it is
    std::map<int, std::string> monthList = {
        {1, "Jan"},
        {2, "Feb"},
        {3, "Mar"},
        {4, "Apr"},
        {5, "May"},
        {6, "Jun"},
        {7, "Jul"},
        {8, "Aug"},
        {9, "Sep"},
        {10, "Oct"},
        {11, "Nov"},
        {12, "Dec"}
    };

};

// Main year calendar class
struct YearCalendar{
    // Prints back days
    void printDays();
    
    // Prints the calendar for a month
    int printMonthCalendar(int monthNum, int startDay, bool isLeapYear);

    void printYear(int year);

    void menu();
};
