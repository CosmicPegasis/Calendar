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

std::string DateProcesser::check_date_validity() {
    if (date.length() != 10) {
        is_valid = false;
    } else if (date.substr(2, 1) != "/" || date.substr(5, 1) != "/") {
        is_valid = false;
    }
}

void DateProcesser::check_year_validity() {
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
}

bool DateProcesser::check_month_validity() {
    // Check month validity
    std::stringstream ss;
    int month;
    try {
        ss >> month;
    }
    catch (std::exception &e) {
        is_valid = false;
    }
}

bool DateProcesser::check_month_date_validity() {

    // Check date validity
    // Check the date is correct or not in comparison to the month
}
