//header file for DriversLicenseRecord

#ifndef DriversLicenseRecord_H
#define DriversLicenseRecord_H
#include <string>
using namespace std;

class Drivers
{
    private:
    string firstName;
    string lastName;
    int m_age;
    char voter;
    int licenseNum;
    
    public:
    Drivers();
    void setFirstName(string first);
    void setLastName(string last);
    void setAge(int age);
    void setVoteStat(char stat);
    void setLicenseNum(int licNum);
    string getFirstName();
    char getFirstChar(string firstName);
    string getLastName();
    int getAge();
    char getVoteStat();
    int getLicenseNum();
};
#endif