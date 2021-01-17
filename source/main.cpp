#include <iostream>
#include <fstream>

bool does_file_exist(const std::string& file_name)
{
    std::ifstream file(file_name);
    if(!file.is_open())
        return false;
    else
    {
        file.close();
        return true;
    }
}

int main()
{
    std::cout << "simple LR system\n";
    std::cout << "type in a command...\n";
    std::string input = "";
    std::cin >> input;

    if(input == "register")
    {

        std::string name = "", password = "";
        std::cout << "type in a new user name\n";
        std::cin >> name;

        name += ".data";

        if(does_file_exist(name))
        {
            std::cout << "user already exists\n";
            return 1;
        }
        
        std::cout << "type in a password for user\n";
        std::cin >> password;

        std::ofstream file(name);
        if(!file.is_open())
        {
            std::cout << "something went wrong when creating user data\n";
            return 1;
        }

        file << password;
        file.close();
        std::cout << "user created\n";
    }
    else if(input == "login")
    {
        std::string name = "", password = "";
        std::cout << "type in a username\n";
        std::cin >> name;

        name += ".data";

        if(!does_file_exist(name))
        {
            std::cout << "no such user exists\n";
            return 1;
        }

        std::cout << "type in the username's password\n";
        std::cin >> password;

        std::ifstream file(name);
        std::string user_password = "";
        file >> user_password;
        if(user_password != password)
        {
            std::cout << "invalid password\n";
            file.close();
            return 1;
        }

        std::cout << "login success\n";
        file.close();
    }
    else
    {
        std::cout << "uknown command\n";
    }

    return 0;
}