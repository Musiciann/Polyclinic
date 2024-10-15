#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"

using namespace std;

class Ward:public Room, public Patient{ 
protected:

    vector<Patient> PatientsInWard;
    unsigned short NumberPatients = 0;

public:

    friend class Doctor;
    friend class Nurse;
    friend class Registry;

    Ward();

    Ward(unsigned short RoomNumber, float Length, float Width, float Height);

    void AddPatient(Patient NewPatient);

    unsigned short GetNumberPatients();

    bool CheckEmpty();

    bool AppropriateSize() override;
};
