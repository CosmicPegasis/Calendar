#include "date_processer.hpp"

bool DateProcesser::check_date_validity(std::string date){
    if(date.length() != 10){
        return false;
    }
}

bool DateProcesser::check_year_validity(std::string year){
    // Check year validity 
        // Slice the year part from the string
        // Also check whether the year is a leap year

}

bool DateProcesser::check_month_validity(std::string month){
    // Check month validity
        // Slice month part from the code 
        // Also check what the last date is
}

bool DateProcesser::check_month_date_validity(std::string month_date){

    // Check date validity
        // Index the first two digits
            // Convert to int
            // Check the date is correct or not in comparison to the month
    
}