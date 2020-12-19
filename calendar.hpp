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

        // Give back the year code
        return yearList[year];
    }

    int caluclateFirstDay(int year){
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

        // Calculates Year Code
        int yearCode = getYearCode(year);
        // Adds previous value to year code
        int afterYearCode = afterMonthValue + yearCode;
        // Calulates the remainder by 7 after adding previous value with the last two digits again
        int finalValue = (afterYearCode + lastTwoDigitsOfYear) % 7;

        // Use this map to find which day it is
        // Gives back the first day
        return dayList[finalValue];
    }
        std::map<int, int> yearList = {
            {2000, 6},
            {1900, 0},
            {1800, 2},
            {1700, 4}
        };

        std::map<int, int> dayList{
            {1, 0},
            {2, 1},
            {3, 2},
            {4, 3},
            {5, 4},
            {6, 5},
            {0, 6}
        };
        
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

struct YearCalendar{
    // [Should be in year helper] Calculates the first day of any given year
    // Prints back days
    void printDays(){
        std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;
    }
    
    // Prints the calendar for a month
    int printMonthCalendar(int monthNum, int startDay, bool isLeapYear){
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
        else if(monthNum == 2 && isLeapYear){
            totalDays = 29;
        }
        else if(monthNum == 2 && !isLeapYear){
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
        std::cout << std::endl;

        // Print the rest of the rows
        int remainingDays = totalDays - totalDatesInFirstRow;
        std::cout << "  ";
        int firstDayNextMonth = remainingDays % 7;

        for(int i{0}; i <= remainingDays - 1; i++){
            int date = i + totalDatesInFirstRow + 1;
            if(i > 7 && i % 7 == 0 && date < 10){
                std::cout << std::endl << "  " << date << "   ";

            }
            else if(i == 7 && i % 7 == 0 && date == 9){
                std::cout << std::endl << "  " << date << "  ";

            }
            else if(i >= 7 && i % 7 == 0 && date >= 10){
                std::cout << std::endl << " " << date << "  ";
            }
            else if(date + 1 < 10){
            std::cout << date << "   ";
            }
            else if(date + 1 >= 10){
                std::cout << date << "  ";
            }

        }
        std::cout << std::endl;
        return firstDayNextMonth;
    }
    //TODO [Continue from here] make function to print out all the months in an year.
    void printYear(int year){
        bool isLeapYear = false;
        YearCalendarHelper helper;
        int firstDay = helper.caluclateFirstDay(year);

        if(year % 4 == 0){
            isLeapYear = true;
        }

        std::cout << "\t  " << helper.monthList[1] << "\n";
        int firstDayNextMonth = printMonthCalendar(1, firstDay, isLeapYear);

        for(int i{2}; i < 13; i++) {
            // Print month name
            std::string month = helper.monthList[i];
            std::cout << "\t  " << month << "\n";

            // Print month calendar
            firstDayNextMonth = printMonthCalendar(i, firstDayNextMonth, isLeapYear);

            // Leave space then print next calendar
            std::cout << "\n\n";
        }
    }
};
