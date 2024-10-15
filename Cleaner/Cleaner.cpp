#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Cleaner.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"

vector<string> Supplies;
vector<string> Tasks;

Cleaner::Cleaner(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID) : Worker(Name, Surname, LastName, Age, Salary, WorkerID) {}

vector<string>& Cleaner::GetTasks(){
    return Tasks;
}

vector<string>& Cleaner::GetSupplies(){
    return Supplies;
}

bool Cleaner::CouldWork(){
    bool Could = true;
    if(Supplies.size() == 0){
        return !Could;
    }
    return Could;
}

void Cleaner::CompleteTask(const string& CompletedTask){
    unsigned int Counter = 0;
    for(auto Task:Tasks){
        if(Task == CompletedTask){
            Tasks.erase(Tasks.begin() + Counter);
            return;
        }
        Counter++;
    }
}

bool Cleaner::AllTasksComplete(){
    bool AllComplete = true;
    if(Tasks.size() == 0){
        return AllComplete;
    }
    return !AllComplete;
}

void Cleaner::CleanRoom(Room& DirtyRoom){
    if(DirtyRoom.CheckDirty() && CouldWork()){
        DirtyRoom.Clean();
    }
}

