#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Nurse.hpp"

using namespace std;

string Qualification;

Doctor::Doctor(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, string Qualification, unsigned short YearExpirience, unsigned int WorkerID) : MedicalStaff(Name, Surname, LastName, Age, Salary, YearExpirience, WorkerID){
    this->Qualification = Qualification;
}

Doctor::Doctor(){}

string Doctor::GetQualification(){
    return Qualification;
}

Doctor& Doctor::operator = (Doctor &EqualDoctor){
    Name = EqualDoctor.Name;
    Surname = EqualDoctor.Surname;
    LastName = EqualDoctor.LastName;
    Salary = EqualDoctor.Salary;
    Age = EqualDoctor.Age;
    Qualification = EqualDoctor.Qualification;
    YearExpirience = EqualDoctor.YearExpirience;
    return *this;
}

void Doctor::ChangePatientState(string NewInfoState, Patient& CurrentPatient) {
    CurrentPatient.State = NewInfoState;
    return;
}
