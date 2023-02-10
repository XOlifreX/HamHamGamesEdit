#pragma once
#ifndef LOCATION_H
#define LOCATION_H

#include <string>


enum RoomID {
	CLUB_HOUSE_F1 = 0x00,
	CLUB_HOUSE_F2 = 0x01,

	HAM_STUDIO_AREA_1 = 0x02,
	HAM_STUDIO_AREA_2 = 0x03,
	HAM_STUDIO_MAIN_HALL = 0x04,
	HAM_STUDIO_FORTUNE = 0x05,
	HAM_STUDIO_SHOPPING = 0x06,
	HAM_STUDIO_NEWS = 0x07,

	VILLAGE_SQUARE = 0x08,
	VILLAGE_DJUNGLE = 0x09,
	VILLAGE_RAINBOW = 0x0A,
	VILLAGE_HAMHAM = 0x0B,
	VILLAGE_SEAHAMS = 0x0C,

	STADIUM_AREA_1 = 0x0D,
	STADIUM_AREA_2 = 0x0E,
	STADIUM_MAIN_HALL = 0x0F,
	STADIUM_DRESSING_ROOM = 0x10,

	BEACH_AREA_1 = 0x11,
	BEACH_AREA_2 = 0x12,
	BEACH_MAIN_HALL = 0x13,
	BEACH_DRESSING_ROOM = 0x14,

	TENNIS_COURT_AREA_1 = 0x15,
	TENNIS_COURT_AREA_2 = 0x16,
	TENNIS_COURT_MAIN_HALL = 0x17,
	TENNIS_COURT_DRESSING_ROOM = 0x18,

	LAWN_AREA_1 = 0x19,
	LAWN_AREA_2 = 0x1A,
	LAWN_MAIN_HALL = 0x1B,
	LAWN_DRESSING_ROOM = 0x1C,

	POOL_AREA_1 = 0x1D,
	POOL_AREA_2 = 0x1E,
	POOL_MAIN_HALL = 0x1F,
	POOL_DRESSING_ROOM = 0x20,
};

struct XYCoord {
	int x;
	int y;
};
struct MapSpawnCoords {
	XYCoord camera;
	XYCoord player;
};


extern MapSpawnCoords WarpPointCoords[]; 


class LocationData
{
public:
	LocationData();
	~LocationData();

	std::string getWorldNameFromRoomID(RoomID id);
	std::string getRoomNameFromRoomID(RoomID id);
};

#endif // LOCATION_H