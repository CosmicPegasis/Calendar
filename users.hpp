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
            std::string response = intro();
            if(response == "1"){
                // Ask Credentials 
                std::string username = get_username();

                bool is_user = helper.check_user(username);
                bool authentication_sucessful;
                authentication_sucessful = process_password(is_user, username, helper);

                if(authentication_sucessful){
                    break;
                }
            }
        }
                        // Non existent user -- Ask to make a new one
                
                    // Ask for username and password
        while(true);
        
        // return the username and password to display things like agenda and todo lists

    }
    std::string get_username(){
        std::cout << std::endl << "Please enter username: ";
        std::string username;
        std::cin >> username;

        return username;
    }
    std::string intro(){
        // Ask what to do
        std::cout << "Welcome!" << std::endl;
            // User log in
        std::cout << "[1] Log In" << std::endl;
            // Make a new user
        std::cout << "[2] Make New User" << std::endl;
            // Quit
        std::cout << "[3] Quit";

        std::string response;
        std::cin >> response;

        return response;
    }
    bool process_password(bool is_user, std::string username, UserProcesingHelper helper){
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
                        std::cout << "Incorrect Password!" << std::endl;
                        continue;
                    }
                } 
                while(true);
                // TODO Continue from here -- Make case for when user doesn't exist
                return true;
            }
            else{
                std::cout << "This user does not exist." << std::endl;
                return false;
            }
    }
};
