#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Cleaner.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/WorkerManager.hpp"


using namespace std;

vector<Worker> Subordinates;

WorkerManager::WorkerManager(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID):Worker(Name, Surname, LastName, Age, Salary, WorkerID){}

void WorkerManager::AddWorker(Worker& NewWorker){
    Subordinates.push_back(NewWorker);
}

Worker& WorkerManager::FindWorker(unsigned int WorkerID){
    for(auto Worker:Subordinates){
        if(Worker.GetWorkerID() == WorkerID){
            return Worker;
        }
    }
}

bool WorkerManager::IsWorker(Worker& CurrentWorker){
    bool IsWorker = true;
    for(auto Worker:Subordinates){
        if(Worker.GetWorkerID() == CurrentWorker.GetWorkerID()){
            return IsWorker;
        }
    }
    return !IsWorker;
}

void WorkerManager::FireWorker(Worker& Firedworker){
    for(auto Worker:Subordinates){
        int Counter = 0;
        if(Worker.GetWorkerID() == Firedworker.GetWorkerID()){
            Subordinates.erase(Subordinates.begin() + Counter);
        } else Counter++;
    }
}

unsigned int WorkerManager::CountYearSalary(Worker& CurrentWorker){
    return CurrentWorker.GetSalary()*12;
}

void WorkerManager::AddCleanerTask(const string& NewTask, Cleaner& CurrentCleaner){
    CurrentCleaner.GetTasks().push_back(NewTask);
}

void WorkerManager::AddCleanerSupplies(const string& NewSupply, Cleaner& CurrentCleaner){
    CurrentCleaner.GetSupplies().push_back(NewSupply);
}
