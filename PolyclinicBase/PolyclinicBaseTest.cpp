#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

TEST(Polyclinic, PolyclinicInitializationCheck){
    string PhoneNumber = "+376-48-384-59-53";
    string Address = "St. Skolkovo, 12-45";
    unsigned int ID = 515;
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    ASSERT_EQ(NewPolyclinic.Polyclinic::GetPolyclinicAddress(), Address);
    ASSERT_EQ(NewPolyclinic.Polyclinic::GetPolyclinicPhoneNumber(), PhoneNumber);
    ASSERT_EQ(NewPolyclinic.Polyclinic::GetPolyclinicID(), ID);
}

TEST(Polyclinic, PolyclinicInitAddress){
    string PhoneNumber = "+376-48-384-59-53";
    string Address = "St. Skolkovo, 12-45";
    unsigned int ID = 515;
    Polyclinic NewPolyclinic(PhoneNumber, Address, ID);
    ASSERT_EQ(NewPolyclinic.Polyclinic::GetPolyclinicAddress(), Address);
}

TEST(Polyclinic, PolyclinicInitPhoneNumber){
    string PhoneNumber = "+376-48-384-59-53";
    string Address = "St. Skolkovo, 12-45";
    unsigned int ID = 515;
    Polyclinic NewPolyclinic(PhoneNumber, Address, ID);
    ASSERT_EQ(NewPolyclinic.Polyclinic::GetPolyclinicPhoneNumber(), PhoneNumber);
}

TEST(Polyclinic, PolyclinicInitШВ){
    string PhoneNumber = "+376-48-384-59-53";
    string Address = "St. Skolkovo, 12-45";
    unsigned int ID = 515;
    Polyclinic NewPolyclinic(PhoneNumber, Address, ID);
    ASSERT_EQ(NewPolyclinic.Polyclinic::GetPolyclinicID(), ID);
}

TEST(Polyclinic, GetPatientsFromPolyclinic){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    NewPolyclinic.Polyclinic::SetTotalPatients(5);
    EXPECT_EQ(NewPolyclinic.Polyclinic::GetTotalPatients(), 5);
    NewPolyclinic.Polyclinic::SetTotalPatients(0);
    EXPECT_EQ(NewPolyclinic.Polyclinic::GetTotalPatients(), 0);
}

TEST(Polyclinic, GetPatientsStatic){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    NewPolyclinic.Polyclinic::SetTotalPatients(5);
    NewPolyclinic.Polyclinic::SetTotalPatients(4);
    EXPECT_EQ(Polyclinic::GetTotalPatients(), 4);
    NewPolyclinic.Polyclinic::SetTotalPatients(0);
    EXPECT_EQ(Polyclinic::GetTotalPatients(), 0);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
