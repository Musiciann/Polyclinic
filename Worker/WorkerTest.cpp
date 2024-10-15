#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/People.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Worker.hpp"


using namespace std;

TEST(Worker, WorkerSalary){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 26);
    Worker Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    EXPECT_EQ(Man.Worker::GetSalary(), 100);
}

TEST(Worker, WorkerID){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    People Person("Maksim", "Maksimov", "Maksimovich", 26);
    Worker Man("Maksim", "Maksimov", "Maksimovich", 23, 100, 111);
    EXPECT_EQ(Man.Worker::GetWorkerID(), 111);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}