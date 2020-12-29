#include <nlohmann/json.hpp>
#include <fstream>
// Store data in a file
// Add agendas 
// Add a help statement

using json = nlohmann::json;

struct AgendaHelper{
    json agenda;

    AgendaHelper(){
        std::ifstream file_read("../data/agendas.json");
        agenda = json::parse(file_read);
    }

    std::string make_agenda(std::string agenda_text, std::string username, int date, int month, int year){
        agenda[username][year][month][date] = agenda_text;
    
        return agenda_text;
    }
};