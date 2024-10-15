#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Nurse.hpp"


using namespace std;

class Doctor:public MedicalStaff {
private:

    string Qualification;

public:

    Doctor(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, string Qualification, unsigned short YearExpirience, unsigned int WorkerID);
    Doctor();

    Doctor& operator = (Doctor &EqualDoctor);

    void ChangePatientState(string NewInfoState, Patient& CurrentPatient);

    string GetQualification();

};