#include <iostream>
#include <sstream>

#pragma once

struct DateProcesser {
    DateProcesser(std::string date);

    void check_date_validity();

    void check_month_date_validity(int month, int year);

    int check_month_validity();

    int check_year_validity();

    bool is_valid{true};
    const std::string date;
    const std::string month_date;
    const std::string month;
    const std::string year;
};
