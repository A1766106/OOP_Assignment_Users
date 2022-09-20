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
        Investor(int User_ID); // Constructor
        int Get_Cost_Base(); // Returns cost base
        void Change_Cost_Base(int Change); // Increases or decreases cost base
        void Set_Broker(std::string Chosen_Broker); // Sets broker
        std::string Return_Broker(); // Function that returns broker
        Share *Get_Portfolio(); // Functions return broker
        void Buy(std::string ASX_code, int Cost_Base); // Investor buys stock
        void Sell(std::string ASX_code); // Investor sells stock
        bool Check_For_ID_Duplicate(int ID); // Checks for duplicate ID's when creating account
        void Set_Details(); // Sets details for new accounts as per user inputs
        void Set_Existing_Details(int Entered_ID); // Sets details for already existing user per csv file
        bool Check_ID(int Entered_ID); // Checks if given ID is an existing user
        bool Check_Password(int Entered_ID, std::string Entered_Password); // Checks if entered password matches user ID
        ~Investor();
};


#endif