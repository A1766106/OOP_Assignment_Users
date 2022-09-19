#ifndef INVESTOR_H
#define INVESTOR_H
#include "User.h"
#include "Share.h"
#include <iostream>
#include <string>
#include <stdlib.h>

class Investor: public User
{
    protected:
        Share *Portfolio; // This will need to be changed to include currencies as well
        int Cost_Base;
        int Share_Count;
        std::string Investor_Broker;
    public:
        Investor(); // Default which is called when user doesnt have account
        Investor(std::string User_Name, int User_ID, std::string User_Password, std::string Investor_Broker); // Constructor
        int Get_Cost_Base(); // Returns cost base
        void Change_Cost_Base(int Change); // Increases or decreases cost base
        void Set_Broker(std::string Chosen_Broker); // Sets broker
        std::string Return_Broker(); // Function that returns broker
        Share *Get_Portfolio(); // Functions return broker
        void Buy(std::string ASX_code, int Cost_Base); // Investor buys stock
        void Sell(std::string ASX_code); // Investor sells stock
        bool Check_For_ID_Duplicate(int ID); // Checks for duplicate ID's when creating account
        void Set_Details(); // Sets details for new accounts
        ~Investor();
};


#endif