//File Name: <main.cpp> 
//Author: <Grace Zhu> 
//KUID: <2983508>
//Email Address: <gracezhu@ku.edu> 
//Homework Assignment Number: <Lab Exercise> 
//Description: <Program that ...> 
//Last Changed: </21>

#include <string>
#include "DMV.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc<2)
    {
        exit(0);
    }
    else
    {
        string fileName = argv[1];
        DMV myDMV(fileName);
        myDMV.run();
    }
}