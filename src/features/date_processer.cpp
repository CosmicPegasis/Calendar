#include "date_processer.hpp"

// TODO Add a date constructor to take in date and then change all parameters to
// just the date
//
// TODO Add error messages and handle errors gracefully

// Idea on how to easily verify dates - use the prebuilt date
// caluclation from agendas and then match the return date to user given date.

DateProcesser::DateProcesser(std::string date)
    : date{date}, month_date{date.substr(0, 2)}, month{date.substr(3, 2)},
      year{date.substr(6, 4)} {}

void DateProcesser::check_date_validity() {
    if (date.length() != 10) {
        is_valid = false;
    } else if (date.substr(2, 1) != "/" || date.substr(5, 1) != "/") {
        is_valid = false;
    }
}

int DateProcesser::check_year_validity() {
    std::stringstream ss{year};
    int year;
    try {
        ss >> year;
    } catch (std::exception &e) {
        is_valid = false;
    }
    // Check year validity
    if (year < 1000 || year > 9999) {
        is_valid = false;
    }
    // Also check whether the year is a leap year
    else if (year % 4 == 0) {

    }
    return year;
}

int DateProcesser::check_month_validity() {
    // Check month validity
    std::stringstream ss{month};
    int month;
    try {
        ss >> month;
    }
    catch (std::exception &e) {
        is_valid = false;
    }
    if (month < 1 || month > 12) {
        is_valid = false;
    }
    return month;
}

int DateProcesser::check_month_date_validity(int month, int year) {
    // Check date validity
    std::stringstream ss{month_date};
    int month_date;
    try {
        ss >> month_date;
    }
    catch(std::exception &e) {
        is_valid = false;
    };

    if (month > 12 || month < 1) {
        is_valid = false;
    }
    else if (year > 9999 || year < 1000) {
        is_valid = false;
    }

    bool is_leap_year = false;
    int month_last_date;

    if(year % 4 == 0) {
        is_leap_year = true;
    }

    if(month == 2 && is_leap_year) {
        month_last_date = 29;
    }
    else if(month == 2) {
        month_last_date = 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        month_last_date = 30;
    }
    else {
        month_last_date = 31;
    }
    // Check the date is correct or not in comparison to the month

    if(month_date < 1 || month_date > month_last_date) {
        is_valid = false;
    }
    return month_date;
}

bool DateProcesser::check() {
    while(is_valid) {
        check_date_validity();
        int month = check_month_validity();
        int year = check_year_validity();
        check_month_date_validity(month, year);
        break;
    }
    return is_valid;
}
