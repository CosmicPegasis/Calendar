#include <map>
#include <cmath>
#include <string>
#include <iostream>

#pragma once

struct CalendarHelper{
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
    void print(int month,int year){
       // Formatting 
    }

    int caluclateFirstDay(int year){
        CalendarHelper helper;

        int lastTwoDigitsOfYear = year % 100;
        float beforeMonthValue = floor(lastTwoDigitsOfYear/4) + 1;
        int afterMonthValue{};

        if(lastTwoDigitsOfYear % 4 == 0.0) {
            afterMonthValue = beforeMonthValue; 
        }
        else{
            afterMonthValue = beforeMonthValue + 1;
        }
        // Finish function
        int yearCode = helper.getYearCode(year);

        int afterYearCode = afterMonthValue + yearCode;
        int finalValue = (afterYearCode + lastTwoDigitsOfYear) % 7;

        std::map<int, std::string> dayList{
            {1, "Sun"},
            {2, "Mon"},
            {3, "Tue"},
            {4, "Wed"},
            {5, "Thu"},
            {6, "Fri"},
            {0, "Sun"}
        };
        std::cout << dayList[finalValue];
        // TODO [Start from here] Debug this function
        return 0;
    }
};
