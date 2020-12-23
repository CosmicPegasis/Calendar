#include <iostream>
#include "calendar.hpp"

#pragma once

namespace interaction{

    // Introduces the app
    void introduceApp(){
        std::cout << "Welcome To Calendar!" << "\nThis is the number one calendar program in the universe!" << std::endl;
    }

    void menu(){
        int response;
        bool menu_running;
        do{
            std::cout << "Please select an option" << std::endl;
            std::cout << "[1] Print out the calendar for a year" << std::endl;
            std::cout << "Response: ";
            std::cin >> response;

            if(response == 1){
                YearCalendar calendar;
                calendar.menu();
                menu_running = false;

            }
            else{
                menu_running = true;
            }
        }
        while(menu_running == true);

    }

}