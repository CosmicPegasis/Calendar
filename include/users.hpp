#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#pragma once

struct UserProcesingHelper {
    nlohmann::json users;

    UserProcesingHelper();

    bool check_user(std::string user, nlohmann::json users);

    bool check_password(std::string user, nlohmann::json users);

    void make_user(std::string user, std::string password);
};

struct UserProcessing {
    std::string process();

    std::string get_username();

    std::string intro();

    bool process_password(bool is_user, std::string username, UserProcesingHelper helper, nlohmann::json users);

    nlohmann::json make_user_menu(UserProcesingHelper helper);
};
