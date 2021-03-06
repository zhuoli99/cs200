//  PersonalService.cpp
#include <iostream>
#include <iomanip>
using namespace std;

#include "PersonalService.hpp"
#include "Service.hpp"

//constructor
PersonalService::PersonalService(){}
PersonalService::PersonalService(string n, string des, string l, double dur, double p, bool a, bool c, string b): Service(n, des, l, dur, p, a)
{
    hasLicense = c;
    language = b;
}

//setters
void PersonalService::setLicense(bool x)
{
    hasLicense = x;
}//setLicense
void PersonalService::setLanguage(string x)
{
    language = x;
}//setLanguage
void PersonalService::addPerService()
{
    char y;
    string w;
    Service::addService();
    while (true)
    {
        cout << "Are you licensed to provide this service (if applicable) Y/N? ";
        cin >> y;
        if (toupper(y) == 'Y' || toupper(y) == 'N')
        {
            if (toupper(y) == 'Y') setLicense(true);
            else if (toupper(y) == 'N') setLicense(false);
            break;
        }//if
        else cout << endl << "Please enter 'Y' for yes or 'N' for no. If not applicable, please enter 'N'. " << endl << endl;
    }//while
    cout << "Please list all languages accommodated: ";
    getline(cin, w); cin.ignore(1000, 10);
    setLanguage(w);
    cout << "Please hit enter to make this service available, or type 'cancel', followed by the enter key to set your service to unavailable." << endl;    getline(cin, w); cout << endl;
    if (w == "cancel") Service::setAvail(false);
    else Service::setAvail(true);
    cout << "MAIN MENU" << endl;
}//addPerService

//getters
map<string, string> PersonalService::toSave() const{
    map<string, string> PersonalService = Service::toSave(); //get base class data
    PersonalService["HasLicense"] = to_string(hasLicense);
    PersonalService["Language"] = language;
    return PersonalService;
}

map<string, string> PersonalService::toCreate() {
    map<string, string> PersonalTable = Service::toCreate(); //get base class data
    PersonalTable["HasLicense"] = "bool";
    PersonalTable["Language"] = "string";
    return PersonalTable;
}

bool PersonalService::getLicense()
{
    return hasLicense;
}//getLicense
string PersonalService::getLanguage()
{
    return language;
}//getLanguage

//print
void PersonalService::printSpecialService() const
{
    //Service::printService();
    cout << "Licensed: " << (hasLicense == true ? "Yes" : "No") << endl;
    cout << "Language(s): " << language << endl << endl;
}//printPersonalService
