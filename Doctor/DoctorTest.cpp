#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"

using namespace std;

TEST(Doctor, DoctorGetQualification){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker Worker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Doctor Anna("Anna", "Maksimova", "Maksimovna", 23, 100, "Surgeon", 3, 118901);

    EXPECT_EQ(Anna.Doctor::GetQualification(), "Surgeon");
}

TEST(Doctor, DoctorChangeState){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker Worker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Doctor Anna("Anna", "Maksimova", "Maksimovna", 23, 100, "Surgeon", 3, 118901);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");

    Anna.Doctor::ChangePatientState("Bad", OldPatient);
    EXPECT_EQ(OldPatient.Patient::GetState(), "Bad");
}

TEST(Doctor, EqualDoctor){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker Worker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);

    Doctor First("Anna", "Maksimova", "Maksimovna", 23, 100, "Surgeon", 3, 118901);
    Doctor Second("Efim", "Alekseev", "Ivanovich", 27, 100, "Dentist", 4, 118961);

    EXPECT_FALSE(First.People::GetName() == Second.People::GetName());
    First = Second;
    EXPECT_TRUE(First.People::GetName() == Second.People::GetName());
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}