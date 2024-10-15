#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/AppointmentCard.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Office.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"


using namespace std;

unsigned int Number;
string VisitTime;
Patient PatientInfo;
Office OfficeInfo;

AppointmentCard::AppointmentCard(unsigned int Number, string VisitTime, Patient& PatientInfo, Office& OfficeInfo){
    this->Number = Number;
    this->VisitTime = VisitTime;
    this->PatientInfo = PatientInfo;
    this->OfficeInfo = OfficeInfo;
}

AppointmentCard::AppointmentCard(){};

unsigned int AppointmentCard::GetAppCardNumber(){
    return Number;
}
    
string AppointmentCard::GetVisitTime(){
    return VisitTime;
}
    
Patient& AppointmentCard::GetPatientInfo(){
    return PatientInfo;
}

Office& AppointmentCard::GetOfficeInfo(){
    return OfficeInfo;
}
