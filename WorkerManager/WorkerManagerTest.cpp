#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/WorkerManager.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Cleaner.hpp"


using namespace std;

TEST(WorkerManager, AddFireWorker){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 26);
    Worker NewWorker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    WorkerManager Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Man.WorkerManager::AddWorker(NewWorker);
    EXPECT_TRUE(Man.WorkerManager::IsWorker(NewWorker));
    Man.WorkerManager::FireWorker(NewWorker);
    EXPECT_FALSE(Man.WorkerManager::IsWorker(NewWorker));
}

TEST(WorkerManager, CountWorkerSalary){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 26);
    Worker NewWorker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    WorkerManager Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    EXPECT_EQ(Man.WorkerManager::CountYearSalary(NewWorker), 1260);
}

TEST(WorkerManager, GiveTaskCleaner){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker NewWorker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Person("Maksim", "Maksimov", "Maksimovich", 26);
    Room Room(10,10,10,10);
    Cleaner NewCleaner("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    WorkerManager Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Man.WorkerManager::AddCleanerTask("Clean Ward", NewCleaner);
    EXPECT_FALSE(NewCleaner.Cleaner::AllTasksComplete());
}

TEST(WorkerManager, GiveSupplyCleaner){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Worker NewWorker("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    People Person("Maksim", "Maksimov", "Maksimovich", 26);
    Room Room(10,10,10,10);
    Cleaner NewCleaner("Maks", "Semenov", "Maksimovich", 25, 105, 34785);
    WorkerManager Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    Man.WorkerManager::AddCleanerSupplies("Soap", NewCleaner);
    EXPECT_TRUE(NewCleaner.Cleaner::CouldWork());
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}