#include "date_processer.hpp"

// TODO Add a date constructor to take in date and then change all parameters to just the date
// Idea on how to easily verify dates - use the prebuilt date caluclation from agendas and then match the return date to user given date.

bool DateProcesser::DateProcesser(std::string date){
	this->date = date;
	date.substr(0, 2) = month_date;
	date.substr(3, 2) = month;
	date.substr(6, 4) = year;
	date.

}

bool DateProcesser::check_date_validity(){
    if(date.length() != 10){
        is_valid = false;
    }
    else if(date.substr(2, 1) != "/" || date.substr(5, 1) != "/"){
        is_valid = false;
    }
}

bool DateProcesser::check_year_validity(){
    // Check year validity 
        // Also check whether the year is a leap year

}

bool DateProcesser::check_month_validity(){
    // Check month validity
        // Also check what the last date is
}

bool DateProcesser::check_month_date_validity(){

    // Check date validity
            // Check the date is correct or not in comparison to the month
    
}
