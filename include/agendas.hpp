#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "date_processer.hpp"


#pragma once
// Store data in a file
// Add agendas
// Add a help statement


// Base class
struct AgendaHelper {
    // Make json var using json header file
    nlohmann::json agenda;

    AgendaHelper();

    // Internal function to make agendas
    std::string make_agenda(std::string agenda_text, std::string username, std::string date, std::string month, std::string year);

    // Internal function to get agenda for a fixed date
    std::string get_agenda( std::string username, std::string date, std::string month, std::string year);

};


struct Agenda {
    // Constructor that accepts username
    const std::string* username;
    AgendaHelper* helper = new AgendaHelper();

    Agenda(std::string username);

    ~Agenda();

    // Make a menu system
    void menu();

    // Front end to add agendas
    void add_agenda();
    // Front end to retrieve agendas
    void check_agenda();
};
