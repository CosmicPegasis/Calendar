#include <iostream>
#include "calendar.hpp"

void introduceApp();

int main(){
    introduceApp();
    YearCalendar calendar;
    calendar.printYear(2025);
}

// Introduces the app
void introduceApp(){
    std::cout << "Welcome To Calendar!" << "\nThis is the number one calendar program in the universe!" << std::endl;
}

// TODO [Start from here] Take user input
