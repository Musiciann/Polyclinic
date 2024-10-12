#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Polyclinic {
protected:

    string PolyclinicPhoneNumber;
    string Address;
    unsigned int PolyclinicID;

    static unsigned short TotalPatients;

public:

    friend class Worker;

    Polyclinic(){}

    Polyclinic(string PolyclinicPhoneNumber, string Address, unsigned int PolyclinicID):PolyclinicPhoneNumber(PolyclinicPhoneNumber), Address(Address),PolyclinicID(PolyclinicID){}

    unsigned short GetTotalPatients(){
        return TotalPatients;
    }
};





class People:public Polyclinic {
protected:

    unsigned short Age;
    string Name;
    string Surname;
    string LastName;

public:

    People(){}

    People(string Name, string Surname, string LastName, unsigned short Age):Name(Name), Surname(Surname), Age(Age), LastName(LastName){}

    string GetName(){
        return Name;
    }

    string GetSurname(){
        return Surname;
    }

    virtual void Info() = 0;
};





class Worker:public People {
protected:

    unsigned int WorkerID;
    unsigned int Salary; 

public:

    Worker(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID):People(Name, Surname, LastName, Age) {
        this->Salary = Salary;
        this->WorkerID = WorkerID;
    }

    Worker(){}

    unsigned int GetWorkerID(){
        return WorkerID;
    }

    unsigned int GetSalary(){
        return Salary;
    }


};





class WorkerManager: public Worker {
private:

    vector<Worker> Workers;

public:

    WorkerManager(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID):Worker(Name, Surname, LastName, Age, Salary, WorkerID){}

    void AddWorker(Worker& NewWorker){
        Workers.push_back(NewWorker);
    }

    Worker& FindWorker(unsigned int WorkerID){
        for(auto Worker:Workers){
            if(Worker.GetWorkerID() == WorkerID){
                return Worker;
            }
        }
    }

    bool IsWorker(Worker& CurrentWorker){
        bool IsWorker = true;
        for(auto Worker:Workers){
            if(Worker.GetWorkerID() == CurrentWorker.GetWorkerID()){
                return IsWorker;
            }
        }
        return !IsWorker;
    }

    void FireWorker(Worker& Firedworker){
        for(auto Worker:Workers){
            int Counter = 0;
            if(Worker.GetWorkerID() == Firedworker.GetWorkerID()){
                    Workers.erase(Workers.begin() + Counter);
            } else Counter++;
        }
    }

    unsigned int CountYearSalary(Worker& CurrentWorker){
        return CurrentWorker.GetSalary()*12;
    }

    void AddCleanerTask(const string& NewTask, Cleaner& CurrentCleaner){
        CurrentCleaner.GetTasks().push_back(NewTask);
    }

    void AddCleanerSupplies(const string& NewSupply, Cleaner& CurrentCleaner){
        CurrentCleaner.GetSupplies().push_back(NewSupply);
    }

    void WorkersInfo(){
        for(auto Worker:Workers){
            Worker.Info();
        }
    }
};





class MedicalStaff:public Worker {  
    protected:

    unsigned short YearExpirience;

    public:

    MedicalStaff(){}

    MedicalStaff(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned short YearExpirience, unsigned int WorkerID):Worker(Name, Surname, LastName, Age, Salary, WorkerID) {
        this->YearExpirience = YearExpirience;
    }

    string& MakeExamination(Patient& CurrentPatient){
        return CurrentPatient.State;
    }

    virtual void ChangePatientState(string&, Patient&) = 0;
};





class Doctor:public MedicalStaff {
private:

    string Qualification;

public:

    Doctor(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, string Qualification, unsigned short YearExpirience, unsigned int WorkerID) : MedicalStaff(Name, Surname, LastName, Age, Salary, YearExpirience, WorkerID){
        this->Qualification = Qualification;
    }

    Doctor(){}

    Doctor& operator = (Doctor &EqualDoctor){
        Name = EqualDoctor.Name;
        Surname = EqualDoctor.Surname;
        LastName = EqualDoctor.LastName;
        Salary = EqualDoctor.Salary;
        Age = EqualDoctor.Age;
        Qualification = EqualDoctor.Qualification;
        YearExpirience = EqualDoctor.YearExpirience;
        return *this;
    }

    void DischargePatient(unsigned int CardNumber, Registry& CurrentRegistry){
        unsigned int Counter = 0;
        for(auto Ward:CurrentRegistry.Patients){
            for(auto Patient: Ward.PatientsInWard){
                if(Patient.GetCardNumber() == CardNumber) {
                    Ward.PatientsInWard.erase(Ward.PatientsInWard.begin() + Counter);
                    return;
                }
                Counter ++;
            }
        }
    }

    bool HasAppointmentCard(Patient& CurrentPatient, Registry& CurrentRegistry){
        bool HasAppCard = true;
        for(auto AppCard:CurrentRegistry.AppCards){
            if(CurrentPatient == AppCard.GetPatientInfo()){
                return HasAppCard;
            }
        }
        return !HasAppCard;
    }

    void ChangePatientState(string& NewInfoState, Patient& CurrentPatient) {
        CurrentPatient.State = NewInfoState;
        return;
    }

    void Info() override{
        cout << "Full name: " << Name << " " << Surname << " " << LastName << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Expirience: " << YearExpirience << endl;
        cout << "Qualification: " << Qualification << endl << endl;
    }

};





class Nurse : public MedicalStaff {
public:

    friend class Doctor;

    Nurse(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned short YearExpirience, unsigned int WorkerID) : MedicalStaff(Name, Surname, LastName, Age, Salary, YearExpirience, WorkerID) {}

    void AddMedicalRecord(string NewRecord, Patient& CurrentPatient){
        CurrentPatient.MedicalRecords.push_back(NewRecord);
    }

    void RemoveMedicalRecord(int index, Patient& CurrentPatient){
        if(index >= 0 && index < CurrentPatient.MedicalRecords.size()){
            CurrentPatient.MedicalRecords.erase(CurrentPatient.MedicalRecords.begin() + index);
        }
    }

    void MedicalStory(Patient& CurrentPatient){
        for(auto Record:CurrentPatient.MedicalRecords){
            cout << Record << endl;
        }
        cout << endl << endl;
    }

    bool CheckEmptyMedStory(Patient& CurrentPatient){
        bool Empty = true;
        if(CurrentPatient.MedicalRecords.size() == 0) {
            return Empty;
        }
        return !Empty;
    }

    bool IsPatientInWard(unsigned int CardNumber, Ward& CurrentWard){
        bool IsHere = true;
        for(auto Patient:CurrentWard.PatientsInWard){
            if(Patient.CardNumber == CardNumber){
                return IsHere;
            }
        }
        return !IsHere;
    }

    Patient& FindPatientInWard(unsigned int CardNumber, Ward& CurrentWard){
        for(auto Patient:CurrentWard.PatientsInWard){
            if(Patient.CardNumber == CardNumber){
                return Patient;
            }
        }
    }

    void ChangePatientState(string& NewInfoState, Patient& CurrentPatient){
        CurrentPatient.Disease = NewInfoState;
    }

    void Info() override{
        cout << "Full name: " << Name << " " << Surname << " " << LastName << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Expirience: " << YearExpirience << endl << endl;
    }
};





class Cleaner : public Worker, public Room {
private:

    vector<string> Supplies;
    vector<string> Tasks;

public:

    friend class WorkManager;

    Cleaner(string Name, string Surname, string LastName, unsigned short Age, unsigned int Salary, unsigned int WorkerID) : Worker(Name, Surname, LastName, Age, Salary, WorkerID) {}

    vector<string>& GetTasks(){
        return Tasks;
    }

    vector<string>& GetSupplies(){
        return Supplies;
    }

    bool CouldWork(){
        bool Could = true;
        if(Supplies.size() == 0){
            return !Could;
        }
        return Could;
    }

    void CompleteTask(const string& CompletedTask){
        unsigned int Counter = 0;
        for(auto Task:Tasks){
            if(Task == CompletedTask){
                Tasks.erase(Tasks.begin() + Counter);
                return;
            }
            ++Counter;
        }
    }

    bool AllTasksComplete(){
        bool AllComplete = true;
        if(Tasks.size() == 0){
            return AllComplete;
        }
        return !AllComplete;
    }

    void CleanRoom(Room& DirtyRoom){
        if(DirtyRoom.CheckDirty() && CouldWork()){
            DirtyRoom.Clean();
        }
    }
    
    void Info() override{
        cout << "Full name: " << Name << " " << Surname << " " << LastName << endl;
        cout << "Age: " << Age << endl;
        cout << "Salary: " << Salary << endl << endl;
    }
};





class Patient:public People {
protected:

    string Disease;
    string State;
    unsigned int CardNumber;
    vector<string> MedicalRecords;

public:

    friend MedicalStaff;
    friend class Doctor;
    friend class Nurse;

    Patient(){};

    Patient(string Name, string Surname, string LastName, unsigned short Age, string Disease, unsigned int CardNumber, string State):People(Name, Surname, LastName, Age){
        this->Disease = Disease;
        this->CardNumber = CardNumber;
        this->State = State;
    }

    unsigned int GetCardNumber(){
        return CardNumber;
    }

    void MedicalStory(){
        for(auto Record:MedicalRecords){
            cout << Record << endl;
        }
        cout << endl << endl;
    }

    bool CheckEmptyMedStory(){
        bool Empty = true;
        if(MedicalRecords.size() == 0) {
            return Empty;
        }
        return !Empty;
    }

    void Info() override{
        cout << "Full name: " << Name << " " << Surname << " " << LastName << endl;
        cout << "Age: " << Age << endl;
        cout << "Disease: " << Disease << endl;
        cout << "Card number: " << CardNumber << endl;
        cout << "State: " << State << endl << endl;
    }

    bool operator ==(Patient& CurrentPatient){
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
};





class Room:public Polyclinic {
protected:

    float Length;
    float Width;
    float Height;
    unsigned short RoomNumber;
    bool Dirty = false;

public:

    Room(){}

    Room(unsigned short RoomNumber, float Length, float Width, float Height):RoomNumber(RoomNumber), Length(Length), Width(Width), Height(Height){}

    virtual bool AppropriateSize(){}

    float FindSize(){
        return Length*Width*Height;
    }

    unsigned short GetRoomNumber(){
        return RoomNumber;
    }

    bool CheckDirty(){
        return Dirty;
    }

    void Clean(){
        Dirty = false;
    }
};





class Office:public Room, public Doctor{
protected:

    Doctor Owner;

public:

    Office(){}

    Office(short RoomNumber, Doctor &Owner, float Length, float Width, float Height):Room(RoomNumber, Length, Width, Height){
        this->Owner = Owner;
    }

    void ChangeOwner(Doctor& NewOwner){
        this->Owner = NewOwner;
    }

    Doctor& GetOwner(){
        return Owner;
    }

    bool AppropriateSize() override {
        bool IsValid = true;
        if(FindSize() >= 12){
            return IsValid;
        }
        return !IsValid;
    }

    void Info() override {
        cout << "Room Number: " << RoomNumber << ".\n";
        cout <<"Owner: ";
        Owner.Info();
        cout << endl;
    }
};





class Ward:public Room, public Patient{ 
protected:

    vector<Patient> PatientsInWard;
    unsigned short NumberPatients = 0;

public:

    friend class Doctor;
    friend class Nurse;

    Ward(short RoomNumber, float Length, float Width, float Height):Room(RoomNumber, Length, Width, Height){}

    void AddPatient(Patient NewPatient){
        NumberPatients++;
        PatientsInWard.push_back(NewPatient);
    }

    unsigned short GetNumberPatients(){
        return NumberPatients;
    }

    void Info() override{
        cout << "Ward number: " << RoomNumber << endl;
        cout << "Number of Patients in ward: " << NumberPatients << endl;
        cout << "Patients info:\n";
        for(auto Patient:PatientsInWard){
            Patient.Info();
        }
    }

    bool CheckEmpty(){
        bool Empty = true;
        if(PatientsInWard.size() == 0){
            return Empty;
        } 
        return !Empty;
    }

    bool AppropriateSize() override {
        bool IsValid = true;
        if(FindSize() >= 9){
            return IsValid;
        }
        return !IsValid;
    }
};





class Registry: public Ward, public AppointmentCard, public Polyclinic{
private:

    vector<AppointmentCard> AppCards;
    vector<Ward> Patients;

public:

    friend class Doctor;

    AppointmentCard& FindAppCardNumber(unsigned int AppCardNumber){
        for(auto AppCard: AppCards){
            if(AppCard.GetAppCardNumber() == AppCardNumber){
                return AppCard;
            }
        }
    }

    Patient& FindCardNumber(int CardNumber){
        for(auto Patient:Patients){
            if(Patient.GetCardNumber() == CardNumber){
                return Patient;
            }
        }
    }

    bool AppCardTime(unsigned short OfficeNumber, string VisitTime){
        bool IsFree = true;
        for(auto AppCard:AppCards){
            Office CurrentOffice = AppCard.GetOfficeInfo();
            if(CurrentOffice.GetRoomNumber() == OfficeNumber && VisitTime != AppCard.GetVisitTime()) return IsFree;
        }
        return !IsFree;
    }

    Patient& FindName(string Name, string Surname){
        for(auto Ward:Patients){
                for(auto Patient: Ward::PatientsInWard)
                    if(Patient.GetName() == Name && Patient.GetSurname() == Surname) {
                        return Patient;
            }
        }
    }

    void AddPatient(unsigned short int WardNumber, Patient& NewPatient){
        for(auto Ward:Patients){
            if(Ward.GetRoomNumber() == WardNumber){
                Ward.AddPatient(NewPatient);
                TotalPatients++;
            }
        }
    }

    void NewWard(Ward& NewWard){
        Patients.push_back(NewWard);
    }

    void AllPatientsInfo(){
        cout << "Patients in total: " << Ward::GetNumberPatients() << endl;;
        for(auto Ward:Patients){
            for(auto Patient: Ward::PatientsInWard){
                Patient.Info();
            }
        }
    }
};





class AppointmentCard:public Office {
private:

    unsigned int Number;
    string VisitTime;
    Patient PatientInfo;
    Office OfficeInfo;

public:

    friend class Doctor;

    AppointmentCard(unsigned int Number, string VisitTime, Patient& PatientInfo, Office& Office):Number(Number), VisitTime(VisitTime), PatientInfo(PatientInfo), OfficeInfo(OfficeInfo){}

    unsigned int GetAppCardNumber(){
        return Number;
    }
    
    string GetVisitTime(){
        return VisitTime;
    }
    
    Patient& GetPatientInfo(){
        return PatientInfo;
    }

    Office& GetOfficeInfo(){
        return OfficeInfo;
    }

    void Info() override{
        cout << "Appointment card number: " << Number << endl;
        cout << "Visit time: " << VisitTime << endl;
        cout << "Doctor: ";
        Office::Owner.Info();
        cout << endl;
        cout << "Patient: ";
        PatientInfo.Info();
    }
}; 


int main(){


    return 0;
}