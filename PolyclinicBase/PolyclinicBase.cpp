#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

string PolyclinicPhoneNumber;
string Address;
unsigned int PolyclinicID;

unsigned short Polyclinic::TotalPatients = 0;

void Polyclinic::SetTotalPatients(unsigned short Total){
    TotalPatients = Total;
}

Polyclinic::Polyclinic(){}

Polyclinic::Polyclinic(string PolyclinicPhoneNumber, string Address, unsigned int PolyclinicID):PolyclinicPhoneNumber(PolyclinicPhoneNumber), Address(Address),PolyclinicID(PolyclinicID){}

unsigned short Polyclinic::GetTotalPatients(){
    return TotalPatients;
}

string Polyclinic::GetPolyclinicPhoneNumber(){
        return PolyclinicPhoneNumber;
}

string Polyclinic::GetPolyclinicAddress(){
    return Address;
}

unsigned int Polyclinic::GetPolyclinicID(){
    return PolyclinicID;
}