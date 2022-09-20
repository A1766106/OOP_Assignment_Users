#include "Share.h"
#include "User.h"
#include "Investor.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;


int main()
{   
    system("Clear"); // Clears terminal
    cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  " << endl;
    cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. | " << endl;
    cout << "| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | | " << endl;
    cout << "| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | | " << endl;
    cout << "| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | | " << endl;
    cout << "| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |  " << endl;
    cout << "| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | | " << endl;
    cout << "| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | | " << endl;
    cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  " << endl;
    cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  " << endl;
    cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   " << endl << endl; // Output welcome message

    string Confirmation = ""; // Initialises confirmation
    cout << "Please enter \'I\' if you are an Investor or \'B\' if you are a Broker: "; // Requests input from user clarrifying if user is investor or broker
    cin >> Confirmation;
    while(Confirmation != "i" && Confirmation != "I" && Confirmation != "b" && Confirmation != "B") // Confirms valid entry
    {
        cout << "You entered an invalid character! Please enter \'I\' if you are an Investor or \'B\' if you are a Broker: ";
        cin >> Confirmation; 
    }
    if(Confirmation == "i"|| Confirmation == "I") // Enters if statement if investor
    {   
        cout << "You have selected Investor" << endl;
        string Existing_Account = "";
        cout << "Do you have an existing account? (Y/N) "; // Gathers input to determine if user has own account
        cin >> Existing_Account;
        while(Existing_Account != "y" && Existing_Account != "Y" && Existing_Account != "n" && Existing_Account != "N") // Confirming valid entry
        {
            cout << "You entered an invalid character! Do you have an existing account? (Y/N) ";
            cin >> Existing_Account;
        }
        if(Existing_Account == "n" || "N") // Creates account if investor doesnt already have account
        {
            system("Clear");
            cout << "Let's create an account! " << endl;;
            Investor End_User;
        }
        else // Investor logs into account if investor has account
        {
            int Entered_ID;
            cout << "Please enter your ID Number to login: ";
            cin >> Entered_ID;
            Investor End_User(Entered_ID);
        }
    }

    cout << "Thanks for running this simulator!" << endl;
    return 0;
}