#include "Location.h"

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