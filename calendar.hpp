#include <map>
#include <cmath>
#include <string>
#include <iostream>

#pragma once

struct YearCalendarHelper{
    int getYearCode(int year){
        year = floor(year / 100) * 100;
        while(year < 1700) {
            year = year + 400;
        }

        while (year > 2000) {
            year = year - 400;
        }

        std::map<int, int> yearList = {
            {2000, 6},
            {1900, 0},
            {1800, 2},
            {1700, 4}
        };

        return yearList[year];
    }

};

struct YearCalendar{
    std::string caluclateFirstDay(int year){
        YearCalendarHelper helper;

        int lastTwoDigitsOfYear = year % 100;
        float beforeMonthValue = floor(lastTwoDigitsOfYear/4) + 1;
        int afterMonthValue{};

        if(lastTwoDigitsOfYear % 4 == 0.0) {
            afterMonthValue = beforeMonthValue; 
        }
        else{
            afterMonthValue = beforeMonthValue + 1;
        }

        int yearCode = helper.getYearCode(year);
        int afterYearCode = afterMonthValue + yearCode;
        int finalValue = (afterYearCode + lastTwoDigitsOfYear) % 7;

        std::map<int, std::string> dayList{
            {0, "Sun"},
            {1, "Mon"},
            {2, "Tue"},
            {3, "Wed"},
            {4, "Thu"},
            {5, "Fri"},
            {6, "Sun"}
        };
        return dayList[finalValue];
    }
    void printDays(){
        std::cout << "Sun Mon Tue Wed Thu Fri Sat";
    }
    
    void printMonthCalendar(int monthNum, int startDay){
        int totalDays = 0;

        if(monthNum % 2 == 0 && monthNum != 2 && monthNum != 8){
           totalDays = 30;
        }
        else{
            totalDays = 31;
        }

        printDays();

        int copyStartDay = startDay;
        std::string firstRow = "  ";
        while (copyStartDay != 0){
            firstRow += "    " ;
            copyStartDay -= 1;
        }
        // Print the first row
        // End the line
        // Print the rest of the rows
    }
};
