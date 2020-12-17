#include <iostream>
#include "calendar.hpp"

void introduceApp();

int main(){
    introduceApp();
    YearCalendar calendar;
    calendar.caluclateFirstDay(2019);
}

// Introduces the app
void introduceApp(){
    std::cout << "Welcome To Calendar!" << "\nThis is the number one calendar program in the universe!";
}
