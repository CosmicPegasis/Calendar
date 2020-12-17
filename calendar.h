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

        while(year < 17) {
            year = year + 4;
        }

        while (year > 20) {
            year = year - 4;
        }
    }

    CalendarHelper(){
        std::map<int, int> yearList = {
            {20, 6},
            {19, 0},
            {18, 2},
            {17, 4}
        };
    }
};