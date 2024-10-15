#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Registry.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/AppointmentCard.hpp"

using namespace std;

vector<AppointmentCard> AppCards;
vector<Ward> Patients;

Registry::Registry(){};

AppointmentCard& Registry::FindAppCardNumber(unsigned int AppCardNumber){
    for(auto AppCard: AppCards){
        if(AppCard.GetAppCardNumber() == AppCardNumber){
            return AppCard;
        }
    }
}

bool Registry::AppCardTime(unsigned short OfficeNumber, string VisitTime){
    bool IsFree = true;
    for(auto AppCard:AppCards){
        Office CurrentOffice = AppCard.GetOfficeInfo();
        if(CurrentOffice.GetRoomNumber() == OfficeNumber && VisitTime != AppCard.GetVisitTime()) return IsFree;
    }
    return !IsFree;
}

void Registry::AddPatient(unsigned short int WardNumber, Patient& NewPatient){
    for(auto Ward:Patients){
        if(Ward.GetRoomNumber() == WardNumber){
            Ward.AddPatient(NewPatient);
        }
    }
}

void Registry::NewWard(Ward& NewWard){
    Patients.push_back(NewWard);
}

void Registry::AddAppointmentCard(AppointmentCard& AppCard){
    AppCards.push_back(AppCard);
}

void Registry::DischargePatient(unsigned int CardNumber){
    unsigned int Counter = 0;
    for(auto Ward:Patients){
        for(auto Patient:Ward.PatientsInWard){
            if(Patient.GetCardNumber() == CardNumber) {
                Ward.PatientsInWard.erase(Ward.PatientsInWard.begin() + Counter);
            }
            Counter ++;
        }
    }
    Counter = 0;
    for(auto AppCard:AppCards){
            if(AppCard.GetPatientInfo().GetCardNumber() == CardNumber) {
                AppCards.erase(AppCards.begin() + Counter);
            }
            Counter ++;
        }
}

bool Registry::HasAppointmentCard(unsigned int CurrentPatientCardNumber){
    bool HasAppCard = true;
    for(auto AppCard:AppCards){
        if(AppCard.GetPatientInfo().GetCardNumber() == CurrentPatientCardNumber){
            return HasAppCard;
        }
    }
    return !HasAppCard;
}