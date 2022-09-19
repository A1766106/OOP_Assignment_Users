#include "Share.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Share::Share()
{
    Code = "N/A";
    Company = "N/A";
    Sector = "N/A";
}

Share::Share(std::string Code)
{
    this->Code = Code;
    Set_Details(Code);
}

std::string Share::Get_Code()
{
    return Code;
}
std::string Share::Get_Company()
{
    return Company;
}
std::string Share::Get_Sector()
{
    return Sector;
}
void Share::Set_Details(string Code)
{
    ifstream CompanyList;
    CompanyList.open("ASX_Companies.csv");
    if(!CompanyList.is_open()){
        Company = "N/A";
        Sector = "N/A";
        cout << "File Failed To Open" << endl;
    }
    
    string Temp_Code;
    string Temp_Company;
    string Temp_Sector;
    string line;

    while(getline(CompanyList, line)){
        stringstream ss(line);
        getline(ss, Temp_Code, ',');
        getline(ss, Temp_Company, ',');
        getline(ss, Temp_Sector, ',');
        if(Temp_Code == Code)
        {
            Company = Temp_Company;
            Sector = Temp_Sector;
            break;
        }
    }
    CompanyList.close();
}


Share::~Share(){}
