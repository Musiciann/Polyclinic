#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Polyclinic {
protected:

    string PolyclinicPhoneNumber;
    string Address;
    unsigned int PolyclinicID;

    static unsigned short TotalPatients;

public:

    static void SetTotalPatients(unsigned short Total);

    friend class Worker;

    Polyclinic();

    Polyclinic(string PolyclinicPhoneNumber, string Address, unsigned int PolyclinicID);
    
    static unsigned short GetTotalPatients();

    string GetPolyclinicPhoneNumber();

    string GetPolyclinicAddress();

    unsigned int GetPolyclinicID();
};