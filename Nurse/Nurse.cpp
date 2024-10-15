#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Nurse.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"

using namespace std;


Nurse::Nurse(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned short YearExpirience, unsigned int WorkerID) : MedicalStaff(Name, Surname, LastName, Age, Salary, YearExpirience, WorkerID) {}

void Nurse::AddMedicalRecord(string NewRecord, Patient& CurrentPatient){
    CurrentPatient.MedicalRecords.push_back(NewRecord);
}

void Nurse::RemoveMedicalRecord(int index, Patient& CurrentPatient){
    if(index >= 0 && index < CurrentPatient.MedicalRecords.size()){
        CurrentPatient.MedicalRecords.erase(CurrentPatient.MedicalRecords.begin() + index);
    }
}

unsigned int Nurse::MedicalRecordsAmount(Patient& CurrentPatient){
    unsigned int Counter;
    Counter = 0;
    for(auto Record:CurrentPatient.MedicalRecords){
        Counter++;
    }
    return Counter;
}

bool Nurse::CheckEmptyMedStory(Patient& CurrentPatient){
    bool Empty = true;
    if(CurrentPatient.MedicalRecords.size() == 0) {
        return Empty;
    }
    return !Empty;
}

bool Nurse::IsPatientInWard(unsigned int CardNumber, Ward& CurrentWard){
    bool IsHere = true;
    for(auto Patient:CurrentWard.PatientsInWard){
        if(Patient.CardNumber == CardNumber){
            return IsHere;
        }
    }
    return !IsHere;
}

Patient& Nurse::FindPatientInWard(unsigned int CardNumber, Ward& CurrentWard){
    for(auto Patient:CurrentWard.PatientsInWard){
        if(Patient.CardNumber == CardNumber){
            return Patient;
        }
    }
}

void Nurse::ChangePatientState(string NewInfoState, Patient& CurrentPatient){
    CurrentPatient.Disease = NewInfoState;
}

