//  PersonalService.hpp
#ifndef PersonalService_hpp
#define PersonalService_hpp

#include "Service.hpp"

class PersonalService: public Service
{
public:
    //constructor
    PersonalService();
    PersonalService(string, string, string, double, double, bool, bool = false, string = "English");
    
    //getters
    string dataTitle() const{return "PersonalService";}
    map<string, string> toSave() const;
    static map<string, string> toCreate();//for sqlitedata
    
    bool getLicense();
    string getLanguage();
    
    //setters
    void setLicense(bool);
    void setLanguage(string);
    void addPerService();
    
    //print
    void printSpecialService() const;
    
private:
    bool hasLicense;
    string language;
};

#endif
