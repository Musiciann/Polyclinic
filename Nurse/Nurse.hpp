#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"

using namespace std;

class Nurse : public MedicalStaff {
public:

    friend class Doctor;

    Nurse(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned short YearExpirience, unsigned int WorkerID);

    void AddMedicalRecord(string NewRecord, Patient& CurrentPatient);

    void RemoveMedicalRecord(int index, Patient& CurrentPatient);

    unsigned int MedicalRecordsAmount(Patient& CurrentPatient);

    bool CheckEmptyMedStory(Patient& CurrentPatient);

    bool IsPatientInWard(unsigned int CardNumber, Ward& CurrentWard);

    Patient& FindPatientInWard(unsigned int CardNumber, Ward& CurrentWard);

    void ChangePatientState(string NewInfoState, Patient& CurrentPatient);

};