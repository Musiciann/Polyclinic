#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"

using namespace std;

class Office:public Room{
protected:

    unsigned int OwnerID;

public:

    Office();

    friend class Doctor;

    Office(short RoomNumber, float Length, float Width, float Height, unsigned int WorkerID);

    void ChangeOwner(unsigned int NewOwnerID);

    unsigned int GetOwner();

    bool AppropriateSize();
};