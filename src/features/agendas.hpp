#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#pragma once
// Store data in a file
// Add agendas 
// Add a help statement

using json = nlohmann::json;

struct AgendaHelper{
    json agenda;

    AgendaHelper(){
        std::ifstream file_read;
        file_read.open("src/data/agendas.json");
        agenda = json::parse(file_read);
        file_read.close();
    }

    std::string make_agenda(std::string agenda_text, std::string username, int date, int month, int year){
        agenda[username] = {year, {month, {date, agenda_text}}};
        std::ofstream file_write;
        file_write.open("src/features/agendas.json");
        file_write << agenda;
        file_write.close();
    
        return agenda_text;
    }
};