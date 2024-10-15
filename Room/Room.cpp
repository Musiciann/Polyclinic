#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

float Length;
float Width;
float Height;
unsigned short RoomNumber;
bool Dirty = false;

Room::Room(){}

Room::Room(unsigned short RoomNumber, float Length, float Width, float Height):RoomNumber(RoomNumber), Length(Length), Width(Width), Height(Height){}

virtual bool Room::AppropriateSize(){
    if(FindSize() >= 12){
        return true;
    }
    return false;
}

float Room::FindSize(){
    return Length*Width*Height;
}

unsigned short Room::GetRoomNumber(){
    return RoomNumber;
}

bool Room::CheckDirty(){
    return Dirty;
}

void Room::Clean(){
    Dirty = false;
}
