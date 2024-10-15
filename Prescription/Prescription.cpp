#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Prescription.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"

using namespace std;

vector<string> Medicine;
unsigned int AttendingDoctorID;
Patient CurrentPatient;

Prescription::Prescription(string NewMedicine, unsigned int AttendingDoctorID, Patient& CurrentPatient):AttendingDoctorID(AttendingDoctorID),CurrentPatient(CurrentPatient){
    Medicine.push_back(NewMedicine);
}

void Prescription::AddMedicine(string NewMedicine){
    Medicine.push_back(NewMedicine);
}

void Prescription::RemoveMedicine(string WrongMedicine){
    unsigned int Counter = 0;
    for(auto OldMedicine:Medicine){
        if(OldMedicine == WrongMedicine){
            Medicine.erase(Medicine.begin() + Counter);
        }
        ++Counter;
    }
}

unsigned int Prescription::MedicineAmount(){
    unsigned int Counter = 0;
    for (auto MedicineInstance:Medicine){
        Counter++;
    }
    return Counter;
}
