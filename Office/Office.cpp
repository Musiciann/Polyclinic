#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Office.hpp"

using namespace std;

unsigned int OwnerID;

Office::Office(short RoomNumber, float Length, float Width, float Height, unsigned int OwnerID):Room(RoomNumber, Length, Width, Height){
    this->OwnerID = OwnerID;
}

Office::Office(){}

void Office::ChangeOwner(unsigned int NewOwnerID){
    this->OwnerID = NewOwnerID;
}

unsigned int Office::GetOwner(){
    return OwnerID;
}

bool Office::AppropriateSize() {
    bool IsValid = true;
    if(FindSize() >= 12){
        return IsValid;
    }
    return !IsValid;
}
