#include <iostream>

#pragma once

struct DateProcesser{
    bool check_date_validity(std::string date);

    bool check_month_date_validity(std::string month_date);

    bool check_month_validity(std::string month);

    bool check_year_validity(std::string year);
};