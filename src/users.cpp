#include "users.hpp"
using json = nlohmann::json;

UserProcesingHelper::UserProcesingHelper(){
        std::ifstream file_read("src/data/users.json");
        if(!file_read){
            file_read.close();

            std::ofstream file_make;
            file_make.open("src/data/users.json");
            file_make << "{}";
            file_make.close();

            file_read.open("src/data/users.json");
            
        }
        users = json::parse(file_read);
        file_read.close();
}

bool UserProcesingHelper::check_user(std::string user, json users){
        if(users.find(user) != users.end()){
            return true;
        }
        else{
            return false;
        }
    }
bool UserProcesingHelper::check_password(std::string user, json users){
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

void UserProcesingHelper::make_user(std::string user, std::string password){
        users[user] = password; 
        std::ofstream file_write("data/users.json");
        file_write << users;
        file_write.close();
    }

void UserProcessing::process(){
        UserProcesingHelper helper;
        json users = helper.users;
        do{
            std::string response = intro();
            if(response == "1"){
                // Ask Credentials 
                std::string username = get_username();

                bool is_user;
                is_user = helper.check_user(username, users);
                bool authentication_sucessful;
                authentication_sucessful = process_password(is_user, username, helper, users);

                if(authentication_sucessful){
                    break;
                }
            }
            if(response == "2") {
                users = make_user_menu(helper);
            }
        // TODO Write function to end program anytime
        }
                
                    // Ask for username and password
        while(true);
        
        // return the username and password to display things like agenda and todo lists

    }
std::string UserProcessing::get_username(){
    std::cout << std::endl << "Please enter username: ";
    std::string username;
    std::cin >> username;

    return username;
}
std::string UserProcessing::intro(){
        // Ask what to do
        std::cout << "Welcome!" << std::endl;
            // User log in
        std::cout << "[1] Log In" << std::endl;
            // Make a new user
        std::cout << "[2] Make New User" << std::endl;
            // Quit
        std::cout << "[3] Quit" << std::endl;

        std::string response;
        std::cin >> response;

        return response;
    }
bool UserProcessing::process_password(bool is_user, std::string username, UserProcesingHelper helper, json users){
    if(is_user) {
        do{
            // Verify Credentials
            // Existent user ask for password
            bool is_correct_password = helper.check_password(username, users);

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
        return true;
    }
    else{
        std::cout << "This user does not exist." << std::endl;
        return false;
    }
}

json UserProcessing::make_user_menu(UserProcesingHelper helper){
    // Non existent user -- Ask to make a new one
    std::string username;
    std::string password;

    std::cout << "Please enter username: ";
    std::cin >> username;
    std::cout << std::endl << "Please enter password: ";
    std::cin >> password;
    
    helper.make_user(username, password);
    std::cout << "Your user has been created. Go ahead and sign in!" << std::endl;

    return helper.users;
    
}