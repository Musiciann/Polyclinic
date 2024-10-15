#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"

using namespace std;

vector<Patient> PatientsInWard;
unsigned short NumberPatients = 0;

Ward::Ward(unsigned short RoomNumber, float Length, float Width, float Height):Room(RoomNumber, Length, Width, Height){}
Ward::Ward(){};

void Ward::AddPatient(Patient NewPatient){
    NumberPatients++;
    PatientsInWard.push_back(NewPatient);
}

unsigned short Ward::GetNumberPatients(){
    return NumberPatients;
}

bool Ward::CheckEmpty(){
    bool Empty = true;
    if(PatientsInWard.size() == 0){
        return Empty;
    } 
    return !Empty;
}

bool Ward::AppropriateSize() {
    bool IsValid = true;
    if(Length*Height*Width >= 9){
        return IsValid;
    }
    return !IsValid;
}
