#include "date_processer.hpp"

// TODO Add a date constructor to take in date and then change all parameters to just the date
bool DateProcesser::check_date_validity(std::string date){
    if(date.length() != 10){
        is_valid = false;
    }
    else if(date.substr(2, 1) != "/" || date.substr(5, 1) != "/"){
        is_valid = false;
    }
}

bool DateProcesser::check_year_validity(std::string year){
    // Check year validity 
        // Also check whether the year is a leap year

}

bool DateProcesser::check_month_validity(std::string month){
    // Check month validity
        // Also check what the last date is
}

bool DateProcesser::check_month_date_validity(std::string month_date){

    // Check date validity
            // Check the date is correct or not in comparison to the month
    
}