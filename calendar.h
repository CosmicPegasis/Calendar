#include <map>
#include <cmath>
#include <string>

#pragma once

struct Calendar{
    void print(int month,int year){
       // Formatting 
    }

    int caluclateFirstDay(int year){
        int lastTwoDatesOfYear = year % 100;
        float beforeAddingMonthValue = floor(lastTwoDatesOfYear/4) + 1;

        if(lastTwoDatesOfYear % 4 == 0.0) {
            int afterMonthValue = beforeAddingMonthValue; 
        }
        else{
            int afterMonthValue = beforeAddingMonthValue + 1;
        }
        // Finish function
    }
};

struct CalendarHelper{
    int calculateYear(int year){
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

        // TODO [Continue From Here] Use yearList map to return the year code

    }

};