#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <stdlib.h>

class User
{
    protected:
        std::string User_Name;
        int User_ID;
        std::string User_Password;

    public:
        User(); // Default constructor
        User(std::string User_Name, int User_ID, std::string User_Password); // Constructor
        bool Password_Check(std::string User_Password); // Checks if password matches user given password
        void Set_Password(std::string User_Password); // Sets Password for user
        void Set_User_ID(int User_ID); // Sets ID for user
        void Set_User_Name(std::string User_Name); // Sets Name for user
        int Get_User_ID(); // Gets user ID
        std::string Get_User_Name(); // Gets user name
};

#endif