/*  BusinessService.hpp
class for business type services such as media, tech, general office, logistics etc.
All business sellers pay a transaction fee of 8% */

#ifndef BusinessService_hpp
#define BusinessService_hpp

#include "Service.hpp"

class BusinessService: public Service
{
  public:
    BusinessService(string, string, string, double, double, int, bool, string = ""); //constructor
    void setBusinessType(string); //setter
    void addBusService(); //user sets object attributes manually
    string getBusinessType(); //getter
    double getFeePercentage(); //getter
    double calculateFee(); //calculate the fee per sale
  
    //print
    void printBusiness();
    
  private:
    string businessType; //The type of business being offered (media services, secretary, accounting, etc)
    const double feePercentage = 8;
};

#endif