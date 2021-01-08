#include "user_interaction.hpp"
#include "users.hpp"
#include "calendar.hpp"

void interaction::introduceApp(){
        std::cout << "Welcome To Calendar!" << "\nThis is the number one calendar program in the universe!" << std::endl;
    }

void interaction::menu(){
    std::string response;
    do{
        std::cout << "Please select an option" << std::endl;
        std::cout << "[1] Print out the calendar for a year" << std::endl;
        std::cout << "[2] Check out your TODOs and agendas" << std::endl;
        std::cout << "Response: ";
        std::cin >> response;

        if(response == "1"){
            YearCalendar calendar;
            calendar.menu();
            break;

        }
        if(response == "2") {
            UserProcessing processor;
            processor.process();
            break;
        }
    }
    while(true);

}
