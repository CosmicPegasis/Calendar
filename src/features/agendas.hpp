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
        if(!file_read){
            file_read.close();

            std::ofstream file_make;
            file_make.open("src/data/agendas.json");
            file_make << "{}";
            file_make.close();

            file_read.open("src/data/agendas.json");
            
        }
        agenda = json::parse(file_read);
        file_read.close();
    }

    std::string make_agenda(std::string agenda_text, std::string username, std::string date, std::string month, std::string year){
        agenda[username][year][month][date] = agenda_text;
        std::ofstream file_write;
        file_write.open("src/data/agendas.json");
        file_write << agenda;
        file_write.close();
    
        return agenda_text;
    }

    std::string get_agenda( std::string username, std::string date, std::string month, std::string year) {
        try{
        std::string agenda_text = agenda[username][year][month][date];
        return agenda_text;
        }
        catch(std::exception& e) {
            return "No agenda for this day.";
        }
    }
};