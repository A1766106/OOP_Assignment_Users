#include "User.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

User::User()
{
    User_Name = "Guest";
    User_ID = 0;
    User_Password = "";
}

User::User(std::string User_Name, int User_ID, std::string User_Password)
{
    this->User_Name = User_Name;
    this->User_ID = User_ID;
    this->User_Password = User_Password;
}

bool User::Password_Check(std::string User_Password)
{
    if(this->User_Password == User_Password)
    {
        return true;
    }
    return false;
}

void User::Set_Password(std::string User_Password)
{
    this->User_Password = User_Password;
}

void User::Set_User_ID(int User_ID)
{
    this->User_ID = User_ID;
}

void User::Set_User_Name(std::string User_Name)
{
    this->User_Name = User_Name;
}
int User::Get_User_ID()
{
    return User_ID;
}

std::string User::Get_User_Name()
{
    return User_Name;
}