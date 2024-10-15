#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Ward.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Patient.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/AppointmentCard.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Office.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Registry.hpp"

using namespace std;

TEST(Registry, IsPatientHasAppCard){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Room Room(10,10,10,10);
    Ward GoodWard(23, 6, 4, 4);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");

    Registry NewRegistry;
    Office NewOffice(12,10,10,10,132);
    AppointmentCard AppCard(1243, "16:05", OldPatient, NewOffice);

    NewRegistry.Registry::AddAppointmentCard(AppCard);

    NewRegistry.Registry::NewWard(GoodWard);
    NewRegistry.Registry::AddPatient(23, OldPatient);
    

    EXPECT_TRUE(NewRegistry.Registry::HasAppointmentCard(126672));
}

TEST(Registry, RightAppointmentTime){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Room Room(10,10,10,10);
    Ward GoodWard(23, 6, 4, 4);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");

    Registry NewRegistry;
    Office NewOffice(12,10,10,10,132);
    AppointmentCard AppCard(1234, "10:00", OldPatient, NewOffice);

    NewRegistry.Registry::AddAppointmentCard(AppCard);

    NewRegistry.Registry::NewWard(GoodWard);
    NewRegistry.Registry::AddPatient(23, OldPatient);
    NewRegistry.Registry::FindAppCardNumber(1234);

    EXPECT_FALSE(NewRegistry.Registry::AppCardTime(14, "11:00"));
}

TEST(Registry, DischargePatient){
    Polyclinic Polyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Man("Maksim", "Maksimov", "Maksimovich", 26);
    Room Room(10,10,10,10);
    Ward GoodWard(23, 6, 4, 4);
    Patient OldPatient("Asriel","Chara","Drimuur", 44, "Flu", 126672, "Good");

    Registry NewRegistry;
    Office NewOffice(12,10,10,10,132);
    AppointmentCard AppCard(1234, "10:00", OldPatient, NewOffice);

    NewRegistry.Registry::AddAppointmentCard(AppCard);

    NewRegistry.Registry::NewWard(GoodWard);
    NewRegistry.Registry::AddPatient(23, OldPatient);
 

    NewRegistry.Registry::DischargePatient(126672);

    EXPECT_FALSE(NewRegistry.Registry::HasAppointmentCard(126672));
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
