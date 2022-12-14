#include "Investor.h"
#include "User.h"
#include "Share.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

Investor::Investor()
{

    Cost_Base = 0;
    Share_Count = 0;
    Portfolio = new Share[20];
    Set_Details();

}
Investor::Investor(int User_ID)
{
    this->User_ID = User_ID;
    if(Check_ID(User_ID))
    {
        string Entered_Password = "";
        int Attempts = 0;
        while(Attempts < 3 && Check_Password(User_ID, Entered_Password))
        {
    //         cout << "Please enter your password: ";
    //         cin >> Entered_Password;
    //         if(Check_Password(User_ID, Entered_Password))
    //         {
    //             Set_Existing_Details(User_ID);
    //             break;
    //         }
    //         else
    //         {
    //             cout << "That password doesn't match the ID you selected! " << endl;
    //             Attempts++;
    //         }
    //         if(Attempts == 3)
    //         {
    //             cout << "You failed to get the password! Lets sign you in as guest instead! (Please note this is a public account) " << endl;
    //             this->User_ID = 0;
    //             this->User_Name = "Guest";
    //             this->User_Password = "";
    //             Cost_Base = 0;
    //             Share_Count = 0;
    //             Portfolio = new Share[20]; 


    //         }
        }
    }
}
int Investor::Get_Cost_Base()
{
    return Cost_Base;
}
void Investor::Change_Cost_Base(int Change)
{
    Cost_Base = Cost_Base + Change;
}
void Investor::Set_Broker(std::string Chosen_Broker)
{
    Investor_Broker = Chosen_Broker;
}
std::string Investor::Return_Broker()
{
    return Investor_Broker;
}
Share *Investor::Get_Portfolio()
{
    return Portfolio;
}
void Investor::Buy(string ASX_code, int Cost_Base)
{
    if(Share_Count<20)
    {
        Portfolio[Share_Count] = Share(ASX_code);
        Share_Count++;
        Change_Cost_Base(Cost_Base);
        cout << "Share added" << endl;
    }
    else
    {
        cout << "You have the maximum amount of shares" << endl;
    }
}
void Investor::Sell(string ASX_code)
{
    for(int i=0;i<20;i++)
    {
        if(ASX_code == Portfolio[i].Get_Code())
        {
            cout << "You sold " << ASX_code << endl;
            Portfolio[i] = Share();
        }
    }
    Share *Temp_Portfolio = new Share[20];
    int Temp_Counter = 0;
    for(int i=0;i<20;i++)
    {
        if (Portfolio[i].Get_Code() != "N/A")
        {
            Temp_Portfolio[Temp_Counter] = Portfolio[i];
            Temp_Counter++;
        }
    }
    Portfolio = Temp_Portfolio;

}

bool Investor::Check_For_ID_Duplicate(int ID)
{
    ifstream Accounts;
    Accounts.open("Accounts.csv");
    string line;
    int Temp_ID;
    string myID;
    while(getline(Accounts, line))
    {
        stringstream ss(line);
        getline(ss,myID,',');
        Temp_ID = stoi(myID);
        if(Temp_ID == ID)
        {
          return false;
        }
    }
    Accounts.close();  
    return true;
    

}

void Investor::Set_Details()
{
    cout << "Please enter user name: ";
    cin >> User_Name;
    cout << "Please enter User ID: ";
    cin >> User_ID;
    while(!Check_For_ID_Duplicate(User_ID))
    {
        cout << "You entered the ID of an already existing account! Please enter a different User ID: ";
        cin >> User_ID;
    }
    string Chosen_broker;
    cout << "What is your Brokers name: ";
    cin >> Chosen_broker;
    cout << "Please enter your password: ";
    cin >> User_Password;

    this->User_Name = User_Name;
    this->User_ID = User_ID;
    this->User_Password = User_Password;
    Investor_Broker = Chosen_broker;

    ofstream Accounts;
    Accounts.open("Accounts.csv", fstream::app);
    Accounts << this->User_ID << "," << this->User_Password << "," << this->User_Name << "," << this->Investor_Broker << ",,,\n";
    Accounts.close();
}
void Set_Existing_Details(int Entered_ID)
{
    cout << "Green Light" << Entered_ID << endl;;
}

bool Check_ID(int Entered_ID)
{
    return true;
}

bool Investor::Check_Password(int Entered_ID, std::string Entered_Password)
{
    return false;
}

Investor::~Investor(){}