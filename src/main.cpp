#include <iostream>
#include "user_interaction.hpp"


// TODO Change json objects to pointer as they might cause stack overflow
// TODO Make wrapper for AgendaHelper
// TODO Set required functions to const

int main(){
    interaction::introduceApp();
    interaction::menu();
}

