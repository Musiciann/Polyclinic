#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Office.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/AppointmentCard.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"

using namespace std;

TEST(AppointmentCard, AppCardNumber){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    AppointmentCard AppCard(1243, "16:05", OldPatient, NewOffice);

    EXPECT_EQ(AppCard.AppointmentCard::GetAppCardNumber(), 1243);
}

TEST(AppointmentCard, AppCardTime){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    AppointmentCard AppCard(1243, "16:05", OldPatient, NewOffice);

    EXPECT_EQ(AppCard.AppointmentCard::GetVisitTime(), "16:05");
}

TEST(AppointmentCard, AppCardPatient){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    AppointmentCard AppCard(1243, "16:05", OldPatient, NewOffice);

    EXPECT_TRUE(AppCard.AppointmentCard::GetPatientInfo() == OldPatient);
}

TEST(AppointmentCard, AppCardOffice){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 122, "Good");
    Room Room(10,10,10,10);
    Office NewOffice(12,10,10,10,132);

    AppointmentCard AppCard(1243, "16:05", OldPatient, NewOffice);
    NewOffice = AppCard.AppointmentCard::GetOfficeInfo();

    EXPECT_TRUE(NewOffice.Office::GetOwner() == 132);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
