//class file to define the DriversLicenseRecord class and to store data that is 
//taken in from the DMV class

#include "DriversLicenseRecord.h"
using namespace std;

Drivers::Drivers()
{
    string firstName = "";
    string lastName = "";
}

void Drivers::setFirstName(string first)
{
    firstName = first;
}

void Drivers::setLastName(string last)
{
    lastName = last;
}
void Drivers::setAge(int age)
{
    m_age = age;
}
void Drivers::setVoteStat(char stat)
{
    voter = stat;
}
void Drivers::setLicenseNum(int licNum)
{
    licenseNum = licNum;
}
string Drivers::getFirstName()
{
    return(firstName);
}
char Drivers::getFirstChar(string firstName)
{
    return(firstName[0]);
}
string Drivers::getLastName()
{
    return(lastName);
}
int Drivers::getAge()
{
    return(m_age);
}
char Drivers::getVoteStat()
{
    return(voter);
}
int Drivers::getLicenseNum()
{
    return(licenseNum);
}