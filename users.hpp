#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

struct UserProcesing{
    json users;

    int read_json() {
        std::ifstream file;
        file.open("users.json");
        file >> users;
        file.close();
    }
};