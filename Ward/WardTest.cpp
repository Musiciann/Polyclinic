#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

TEST(WardSize, WardAppropriateSize){
    Room Room(10,10,10,10);
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Ward GoodWard(23, 6, 4, 4);
    EXPECT_TRUE(GoodWard.Ward::AppropriateSize());
}

TEST(Ward, WardAddPatient){
    Room Room(10,10,10,10);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Ward GoodWard(23, 6, 4, 4);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    GoodWard.Ward::AddPatient(OldPatient);
    EXPECT_EQ(GoodWard.Ward::GetNumberPatients(), 1);
}

TEST(Ward, WardCheckEmpty){
    Room Room(10,10,10,10);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Ward GoodWard(23, 6, 4, 4);
    EXPECT_TRUE(GoodWard.Ward::CheckEmpty());
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    GoodWard.Ward::AddPatient(OldPatient);
    EXPECT_FALSE(GoodWard.Ward::CheckEmpty());
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}