#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Polyclinic {
    protected:

    string Address = "Logvinovo, 12 - 15";

    public:

    static int TotalPatients;

    string GetAddress() { 
        return Address;
    }

    void SetAddress(string Address) {
        this->Address = Address;
    }

    Worker& FindWorker(string Name){

    }

    virtual void Info() = 0;

};





class Community:public Polyclinic {
    protected:

    string FullName;
    int Age;

    public:

    Community(){};

    Community(string FullName, int Age):FullName(FullName), Age(Age){};

    int GetAge(){
        return Age;
    }

    string GetName(){
        return FullName;
    }

    void SetName(string FullName){
        this->FullName = FullName;
    }

    void SetAge(int Age){
        this->Age = Age;
    }
};





class Worker:public Community {
    protected:

    int Salary;
    vector<Worker> Workers;

    public:

    Worker(){};

    Worker(string FullName, int Age, int Salary):Community(FullName, Age) {
        this->Salary = Salary;
        Workers.push_back(*this);
    }

    void AddWorker(Worker& NewWorker){
        Workers.push_back(NewWorker);
    }

    void FindWorker(string Name){
        for(auto Worker:Workers){
            if(Worker.FullName == Name){
                Worker.Info();
            }
        }
    }

    void FireWorker(Worker& Firedworker){
        for(auto Worker:Workers){
            int Counter = 0;
            if(Worker == Firedworker){
                    //TODO Перегрузить опреатор сравнения и сделать функции виртуальными
            }
        }
    }

    void WorkersInfo(){
        for(auto Worker:Workers){
            Worker.Info();
        }
    }

    int GetSalary(){
        return Salary;
    }

    int YearSalary(){
        return 12*Salary;
    }
};





class MedicalStaff:public Worker {  
    protected:

    int Expirience;

    public:

    MedicalStaff(){};

    MedicalStaff(string FullName, int Age, int Salary, int Expirience):Worker(FullName, Age, Salary) {
        this->Expirience = Expirience;
    }

    int GetSalary(){
        return Salary;
    }
};





class Doctor:public MedicalStaff {
    private:

    string Qualification;

    public:

    Doctor& operator = (Doctor &doctor){

        FullName = doctor.FullName;
        Salary = doctor.Salary;
        Age = doctor.Age;
        Qualification = doctor.Qualification;
        Expirience = doctor.Expirience;

        return *this;
    }

    Doctor(string FullName, int Age, int Salary, string Qualification, int Expirience) : MedicalStaff(FullName, Age, Salary, Expirience){
        this->Qualification = Qualification;
    };

    Doctor(){};

    string GetQualification(){
        return Qualification;
    }

    void Info() override{
        cout << "Full name: " << FullName << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Expirience: " << Expirience << endl;
        cout << "Qualification: " << Qualification << endl << endl;
    }

};





class Nurse : public MedicalStaff {
    public:

    Nurse(string FullName, int Age, int Salary, int Expirience) : MedicalStaff(FullName, Age, Salary, Expirience) {};

    void Info() override{
        cout << "Full name: " << FullName << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Expirience: " << Expirience << endl << endl;
    }

};





class Cleaner : public Worker {
    public:

    Cleaner(string FullName, int Age, int Salary) : Worker(FullName, Age, Salary) {};

    void Info() override{
        cout << "Full name: " << FullName << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl << endl;
    }

};





class Patient:public Community {
    protected:

    string Disease;

    public:
    int CardNumber;

    Patient(){};

    string GetDisease(){
        return Disease;
    }


    Patient(string FullName, int Age, string Disease, int CardNumber):Community(FullName, Age){
        this->Disease = Disease;
        this->CardNumber = CardNumber;
    }

    void Info() override{
        cout << "Full name: " << FullName << endl;
        cout << "Age: " << Age << endl;
        cout << "Disease: " << Disease << endl;
        cout << "Card number: " << CardNumber << endl << endl;
    }

};





class Room:public Polyclinic {
protected:

int RoomNumber;
double Size;

public:

Room(int RoomNumber):RoomNumber(RoomNumber){};

int static RoomsTotal;

int GetNumber(){
        return RoomNumber;
    }

};





class Office:public Room, public Doctor{
private:

Doctor Owner;

public:

    Office(int RoomNumber, Doctor &Owner):Room(RoomNumber){

    this->Owner = Owner;

    }

    void Info() override {
        cout << "Room Number: " << RoomNumber << ".\n";
        cout <<"Owner: ";
        Owner.Info();
        cout << endl;
    }

};





class Ward:public Room, public Patient{ 
private:

    vector<Patient> Patients;
    int NumberPatients = 0;

public:

    Ward(int RoomNumber):Room(RoomNumber){};

    void AddPatient(Patient NewPatient){
        Patients.push_back(NewPatient);
        NumberPatients++;
    }

    void Info() override{

        cout << "Ward number: " << RoomNumber << endl;
        cout << "Number of Patients in ward: " << NumberPatients << endl;
        cout << "Patients info:\n";

        for(auto Patient:Patients){
            Patient.Info();
        }

    }

    int GetNumberPatients(){
        return NumberPatients;
    }

};





class Registry:public Polyclinic, public Patient{
private:

string RegistryNumber = "+ 375-29-564-34-34";

vector<Patient> AllPatients;

public:

Patient& FindPatient(int CardNumber){
    for(auto Patient:AllPatients){
        if(Patient.CardNumber = CardNumber){
            Patient.Info();
            return Patient;
        }
    }
}

void NewPatient(Patient& NewPatient){
    AllPatients.push_back(NewPatient);
}

void EraseLastPatient(){
    AllPatients.pop_back();
}

//TODO - Поиск по имени пациента

//TODO - Удаление инф по самомму объекту


//TODO - БОЛЬШЕ ИСПОЛЬЗУЙ КОНСТАНТЫ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void DischargePatient(int CardNumber){
    int Counter = 0;
    for(auto Patient:AllPatients){
        if(CardNumber = Patient.CardNumber){
            AllPatients.erase(AllPatients.begin() + Counter);
        } else Counter++;
    }

}

void AllPatientsInfo(){
    for(auto Patient:AllPatients){
            Patient.Info();
    }
}


};











class AppointmentCard:public Office, public Registry{

};


int main(){


    return 0;
}