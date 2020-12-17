#include <cmath>
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
        while(year < 17 )
    }
    )
}