#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"


using namespace std;

class People:public Polyclinic{
protected:

    unsigned short Age;
    string Name;
    string Surname;
    string LastName;

public:

    People();

    People(string Name, string Surname, string LastName, unsigned short Age);

    string GetName();

    string GetSurname();

    string GetLastName();

    unsigned short GetAge();
};