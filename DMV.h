//header file for DMV
#include "DriversLicenseRecord.h"

#ifndef DMV_h
#define DMV_h

class DMV
{
    private:
    Drivers *driverRecord;
    string filename;
    int size;

    public:
    DMV(string filename);
    void printMenu();
    void run();
    void AllInfo();
    void seniorNonvote();
    void firstInitial();
    void driverID();
    void registered();
    
    ~DMV();
};
#endif