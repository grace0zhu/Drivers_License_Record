//Class file that prints a menu for the user, takes in and validates 
//user input, reads in driver info from a file, prints info of user's choosing
//and writes to the input file to register voters if needed

//file IO
    //loop that passes info to Record - call setters
//array created
    //one array size 55 including all Drivers
    //in Record, setters will take in values passed in via parameters
//in DMV public varaibles and methods to do stuff
    //array accessing
#include "DMV.h"
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

DMV::DMV(string filename)
{
    this->filename = filename;
    string firstName;
    string lastName;
    int age;
    char voter;
    int licenseNum;
    fstream records;
    records.open(filename);
    records >> size;

    driverRecord = new Drivers[size];

    for(int i=0; i<size; i++)
    {
        records >> licenseNum;
        driverRecord[i].setLicenseNum(licenseNum);

        records >> firstName;
        driverRecord[i].setFirstName(firstName);

        records >> lastName;
        driverRecord[i].setLastName(lastName);

        records >> age;
        driverRecord[i].setAge(age);

        records >> voter;
        driverRecord[i].setVoteStat(voter);
    }
    records.close();
}

void DMV::printMenu()
{
    cout << "Select an option:" << endl;
    cout << "1) Print all Drivers Info" << endl;
    cout << "2) Print all senior, unregistered voters" << endl;
    cout << "3) Print drivers by first initial" << endl;
    cout << "4) Print driver with id" << endl;
    cout << "5) Register to vote" << endl;
    cout << "6) Quit" << endl;
    cout << "Enter your choice: "; 
}

void DMV::AllInfo()
{
    for(int i=0; i<size; i++)
    {
        cout << driverRecord[i].getLastName() << ", ";
        cout << driverRecord[i].getFirstName()<<" (";
        cout << driverRecord[i].getAge() << "): ";
        cout << driverRecord[i].getLicenseNum() << endl;
    }
}

void DMV::seniorNonvote()
{
    for(int i=0; i<size; i++)
    {
        if(driverRecord[i].getAge() >= 55 && driverRecord[i].getVoteStat() == 'N')
        {
            cout << driverRecord[i].getLastName() << ", ";
            cout << driverRecord[i].getFirstName()<<" (";
            cout << driverRecord[i].getAge() << "): ";
            cout << driverRecord[i].getLicenseNum() << endl;
        }
    }
}


void DMV::firstInitial()
{
    char firstInitial;

    cout << "What is the driver's first initial?";
    cin >> firstInitial;

    int counter;

    for(int i=0; i<size; i++)
    {
        string temp = driverRecord[i].getFirstName();
        if(firstInitial == driverRecord[i].getFirstChar(temp))
        {
            cout << driverRecord[i].getLastName() << ", ";
            cout << driverRecord[i].getFirstName()<<" (";
            cout << driverRecord[i].getAge() << "): ";
            cout << driverRecord[i].getLicenseNum() << endl;
            counter++;
        }
    }

    if(counter==0)
    {
        cout << "No record found";
    }
}

void DMV::driverID()
{
    int id;
    int counter;

    cout << "What is the driver's id: ";
    cin >> id;
    while ( std::cin.fail() )
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Sorry, your input did not seem to be an int. Try again: ";   
        cin >> id;
    }

    for(int i=0; i<size; i++)
    {
        if(id == driverRecord[i].getLicenseNum())
        {
            cout << driverRecord[i].getLastName() << ", ";
            cout << driverRecord[i].getFirstName()<<" (";
            cout << driverRecord[i].getAge() << "): ";
            cout << driverRecord[i].getLicenseNum() << endl;
            counter++;
        }
    }
}

void DMV::registered()
{
    string driver;
    int licNum;
    char statUpdate;
    int counter=0;

    cout << "Enter a license number: ";
    cin >> licNum;
    while ( std::cin.fail() )
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Sorry, your input did not seem to be an int. Try again: ";   
        cin >> licNum;
    }

    for(int i=0; i<size; i++)
    {
        if(licNum == driverRecord[i].getLicenseNum() && driverRecord[i].getVoteStat() == 'N')
        {
            statUpdate = 'Y';
            driverRecord[i].setVoteStat(statUpdate);
            counter++;
            break;
        }
        else if(licNum == driverRecord[i].getLicenseNum() && driverRecord[i].getVoteStat() == 'Y')
        {
            cout << "Driver currently registered" << endl;
            counter++;
            break;
        }
    }
    if(counter==0)
    {
        cout << "No record found" << endl;
    }

}

void DMV::run()
{
    int menuChoice;
    printMenu();
    cin >> menuChoice;
    while ( std::cin.fail() )
    {
        cin.clear();

        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        cout << "Sorry, your input did not seem to be an int. Try again: ";   
        cin >> menuChoice;
    }

    if(menuChoice > 0 && menuChoice < 7)
    {
        if(menuChoice == 1)
        {
            AllInfo();
        }
        if(menuChoice == 2)
        {
            seniorNonvote();
        }
        if(menuChoice == 3)
        {
            firstInitial();
        }
        if(menuChoice == 4)
        {
            driverID();
        }
        if(menuChoice == 5)
        {
            registered();
        }
        if(menuChoice == 6)
        {
            exit(0);
        }
    }

}

DMV::~DMV()
{
    ofstream registered;
    registered.open(filename, ofstream::out | ofstream::trunc);
    registered << size;
    registered << "\t\n";
    for(int i=0; i<size; i++)
    {
        registered << driverRecord[i].getLicenseNum();
        registered << "\t";
        registered << driverRecord[i].getFirstName();
        registered << "\t";
        registered << driverRecord[i].getLastName();
        registered << "\t";
        registered << driverRecord[i].getAge();
        registered << "\t";
        registered << driverRecord[i].getVoteStat();
        if(i<size-1)
        {
            registered << "\n";
        }
    }
    registered.close();
    delete[] driverRecord;
}


