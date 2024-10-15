#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
#include "/home/maksim/Рабочий стол/Polyclinic/Source/Room.hpp"
#include "/home/maksim/Рабочий стол/Polyclinic/Source/PolyclinicBase.hpp"

using namespace std;

TEST(RoomSize, RoomAppropriateSize){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room GoodRoom(23, 6, 4, 4);
    EXPECT_TRUE(GoodRoom.AppropriateSize());
}

TEST(RoomSize, RoomFindSize){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room GoodRoom(23, 6.3, 4, 4.56);
    EXPECT_EQ(GoodRoom.FindSize(),114.912f);
}

TEST(Room, RoomNumber){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room GoodRoom(23, 6, 4, 4);
    EXPECT_EQ(GoodRoom.GetRoomNumber(), 23);
}

TEST(RoomState, RoomCheckDirty){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room GoodRoom(23, 6, 4, 4);
    EXPECT_FALSE(GoodRoom.CheckDirty());
}

TEST(RoomState, CleanRoom){
    Polyclinic NewPolyclinic("+376-48-384-59-53", "St. Skolkovo, 12-45", 515);
    Room GoodRoom(23, 6, 4, 4);
    GoodRoom.Dirty = true;
    GoodRoom.Clean();
    EXPECT_FALSE(GoodRoom.CheckDirty());
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}