#include <map> // For storing pre defined codes for days/years for the algorithm
#include <cmath>// for floor() function
#include <string>// For easier calendar printing
#include <iostream>

#pragma once // To not import things twice

// Helps the YearCalendar class by doing all the calculations
struct YearCalendarHelper{

    // Calculates the year code for the year
    int getYearCode(int year){
        // Get the century of the year
        year = floor(year / 100) * 100;
        // If year is less than 1700 add 400 to it
        while(year < 1700) {
            year = year + 400;
        }

        // If year is over 2000 subtract 400 from it
        while (year > 2000) {
            year = year - 400;
        }

        // We did the above so we can use the pre existing year codes for the four cenutries
        std::map<int, int> yearList = {
            {2000, 6},
            {1900, 0},
            {1800, 2},
            {1700, 4}
        };

        // Give back the year code
        return yearList[year];
    }

};

struct YearCalendar{
    // [Should be in year helper] Calculates the first day of any given year
    std::string caluclateFirstDay(int year){
        // Inits a helper class to calculate the year code
        YearCalendarHelper helper;

        // Gets last two digits of year
        int lastTwoDigitsOfYear = year % 100;
        // Divides last two digits by four, discards remainder and adds 1
        float beforeMonthValue = floor(lastTwoDigitsOfYear/4) + 1;
        int afterMonthValue{};

        // Checks if the year is a leap year or not and adds 1 accordingly
        if(lastTwoDigitsOfYear % 4 == 0.0) {
            afterMonthValue = beforeMonthValue; 
        }
        else{
            afterMonthValue = beforeMonthValue + 1;
        }

        // Uses year helper to get year code
        int yearCode = helper.getYearCode(year);
        // Adds previous value to year code
        int afterYearCode = afterMonthValue + yearCode;
        // Calulates the remainder by 7 after adding previous value with the last two digits again
        int finalValue = (afterYearCode + lastTwoDigitsOfYear) % 7;

        // Use this map to find which day it is
        std::map<int, std::string> dayList{
            {0, "Sun"},
            {1, "Mon"},
            {2, "Tue"},
            {3, "Wed"},
            {4, "Thu"},
            {5, "Fri"},
            {6, "Sun"}
        };
        // Gives back the first day
        return dayList[finalValue];
    }
    // Prints back days
    void printDays(){
        std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;
    }
    
    // Prints the calendar for a month
    void printMonthCalendar(int monthNum, int startDay, bool leapYear){
        // Prints days
        printDays();
        int totalDays = 0;

        // Checks if the month is divisible by two with the exception of February
        if(monthNum < 8 && monthNum % 2 == 0 && monthNum != 2){
           totalDays = 30;
        }
        else if(monthNum < 8 && monthNum % 2 == 1){
            totalDays = 31;
        }
        else if(monthNum > 7 && monthNum % 2 == 0) {
            totalDays = 31;
        }
        else if(monthNum > 7 && monthNum % 2 == 1) {
            totalDays = 30;
        }
        else if(monthNum == 2 && leapYear){
            totalDays = 29;
        }
        else if(monthNum == 2 && !leapYear){
            totalDays = 28;
        }

        // Makes a copy of startDay to not modify the original value
        int copyStartDay = startDay;
        // Gives spacing for aesthetics
        std::string firstRow = "  ";
        // Ensures first date is adequately spaced
        while (copyStartDay != 0){
            firstRow += "    ";
            copyStartDay -= 1;
        }
        // Print the first row
        int totalDatesInFirstRow = 7 - startDay;

        std::cout << firstRow;
        for(int i{1}; i <= totalDatesInFirstRow; i++){
            std::cout << i << "   ";
        }
        // End the line
        // Print the rest of the rows
    }
};
