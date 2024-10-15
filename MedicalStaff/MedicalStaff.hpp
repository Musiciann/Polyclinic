#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"

using namespace std;

class MedicalStaff:public Worker {  
    protected:

    unsigned short YearExpirience;

    public:

    MedicalStaff();

    MedicalStaff(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned short YearExpirience, unsigned int WorkerID);

    string MakeExamination(Patient CurrentPatient);
};