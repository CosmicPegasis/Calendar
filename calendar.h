#include <cmath>
#pragma once

struct Calendar{
    void print(int month,int year){
       // Formatting 
    }

    int caluclateFirstDay(int year){
        int lastTwoDaysOfYear = year % 100;
        float beforeAddingMonthValue = floor(lastTwoDaysOfYear/4);
        // Finish function
    }
};