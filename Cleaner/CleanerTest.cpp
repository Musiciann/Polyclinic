#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/WorkerManager.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Cleaner.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"


using namespace std;

TEST(Cleaner, CompleteTask){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Woman("Maksim", "Maksimov", "Maksimovich", 23);
    Worker Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    WorkerManager Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Room NewRoom(10,10,10,10);
    Cleaner NewCleaner("Fedor", "Maksov", "Noskovich", 46, 70, 121);
    Man.WorkerManager::AddCleanerTask("Clean Ward", NewCleaner);
    vector<string> AllTasks = NewCleaner.Cleaner::GetTasks();
    EXPECT_FALSE(NewCleaner.Cleaner::AllTasksComplete());
    vector<string> AllSupplies = NewCleaner.Cleaner::GetSupplies();
    NewCleaner.Cleaner::CompleteTask("Clean Ward");
    EXPECT_TRUE(NewCleaner.Cleaner::AllTasksComplete());
}

TEST(Cleaner, CleanRoom){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
     Worker Person("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
     People Woman("Maksim", "Maksimov", "Maksimovich", 23);
    Room NewRoom(10,10,10,10);
    Cleaner NewCleaner("Fedor", "Maksov", "Noskovich", 46, 70, 121);
    NewCleaner.Cleaner::CleanRoom(NewRoom);
    EXPECT_FALSE(NewRoom.Room::CheckDirty());
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}