#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/MedicalStaff.hpp"

using namespace std;

TEST(MedicalStaff, MedicalStaffExamination){

    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 578915);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Worker Maksim("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    MedicalStaff Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 3, 116871);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");

    EXPECT_EQ(Man.MedicalStaff::MakeExamination(OldPatient), "Good");
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
