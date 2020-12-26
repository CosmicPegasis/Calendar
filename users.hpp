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

// TODO Refactor entire class
struct UserProcessing{
    void process(){
        UserProcesingHelper helper;
        do{
            // Ask what to do
            std::cout << "Welcome!" << std::endl;
                // User log in
            std::cout << "[1] Log In" << std::endl;
                // Make a new user
            std::cout << "[2] Make New User" << std::endl;

            std::string response;
            std::cin >> response;
            
            if(response == "1"){
                // Ask Credentials 
                std::cout << std::endl << "Please enter username: ";
                std::string username;
                std::cin >> username;

                bool is_user = helper.check_user(username);
                if(is_user) {
                    do{
                        // Verify Credentials
                        // Existent user ask for password
                        bool is_correct_password = helper.check_password(username);

                        if(is_correct_password){
                            std::cout << "Hello! " << username;
                            break;
                        }

                        else{
                            std::cout << "Incorrect Password!";
                            continue;
                        }
                    } 
                    while(true);
                    // TODO Continue from here -- Make case for when user doesn't exist
                }
            }
        }
                        // Non existent user -- Ask to make a new one
                
                    // Ask for username and password
        while(true);
        
        // return the username and password to display things like agenda and todo lists

    }
};
