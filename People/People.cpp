#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"

using namespace std;

unsigned short Age;
string Name;
string Surname;
string LastName;

People::People():Polyclinic::Polyclinic(){}

People::People(string Name, string Surname, string LastName, unsigned short Age):Name(Name), Surname(Surname), Age(Age), LastName(LastName){}

string People::GetName(){
    return Name;
}

string People::GetSurname(){
    return Surname;
}

string People::GetLastName(){
    return LastName;
}

unsigned short People::GetAge(){
    return Age;
}
