#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

class Room:public Polyclinic {
protected:

    float Length;
    float Width;
    float Height;
    unsigned short RoomNumber;

public:

    bool Dirty = false;

    Room();

    Room(unsigned short RoomNumber, float Length, float Width, float Height);

    virtual bool AppropriateSize();

    float FindSize();

    unsigned short GetRoomNumber();

    bool CheckDirty();

    void Clean();
};
