#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"

using namespace std;

unsigned int WorkerID;
unsigned int Salary; 


Worker::Worker(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID):People(Name, Surname, LastName, Age) {
    this->Salary = Salary;
    this->WorkerID = WorkerID;
}

Worker::Worker(){}

unsigned int Worker::GetWorkerID(){
    return WorkerID;
}

unsigned int Worker::GetSalary(){
    return Salary;
}



