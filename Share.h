#ifndef SHARE_H
#define SHARE_H
#include <iostream>
#include <string>

class Share
{
    protected:
        std::string Code;
        std::string Company;
        std::string Sector;
    public:
        Share(); // Default Constructor
        Share(std::string Code); // Constructor
        std::string Get_Code(); // Function that returns Company Code
        std::string Get_Company(); // Function that returns Company Name
        std::string Get_Sector(); // Function that returns Company Sector
        void Set_Details(std::string Code); // Function that sets Company Name and Industry from CVS file
        ~Share();     
};

#endif