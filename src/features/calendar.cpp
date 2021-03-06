#include "calendar.hpp"

int YearCalendarHelper::getYearCode(int year){
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

int YearCalendarHelper::caluclateFirstDay(int year){
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
    int finalValue;
    if(1 < afterYearCode && afterYearCode < 7){
        finalValue =  7 - afterYearCode;
    }
    else if(afterYearCode == 1){
        finalValue = 2; // Arbitrary because of algorithm used
    }
    else{
        finalValue = (afterYearCode + lastTwoDigitsOfYear) % 7;
    }

    // Gives back the first day
    return dayList[finalValue];
}


void YearCalendar::printDays(){
    std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;
}
int YearCalendar::printMonthCalendar(int monthNum, int startDay, bool isLeapYear){
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
    // Calculates the first day of next month
    int firstDayNextMonth = remainingDays % 7;

    // Print out all the dates
    for(int i{0}; i <= remainingDays - 1; i++){
        // Makes out date from i
        int date = i + totalDatesInFirstRow + 1;
        // if i is single digit and at the end of the week
        if(i > 7 && i % 7 == 0 && date < 10){
            std::cout << std::endl << "  " << date << "   ";

        }
        // special case for when week ends on 8
        else if(i == 7 && i % 7 == 0 && date == 9){
            std::cout << std::endl << "  " << date << "  ";

        }
        // if i is double digit and at the end of the week
        else if(i >= 7 && i % 7 == 0 && date >= 10){
            std::cout << std::endl << " " << date << "  ";
        }
        // if i is a week day and single digit
        else if(date + 1 < 10){
        std::cout << date << "   ";
        }
        // if i is a week day and double digit
        else if(date + 1 >= 10){
            std::cout << date << "  ";
        }

    }
    std::cout << std::endl;
    // returns the first day of next month to put back in this function
    return firstDayNextMonth;
}

void YearCalendar::printYear(int year){
    bool isLeapYear = false;
    YearCalendarHelper helper;
    // Calculates the first day of the year
    int firstDay = helper.caluclateFirstDay(year);

    // Checks if given year is leap
    if(year % 4 == 0){
        isLeapYear = true;
    }

    // Prints out Jan
    std::cout << "\t  " << helper.monthList[1] << "\n";
    // Prints out all the dates of Jan
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

void YearCalendar::menu(){
    int year;
    bool menu_running;
    std::string response;
    do {
        std::cout << "Which year would you like to print?[Enter year number]: ";
        std::cin >> year;

        printYear(year);
        std::cout << std::endl;

        std::cout << "Would you like to print out another year?(Y/n) ";
        std::cin >> response;
        if(response == "n"){
            menu_running = false;
        }
        else{
            menu_running = true;
        }
    }
    while(menu_running);

}