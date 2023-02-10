#include "Location.h"

MapSpawnCoords WarpPointCoords[] = {
	// CLUB HOUSE
	{{0x110,0xA}, {0x188,0x108}},
	{{0x20,0x34}, {0x98,0xA0}},
	{{0x150,0x0}, {0x1C8,0x30}},
	{{0x1E0,0xA0}, {0x240,0x100}},
	{{0xB8,0x20}, {0x130,0x80}},
	{{0x150,0xA0}, {0x1C8,0x100}},
	{{0x1E0,0x90}, {0x270,0x100}},
	{{0xE0,0x90}, {0x158,0xE8}},
	{{0x60,0x90}, {0xD8,0xE8}},

	// HAM STUDIO
	{{0x0,0xF0}, {0x78,0x150}},
	{{0xF0,0x20}, {0x160,0x70}},
	{{0x1E0,0xC0}, {0x2A0,0x130}},
	{{0x0,0xC0}, {0x30,0x130}},
	{{0x120,0xA0}, {0x198,0x110}},
	{{0x1D0,0x50}, {0x248,0xA0}},
	{{0x80,0x50}, {0xF8,0xA0}},
	{{0x10,0x50}, {0x88,0xA0}},
	{{0x80,0xA0}, {0xF0,0x110}},
	{{0x80,0xA0}, {0xF0,0x110}},
	{{0x80,0xA0}, {0xF0,0x110}},

	// VILLAGE
	{{0xF0,0x1C0}, {0x168,0x220}},
	{{0x0,0x180}, {0x80,0x1D0}},
	{{0x50,0xA0}, {0xC0,0xF0}},
	{{0x190,0x90}, {0x210,0xF0}},
	{{0x1D0,0x180}, {0x250,0x1D0}},
	{{0xF0,0x140}, {0x168,0x1B0}},
	{{0xF0,0x140}, {0x168,0x1B0}},
	{{0xF0,0x140}, {0x168,0x1B0}},
	{{0xF0,0x140}, {0x168,0x1B0}},

	// STADIUM
	{{0x1E0,0x130}, {0x260,0x190}},
	{{0x1E0,0xE0}, {0x260,0x130}},
	{{0x1E0,0x140}, {0x2A0,0x1A0}},
	{{0x188,0x54}, {0x200,0xC0}},
	{{0x0,0x140}, {0x30,0x1A0}},
	{{0x0,0x60}, {0x30,0xC0}},
	{{0x4158,0xA4}, {0x1D0,0x110}},
	{{0x2A0,0xD0}, {0x320,0x130}},
	{{0x30,0x70}, {0xA0,0xC0}},

	// BEACH
	{{0x50,0x140}, {0xC0,0x1A0}},
	{{0x50,0x20}, {0xC8,0x80}},
	{{0xF0,0x20}, {0x1B0,0x70}},
	{{0xF0,0xF0}, {0x1B0,0x150}},
	{{0x0,0x20}, {0x30,0x70}},
	{{0x0,0xF0}, {0x30,0x150}},
	{{0xF0,0xA0}, {0x168,0x110}},
	{{0xC8,0x54}, {0x140,0xC0}},
	{{0x1E0,0x60}, {0x290,0xD0}},
	{{0x0,0x30}, {0x40,0x90}},

	// TENNIS COURT
	{{0xE8,0x140}, {0x160,0x1A0}},
	{{0xF0,0x40}, {0x168,0xA0}},
	{{0x1E,0x90}, {0x2A0,0xE0}},
	{{0x0,0x60}, {0x30,0xD0}},
	{{0xF0,0x140}, {0x168,0x1B0}},
	{{0xD8,0x44}, {0x150,0xB0}},
	{{0x1E0,0x140}, {0x288,0x1A0}},
	{{0x0,0x0}, {0x70,0x60}},

	// LAWN
	{{0xF0,0xA0}, {0x170,0x100}},
	{{0x30,0x20}, {0xA0,0x70}},
	{{0xF0,0x80}, {0x1B0,0xE0}},
	{{0x0,0x70}, {0x30,0xE0}},
	{{0xF0,0xA0}, {0x168,0x120}},
	{{0xD8,0x34}, {0x150,0xA0}},
	{{0x1E0,0x60}, {0x290,0xC0}},
	{{0x0,0x40}, {0x30,0xA0}},

	// POOL
	{{0xF8,0x140}, {0x170,0x190}},
	{{0x1B0,0x0}, {0x220,0x30}},
	{{0x130,0xA0}, {0x1A0,0x100}},
	{{0x110,0x140}, {0x190,0x1C0}},
	{{0x80,0x11C}, {0xF8,0x188}},
	{{0x1CC,0xD8}, {0x224,0x144}},
	{{0xF0,0xA0}, {0x168,0x110}},
	{{0xD8,0x64}, {0x150,0xD0}},
	{{0x1B0,0x60}, {0x240,0xC0}},
	{{0x20,0x50}, {0x90,0xC0}},
};

// Indexes for WarpPointCoords
enum WarpPointsID {
	CLUB_HOUSE_F1_MAIN_ENTRANCE = 0x0,
	CLUB_HOUSE_F1_SLIDE = 0x1,
	CLUB_HOUSE_F1_LADDER = 0x2,
	CLUB_HOUSE_F1_BED = 0x3,
	CLUB_HOUSE_F1_TV = 0x4,
	CLUB_HOUSE_F2_LADDER = 0x5,
	CLUB_HOUSE_F2_MESSAGE_MACHINE = 0x6,
	CLUB_HOUSE_F2_BASKETBALL_MINIGAME_GREEN = 0x7,
	CLUB_HOUSE_F2_BASKETBALL_MINIGAME_RED = 0x8,

	HAM_STUDIO_AREA_1_MAIN_ENTRANCE = 0x9,
	HAM_STUDIO_AREA_1_DOOR = 0xA,
	HAM_STUDIO_AREA_1_RIGHT_ROUTE = 0xB,
	HAM_STUDIO_AREA_2_LEFT_ROUTE = 0xC,
	HAM_STUDIO_MAIN_HALL_MAIN_ENTRANCE = 0xD,
	HAM_STUDIO_MAIN_HALL_FORTUNE = 0xE,
	HAM_STUDIO_MAIN_HALL_SHOPPING = 0xF,
	HAM_STUDIO_MAIN_HALL_NEWS = 0x10,
	HAM_STUDIO_FORTUNE_MAIN_ENTRANCE = 0x11,
	HAM_STUDIO_SHOPPING_MAIN_ENTRANCE = 0x12,
	HAM_STUDIO_NEWS_MAIN_ENTRANCE = 0x13,

	VILLAGE_SQUARE_MAIN_ENTRANCE = 0x14,
	VILLAGE_SQUARE_DJUNGLE = 0x15,
	VILLAGE_SQUARE_RAINBOW = 0x16,
	VILLAGE_SQUARE_HAMHAM = 0x17,
	VILLAGE_SQUARE_SEAHAMS = 0x18,
	VILLAGE_DJUNGLE_MAIN_ENTRANCE = 0x19,
	VILLAGE_RAINBOW_MAIN_ENTRANCE = 0x1A,
	VILLAGE_HAMHAM_MAIN_ENTRANCE = 0x1B,
	VILLAGE_SEAHAMS_MAIN_ENTRANCE = 0x1C,

	STADIUM_AREA_1_MAIN_ENTRANCE = 0x1D,
	STADIUM_AREA_1_DOOR = 0x1E,
	STADIUM_AREA_1_LOWER_RIGHT = 0x1F,
	STADIUM_AREA_1_UPPER_RIGHT = 0x20,
	STADIUM_AREA_2_LOWER_LEFT = 0x21,
	STADIUM_AREA_2_UPPER_LEFT = 0x22,
	STADIUM_MAIN_HALL_MAIN_ENTRANCE = 0x23,
	STADIUM_MAIN_HALL_LOBY = 0x24,
	STADIUM_MAIN_HALL_DRESSING_ROOM = 0x25,
	STADIUM_DRESSING_ROOM_MAIN_ENTRANCE = 0x26,

	BEACH_AREA_1_MAIN_ENTRANCE = 0x27,
	BEACH_AREA_1_DOOR = 0x28,
	BEACH_AREA_1_UPPER_ROUTE = 0x29,
	BEACH_AREA_1_LOWER_ROUTE = 0x2A,
	BEACH_AREA_2_UPPER_ROUTE = 0x2B,
	BEACH_AREA_2_LOWER_ROUTE = 0x2C,
	BEACH_MAIN_HALL_MAIN_ENTRANCE = 0x2D,
	BEACH_MAIN_HALL_DRESSING = 0x2E,
	BEACH_MAIN_HALL_LOBY = 0x2F,
	BEACH_DRESSING_ROOM_MAIN_ENTRANCE = 0x30,

	TENNIS_COURT_AREA_1_MAIN_ENTRANCE = 0x31,
	TENNIS_COURT_AREA_1_DOOR = 0x32,
	TENNIS_COURT_AREA_1_RIGHT_ROUTE = 0x33,
	TENNIS_COURT_AREA_2_LEFT_ROUTE = 0x34,
	TENNIS_COURT_MAIN_HALL_MAIN_ENTRANCE = 0x35,
	TENNIS_COURT_MAIN_HALL_LOBY = 0x36,
	TENNIS_COURT_MAIN_HALL_DRESSING_ROOM = 0x37,
	TENNIS_COURT_DRESSING_ROOM_MAIN_ENTRANCE = 0x38,

	LAWN_AREA_1_MAIN_ENTRANCE = 0x39,
	LAWN_AREA_1_DOOR = 0x3A,
	LAWN_AREA_1_RIGHT_ROUTE = 0x3B,
	LAWN_AREA_2_LEFT_ROUTE = 0x3C,
	LAWN_MAIN_HALL_MAIN_ENTRANCE = 0x3D,
	LAWN_MAIN_HALL_LOBY = 0x3E,
	LAWN_MAIN_HALL_DRESSING_ROOM = 0x3F,
	LAWN_DRESSING_ROOM_MAIN_ENTRANCE = 0x40,

	POOL_AREA_1_MAIN_ENTRANCE = 0x41,
	POOL_AREA_1_LADDER = 0x42,
	POOL_AREA_1_DOOR = 0x43,
	POOL_AREA_2_LADDER = 0x44,
	POOL_AREA_2_INNER_CLOUD = 0x45,
	POOL_AREA_2_OUTER_CLOUD = 0x46,
	POOL_MAIN_HALL_MAIN_ENTRANCE = 0x47,
	POOL_MAIN_HALL_DRESSING = 0x48,
	POOL_MAIN_HALL_LOBY = 0x49,
	POOL_DRESSING_ROOM_MAIN_ENTRANCE = 0x4A,
};


LocationData::LocationData() {

}

LocationData::~LocationData() {

}


std::string LocationData::getWorldNameFromRoomID(RoomID id) {

	switch (id) {
		case RoomID::CLUB_HOUSE_F1:
		case RoomID::CLUB_HOUSE_F2: return "Club House";

		case RoomID::HAM_STUDIO_AREA_1:
		case RoomID::HAM_STUDIO_AREA_2:
		case RoomID::HAM_STUDIO_MAIN_HALL:
		case RoomID::HAM_STUDIO_FORTUNE:
		case RoomID::HAM_STUDIO_SHOPPING:
		case RoomID::HAM_STUDIO_NEWS: return "Ham Studio";

		case RoomID::VILLAGE_SQUARE:
		case RoomID::VILLAGE_DJUNGLE:
		case RoomID::VILLAGE_RAINBOW:
		case RoomID::VILLAGE_HAMHAM:
		case RoomID::VILLAGE_SEAHAMS: return "Village";

		case RoomID::STADIUM_AREA_1:
		case RoomID::STADIUM_AREA_2:
		case RoomID::STADIUM_MAIN_HALL:
		case RoomID::STADIUM_DRESSING_ROOM: return "Stadium";

		case RoomID::BEACH_AREA_1:
		case RoomID::BEACH_AREA_2:
		case RoomID::BEACH_MAIN_HALL:
		case RoomID::BEACH_DRESSING_ROOM: return "Beach";

		case RoomID::TENNIS_COURT_AREA_1:
		case RoomID::TENNIS_COURT_AREA_2:
		case RoomID::TENNIS_COURT_MAIN_HALL:
		case RoomID::TENNIS_COURT_DRESSING_ROOM: return "Tennis Court";

		case RoomID::LAWN_AREA_1:
		case RoomID::LAWN_AREA_2:
		case RoomID::LAWN_MAIN_HALL:
		case RoomID::LAWN_DRESSING_ROOM: return "Lawn";

		case RoomID::POOL_AREA_1:
		case RoomID::POOL_AREA_2:
		case RoomID::POOL_MAIN_HALL:
		case RoomID::POOL_DRESSING_ROOM: return "Pool";
		
		default: return "Unknown";
	}

}

std::string LocationData::getRoomNameFromRoomID(RoomID id) {

	switch (id) {
		case RoomID::CLUB_HOUSE_F1: return "Club House - Floor 1";
		case RoomID::CLUB_HOUSE_F2: return "Club House - Floor 2";

		case RoomID::HAM_STUDIO_AREA_1: return "Ham Studio - Area 1";
		case RoomID::HAM_STUDIO_AREA_2: return "Ham Studio - Area 2";
		case RoomID::HAM_STUDIO_MAIN_HALL: return "Ham Studio - Radio Hall";
		case RoomID::HAM_STUDIO_FORTUNE: return "Ham Studio - Fortune Room";
		case RoomID::HAM_STUDIO_SHOPPING: return "Ham Studio - Shopping Room";
		case RoomID::HAM_STUDIO_NEWS: return "Ham Studio - News Room";

		case RoomID::VILLAGE_SQUARE: return "Village - Square";
		case RoomID::VILLAGE_DJUNGLE: return "Village - Team DJungle Room";
		case RoomID::VILLAGE_RAINBOW: return "Village - Team Rainbow Room";
		case RoomID::VILLAGE_HAMHAM: return "Village - Team Hamham Room";
		case RoomID::VILLAGE_SEAHAMS: return "Village - Team Seahams Room";

		case RoomID::STADIUM_AREA_1: return "Stadium - Area 1";
		case RoomID::STADIUM_AREA_2: return "Stadium - Area 2";
		case RoomID::STADIUM_MAIN_HALL: return "Stadium - Lobby";
		case RoomID::STADIUM_DRESSING_ROOM: return "Stadium - Dressing Room";

		case RoomID::BEACH_AREA_1: return "Beach - Area 1";
		case RoomID::BEACH_AREA_2: return "Beach - Area 2";
		case RoomID::BEACH_MAIN_HALL: return "Beach - Lobby";
		case RoomID::BEACH_DRESSING_ROOM: return "Beach - Dressing Room";

		case RoomID::TENNIS_COURT_AREA_1: return "Tennis Court - Area 1";
		case RoomID::TENNIS_COURT_AREA_2: return "Tennis Court - Area 2";
		case RoomID::TENNIS_COURT_MAIN_HALL: return "Tennis Court - Lobby";
		case RoomID::TENNIS_COURT_DRESSING_ROOM: return "Tennis Court - Dressing Room";

		case RoomID::LAWN_AREA_1: return "Lawn - Area 1";
		case RoomID::LAWN_AREA_2: return "Lawn - Area 2";
		case RoomID::LAWN_MAIN_HALL: return "Lawn - Lobby";
		case RoomID::LAWN_DRESSING_ROOM: return "Lawn - Dressing Room";

		case RoomID::POOL_AREA_1: return "Pool - Area 1";
		case RoomID::POOL_AREA_2: return "Pool - Area 2";
		case RoomID::POOL_MAIN_HALL: return "Pool - Lobby";
		case RoomID::POOL_DRESSING_ROOM: return "Pool - Dressing Room";

		default: return "Unknown";
	}

}