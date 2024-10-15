#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Prescription.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Doctor.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"

using namespace std;

TEST(Prescription, PrescriptionAddMedicine){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker Worker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Doctor Anna("Anna", "Maksimova", "Maksimovna", 23, 100, "Surgeon", 3, 118901);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");

    Prescription NewPrescription("Septolete", 123543, OldPatient);
    NewPrescription.Prescription::AddMedicine("Medicine");

    EXPECT_EQ(NewPrescription.Prescription::MedicineAmount(), 2);
}

TEST(Prescription, PrescriptionRemoveMedicine){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker Worker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    MedicalStaff Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 2, 117891);
    Doctor Anna("Anna", "Maksimova", "Maksimovna", 23, 100, "Surgeon", 3, 118901);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");

    Prescription Prescription("Septolete", 123543, OldPatient);
    Prescription.Prescription::AddMedicine("Medicine");
    Prescription.Prescription::RemoveMedicine("Medicine");

    EXPECT_EQ(Prescription.Prescription::MedicineAmount(), 1);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
