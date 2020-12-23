#include "dependencies/json.hpp"
#include <fstream>
#include <iostream>

#pragma once

using json = nlohmann::json;

struct UserProcesingHelper{
    json users;

    void read_json() {
        std::ifstream file("users.json");
        users = json::parse(file);
    }

    bool check_user(std::string user){
        read_json();
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


};