#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"

using namespace std;

class Prescription: public Doctor, public Patient {
private:

    vector<string> Medicine;
    unsigned int AttendingDoctorID;
    Patient& CurrentPatient;

public:

    friend class Doctor;

    Prescription(string NewMedicine, unsigned int AttendingDoctorID, Patient& CurrentPatient);

    void AddMedicine(string NewMedicine);

    void RemoveMedicine(string WrongMedicine);

    unsigned int MedicineAmount();
};