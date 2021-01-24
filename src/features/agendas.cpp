#include "agendas.hpp"

using json = nlohmann::json;

AgendaHelper::AgendaHelper() {
    // Open a file stream to read file
    std::ifstream file_read;
    file_read.open("src/data/agendas.json");
    // Checks if file doesn't exist
    if(!file_read) {
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

std::string AgendaHelper::make_agenda(std::string agenda_text, std::string username, std::string date, std::string month, std::string year) {
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
std::string AgendaHelper::get_agenda( std::string username, std::string date, std::string month, std::string year) {
    // Enclosed in try block because json header throws and exits
    try {
        std::string agenda_text = agenda[username][year][month][date];
        return agenda_text;
    }
    catch(std::exception& e) {
        return "No agenda for this day.";
    }
}



Agenda::Agenda(std::string username) : username {new std::string(username)} {}

Agenda::~Agenda() {
    delete helper;
    delete username;
}

void Agenda::menu() {
    do {
        std::cout << "Welcome to Agendas!\n[1] Add Agendas\n[2] Check Agenda\nResponose: ";

        std::string response;
        std::cin >> response;

        // When response is to add agendas
        if(response == "1") {
            // Add Agenda Front End
            // Ask if you want to do something else
            break;
        }

        // When response is to check agendas
        if(response == "2") {
            // Check Agenda Front End
            // Ask if you want to do something else
            break;
        }

        // For any thing other than this the loop should keep repeating

    }
    while(true);
}

void Agenda::add_agenda() {
    while(true) {
        std::cout << "Please enter date of agenda[DD/MM/YYYY]";
        std::string date;
        std::cin >> date;
        DateProcesser date_processer{date};
        if(date_processer.check()) {
            std::cout << "Invalid date";
        }
    }

    // Check if agenda already exists for that day and ask to overwrite it
    // Take in agenda text and write it
}
