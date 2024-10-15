#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/AppointmentCard.hpp"


using namespace std;

class Registry: public Ward,public AppointmentCard{
private:

    vector<AppointmentCard> AppCards;
    vector<Ward> Patients;

public:

    Registry();

    friend class Doctor;

    AppointmentCard& FindAppCardNumber(unsigned int AppCardNumber);

    bool AppCardTime(unsigned short OfficeNumber, string VisitTime);

    void AddPatient(unsigned short int WardNumber, Patient& NewPatient);

    void AddAppointmentCard(AppointmentCard& AppCard);

    void NewWard(Ward& NewWard);

    void DischargePatient(unsigned int CardNumber);

    bool HasAppointmentCard(unsigned int CurrentPatientCardNumber);
};