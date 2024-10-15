#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Office.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"

using namespace std;

class AppointmentCard:public Office {
private:

    unsigned int Number;
    string VisitTime;
    Patient PatientInfo;
    Office OfficeInfo;

    friend class Registry;

public:

    friend class Doctor;

    AppointmentCard(unsigned int Number, string VisitTime, Patient& PatientInfo, Office& Office);
    AppointmentCard();

    unsigned int GetAppCardNumber();
    
    string GetVisitTime();
    
    Patient& GetPatientInfo();

    Office& GetOfficeInfo();
}; 