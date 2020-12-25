#include "dependencies/json.hpp"
#include <fstream>
#include <iostream>

#pragma once

using json = nlohmann::json;

struct UserProcesingHelper{
    json users;

    UserProcesingHelper() {
        std::ifstream file_read("data/users.json");
        users = json::parse(file_read);
    }

    bool check_user(std::string user){
        if(users.find(user) != users.end()){
            return true;
        }
        else{
            return false;
        }
    }

    bool check_password(std::string user){
        std::cout << "Please enter your password: ";
        std::string password;
        std::cin >> password;
        std::string correct_password = users.value(user, "hello");

        if(correct_password == password){
            return true;
        }
        else{
            return false;
        }
    }

    void make_user(std::string user, std::string password){
        users[user] = password; 
        std::ofstream file_write("data/users.json");
        file_write << users;
        file_write.close();

        std::ifstream file_reread("data/users.json");
        users = json::parse(file_reread);
        file_reread.close();
    }

};
