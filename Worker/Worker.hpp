#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"

using namespace std;

class Worker:public People {
protected:

    unsigned int WorkerID;
    unsigned int Salary; 

public:

    Worker(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID);

    Worker();

    unsigned int GetWorkerID();

    unsigned int GetSalary();
};