#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"

class Cleaner : public Worker, public Room {
private:

    vector<string> Supplies;
    vector<string> Tasks;

public:

    friend class WorkManager;

    Cleaner(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID);

    vector<string>& GetTasks();

    vector<string>& GetSupplies();

    bool CouldWork();

    void CompleteTask(const string& CompletedTask);

    bool AllTasksComplete();

    void CleanRoom(Room& DirtyRoom);
    
};