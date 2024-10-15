#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Nurse.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"

using namespace std;


TEST(Nurse, NurseAddRecord){
    Polyclinic NewPolyclinic("+376-48-674-59-53", "St. Skolkovo, 12-45", 515789);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Nurse Anna("Anna", "Maksimova", "Maksimovna", 23, 100, 3, 118901);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");
    Worker Maksim("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Anna.Nurse::AddMedicalRecord("NewRecord", OldPatient);
    EXPECT_FALSE(Anna.Nurse::CheckEmptyMedStory(OldPatient));
    EXPECT_FALSE(OldPatient.Patient::CheckEmptyMedStory());
    EXPECT_EQ(Anna.Nurse::MedicalRecordsAmount(OldPatient), OldPatient.Patient::MedRecordsAmount());
}

TEST(Nurse, NurseRemoveRecord){
    Polyclinic NewPolyclinic("+376-47-574-59-53", "St. Skolkino, 78-85", 568715);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Nurse Eva("Eva", "Maksimova", "Maksimovna", 23, 100, 3, 181671);
    Worker Maksim("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Patient OldPatient("Asgor","Chara","Drimuur", 56, "Flu", 12352, "Bad");
    Eva.Nurse::AddMedicalRecord("New Record", OldPatient);
    Eva.Nurse::RemoveMedicalRecord(0, OldPatient);
    EXPECT_TRUE(Eva.Nurse::CheckEmptyMedStory(OldPatient));
    EXPECT_EQ(OldPatient.Patient::MedRecordsAmount(), 0);
}

TEST(Nurse, NurseChangePatientState){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 590715);
    People Man("Maksim", "Maksimov", "Maksimovich", 24);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Nurse Anna("Anna", "Maksimova", "Maksimovna", 23, 100, 3, 111777);
    Worker Maksim("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Patient OldPatientFirst("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Patient OldPatientSecond("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Anna.Nurse::ChangePatientState("Cold", OldPatientFirst);
    EXPECT_FALSE(OldPatientFirst == OldPatientSecond);
}

TEST(Nurse, NursePatientInWard){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 5137755);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Room NewRoom(132, 10, 10, 10);
    Nurse Anna("Anna", "Maksimova", "Maksimovna", 23, 100, 3, 110981);
    Worker Maksim("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Ward NewWard(12, 10, 10, 10);
    NewWard.Ward::AddPatient(OldPatient); 
    EXPECT_TRUE(Anna.Nurse::IsPatientInWard(122, NewWard));
}


TEST(Nurse, NurseFindPatient){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Room NewRoom(654,10,10,10);
    Nurse Anna("Anna", "Maksimova", "Maksimovna", 23, 100, 3, 111);
    Worker Maksim("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Ward NewWard(182, 10, 10, 10);
    NewWard.Ward::AddPatient(OldPatient);
    Anna.Nurse::FindPatientInWard(122, NewWard);
    EXPECT_TRUE(Anna.Nurse::IsPatientInWard(122, NewWard));
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
