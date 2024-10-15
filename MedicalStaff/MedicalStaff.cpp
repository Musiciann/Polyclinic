#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"

using namespace std;

unsigned short YearExpirience;

MedicalStaff::MedicalStaff(){}

MedicalStaff::MedicalStaff(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned short YearExpirience, unsigned int WorkerID):Worker(Name, Surname, LastName, Age, Salary, WorkerID) {
    this->YearExpirience = YearExpirience;
}

string MedicalStaff::MakeExamination(Patient CurrentPatient){
    return CurrentPatient.GetState();
}
