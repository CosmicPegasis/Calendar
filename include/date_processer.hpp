#include <iostream>
#include <sstream>

#pragma once

struct DateProcesser{
    DateProcesser(std::string date);

    void check_date_validity();

    bool check_month_date_validity();

    bool check_month_validity();

    bool check_year_validity();

    bool is_valid{true};
    const std::string date;
    const std::string month_date;
    const std::string month;
    const std::string year;
};
