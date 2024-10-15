#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"



using namespace std;

string Disease;
string State;
unsigned int CardNumber;
vector<string> MedicalRecords;

Patient::Patient():People::People(){};

Patient::Patient(string Name, string Surname, string LastName, unsigned short Age, string Disease, unsigned int CardNumber, string State):People::People(Name, Surname, LastName, Age){
    this->Disease = Disease;
    this->CardNumber = CardNumber;
    this->State = State;
}

unsigned int Patient::GetCardNumber(){
    return CardNumber;
}

bool Patient::CheckEmptyMedStory(){
    bool Empty = true;
    if(MedicalRecords.size() == 0) {
        return Empty;
    }
    return !Empty;
}

string Patient::GetState(){
    return State;
}

unsigned int Patient::MedRecordsAmount(){
    unsigned int Counter = 0;
    for(auto Record:MedicalRecords){
        Counter++;
    }
    return Counter;
}

bool Patient::operator ==(Patient& CurrentPatient){
    if(this->Name == CurrentPatient.Name &&
    this->Surname == CurrentPatient.Surname &&
    this->LastName == CurrentPatient.LastName &&
    this->Age == CurrentPatient.Age &&
    this->CardNumber == CurrentPatient.CardNumber &&
    this->Disease == CurrentPatient.Disease &&
    this->State == CurrentPatient.State) {
        return true;
    }
    return false;
}
