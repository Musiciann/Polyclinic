#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Cleaner.hpp"

using namespace std;

class WorkerManager: public Worker {
private:

    vector<Worker> Subordinates;

public:

    WorkerManager(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID);

    void AddWorker(Worker& NewWorker);

    Worker& FindWorker(unsigned int WorkerID);

    bool IsWorker(Worker& CurrentWorker);

    void FireWorker(Worker& Firedworker);

    unsigned int CountYearSalary(Worker& CurrentWorker);

    void AddCleanerTask(const string& NewTask, Cleaner& CurrentCleaner);

    void AddCleanerSupplies(const string& NewSupply, Cleaner& CurrentCleaner);

};