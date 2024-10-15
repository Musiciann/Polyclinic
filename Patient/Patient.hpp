#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"

using namespace std;

class Patient:public People {
protected:

    string Disease;
    string State;
    unsigned int CardNumber;
    vector<string> MedicalRecords;

    friend class Registry;

public:

    friend class Doctor;
    friend class Nurse;

    string GetState();

    Patient();

    Patient(string Name, string Surname, string LastName, unsigned short Age, string Disease, unsigned int CardNumber, string State);

    unsigned int GetCardNumber();

    unsigned int MedRecordsAmount();

    bool CheckEmptyMedStory();

    bool operator ==(Patient& CurrentPatient);
};