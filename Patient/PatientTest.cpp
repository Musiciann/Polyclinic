#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"


using namespace std;

TEST(Patient, PatientCardNumber){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Patient Man("Asriel","Chara","Drimuur", 44, "Flu", 122765, "Bad");
    EXPECT_EQ(Man.Patient::GetCardNumber(), 122765);
}

TEST(Patient, CheckPatientMedicalStory){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Patient Man("Asriel","Chara","Drimuur", 44, "Flu", 122765, "Bad");
    ASSERT_TRUE(Man.Patient::CheckEmptyMedStory());
}

TEST(Patient, PatientState){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Patient Man("Asriel","Chara","Drimuur", 44, "Flu", 122765, "Bad");
    ASSERT_EQ(Man.Patient::GetState(), "Bad");
}

TEST(PatientOperator, EqualPatients){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Patient FirstMan("Asriel","Chara","Drimuur", 44, "Flu", 122765, "Bad");
    Patient SecondMan("Asriel","Chara","Drimuur", 44, "Flu", 122765, "Bad");
    Patient ThirdMan("Sans","Good","Skeleton", 20, "Cold", 657345, "Good");
    EXPECT_TRUE(FirstMan == SecondMan);
    EXPECT_FALSE(FirstMan == ThirdMan);
    EXPECT_FALSE(ThirdMan == SecondMan);
}

TEST(Patient, MedRecords){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 23);
    Patient Man("Asriel","Chara","Drimuur", 44, "Flu", 122765, "Bad");
    EXPECT_EQ(Man.MedRecordsAmount(), 0);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}