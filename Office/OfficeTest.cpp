#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Office.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

TEST(Office, OfficeOwnerID){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    EXPECT_EQ(NewOffice.Office::GetOwner(), 132);
}

TEST(Office, OfficeSize){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    EXPECT_TRUE(NewOffice.Office::AppropriateSize());
}

TEST(Office, OfficeChangeOwner){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    NewOffice.Office::ChangeOwner(135);

    EXPECT_EQ(NewOffice.Office::GetOwner(), 135);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
