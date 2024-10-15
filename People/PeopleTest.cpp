#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

TEST(People, PeopleName){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    EXPECT_EQ(Man.People::GetName(), "Maksim");
}

TEST(People, PeopleSurname){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    EXPECT_EQ(Man.People::GetSurname(), "Maksimov");
}

TEST(People, PeopleLastName){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    EXPECT_EQ(Man.People::GetLastName(), "Maksimovich");
}

TEST(People, PeopleAge){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 23);
    EXPECT_EQ(Man.People::GetAge(), 23);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
