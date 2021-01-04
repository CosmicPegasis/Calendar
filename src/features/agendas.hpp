#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#pragma once
// Store data in a file
// Add agendas 
// Add a help statement

using json = nlohmann::json;

// Base class
struct AgendaHelper{
    // Make json var using json header file
    json agenda;

    AgendaHelper(){
        // Open a file stream to read file
        std::ifstream file_read;
        file_read.open("src/data/agendas.json");
        // Checks if file doesn't exist
        if(!file_read){
            // Closes file to avoid corruption
            file_read.close();

            // Opens new stream to write empty json var to new file
            std::ofstream file_make;
            file_make.open("src/data/agendas.json");
            file_make << "{}";
            file_make.close();

            // Reopens the file
            file_read.open("src/data/agendas.json");
            
        }
        // Parse the file
        agenda = json::parse(file_read);
        file_read.close();
    }

    // Internal function to make agendas
    std::string make_agenda(std::string agenda_text, std::string username, std::string date, std::string month, std::string year){
        // Assigns agenda
        agenda[username][year][month][date] = agenda_text;
        // Writes entire json var to file
        std::ofstream file_write;
        file_write.open("src/data/agendas.json");
        file_write << agenda;
        file_write.close();
    
        // Returns the agenda_text for uniformity and testing
        return agenda_text;
    }

    // Internal function to get agenda for a fixed date
    std::string get_agenda( std::string username, std::string date, std::string month, std::string year) {
        // Enclosed in try block because json header throws and exits
        try{
        std::string agenda_text = agenda[username][year][month][date];
        return agenda_text;
        }
        catch(std::exception& e) {
            return "No agenda for this day.";
        }
    }
};

// TODO [Continue from here] Write AgendaHelper wrapper