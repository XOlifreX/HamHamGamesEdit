#include "SaveManager.h"


SaveManager::SaveManager(std::string fileName)
{
	this->save = new File(fileName);
}


SaveManager::SaveManager(File* file) : save(file)
{
}

SaveManager::~SaveManager()
{
	delete(this->save);
}



std::string SaveManager::extractHamtaroString(std::string hamtaroString) {

	std::string value = "";

	short j = 0;
	// Special characters not supported currently
	for (int i = 0; i < hamtaroString.size(); i++) {

		// Actual string value
		if (j % 4 == 2 && hamtaroString[i + 1] == 0x5)
			value += hamtaroString[i];

		j++;

	}

	return value;

}

void SaveManager::setHamtaroStringAt(std::string message, int location) {

	short j = 0;
	short stringIndex = 0;
	bool finalSet = false;

	for (int i = location; i < (location + MAX_STRING_SIZE); i++) {

		switch (j % 4) {
		case 0:
			this->save->setValueAt(i, 0x21);
			break;
		case 1:
			this->save->setValueAt(i, 0xFF);
			break;
		case 2:
			if (stringIndex >= message.size()) {
				if (finalSet) {
					this->save->setValueAt(i, 0x00);
				}
				else {
					this->save->setValueAt(i, 0x05);
					finalSet = true;
				}
				continue;
			}
			this->save->setValueAt(i, message[stringIndex]);
			stringIndex++;
			break;
		default:
			this->save->setValueAt(i, 0x05);
		}

		j++;

	}

}

long SaveManager::getIntegrityHash(int padding) {

	long hash = 0;
	for (int i = (START_SAVE_1 + padding); i < (START_SAVE_1 + SAVE_DATA_PART_SIZE + padding); i++) {

		// Padding to save file
		if (i < (0x200 + padding))
			continue;

		// Skipped bytes
		if (i >= (0x2cd + padding) && i < (0x2cf + padding))
			continue;

		if (i >= (0x2d6 + padding) && i < (0x2d8 + padding))
			continue;

		if (i >= (0x5e2 + padding) && i < (0x05e4 + padding))
			continue;

		if (i >= (0x3da4 + padding) && i < (0x3da6 + padding))
			continue;

		hash += this->save->getValueAt(i, 1);

	}

	hash = ((hash) & 0x0000FFFF) | (((~hash) << 16) & 0xFFFF0000);

	return hash;

}

std::string SaveManager::getStringAt(long index, short size) {

	if (index >= 0 &&
		index < SAVE_SIZE &&
		(index + size) < SAVE_SIZE &&
		size <= MAX_STRING_SIZE &&
		size >= 1
		) {

		std::string value = "";

		for (int i = index; i < (index + size); i++)
			value += this->save->getValueAt(i, 1);

		return value;

	}

	return "";

}

void SaveManager::setStringAt(long index, const char* value) {

	if (index >= 0 &&
		index < SAVE_SIZE
		) {

		short j = 0;
		for (int i = index; i < (index + MAX_STRING_SIZE); i++) {

			this->save->setValueAt(i, value[j]);
			j++;

		}
	}
}


bool SaveManager::isModified() {

	return this->save->isModified();

}

void SaveManager::loadSave(std::string file) {

	this->save->loadFile(file);

}

bool SaveManager::isValidSave() {

	// We check for three things: 
	// First, is the header correct in both sections? (Hamtaro)
	// Secondly, Is the data the same in both save sections?
	// Lastly, Is the integrity check correct?
	
	unsigned char validHeader[] = {
		0x48,
		0x61,
		0x6D,
		0x74,
		0x61,
		0x72,
		0x6F
	};

	// Check header
	for (int i = 0x200; i < 0x207; i++) {

		if (this->save->getValueAt(i, 1) != validHeader[i - 0x200] ||
			this->save ->getValueAt(i + 0x3E00, 1) != validHeader[i - 0x200])
			return false;
	}

	// Check all values
	for (int i = 0x200; i < 0x4000; i++) {
		if (this->save->getValueAt(i, 1) != this->save->getValueAt(i + 0x3E00, 1))
			return false;
	}
	
	// Check integrity checks
	long hash1 = this->getIntegrityHash();
	long hash2 = this->getIntegrityHash(START_SAVE_2 - START_SAVE_1);
	
	if (hash1 != hash2)
		return false;

	if ((unsigned char)(hash1 & 0x000000FF) != this->save->getValueAt(0x208, 1))
		return false;
	if ((unsigned char)(hash2 & 0x000000FF) != this->save->getValueAt(0x4008, 1))
		return false;
	if ((unsigned char)((hash1 >> 8) & 0x000000FF) != this->save->getValueAt(0x209, 1))
		return false;
	if ((unsigned char)((hash2 >> 8) & 0x000000FF) != this->save->getValueAt(0x4009, 1))
		return false;
	if ((unsigned char)((hash1 >> 16) & 0x000000FF) != this->save->getValueAt(0x20A, 1))
		return false;
	if ((unsigned char)((hash2 >> 16) & 0x000000FF) != this->save->getValueAt(0x400A, 1))
		return false;
	if ((unsigned char)((hash1 >> 24) & 0x000000FF) != this->save->getValueAt(0x20B, 1))
		return false;
	if ((unsigned char)((hash2 >> 24) & 0x000000FF) != this->save->getValueAt(0x400B, 1))
		return false;

	return true;

}

void SaveManager::saveChanges() {

	unsigned char hashBuffer[4];
	long hash = this->getIntegrityHash();

	hashBuffer[0] = (unsigned char)(hash & 0x000000FF);
	hashBuffer[1] = (unsigned char)((hash >> 8) & 0x000000FF);
	hashBuffer[2] = (unsigned char)((hash >> 16) & 0x000000FF);
	hashBuffer[3] = (unsigned char)((hash >> 24) & 0x000000FF);

	this->save->setValueAt(Save::INTEGRITY_HASH_1, hashBuffer[0]);
	this->save->setValueAt(Save::INTEGRITY_HASH_2, hashBuffer[0]);

	this->save->setValueAt(Save::INTEGRITY_HASH_1 + 1, hashBuffer[1]);
	this->save->setValueAt(Save::INTEGRITY_HASH_2 + 1, hashBuffer[1]);

	this->save->setValueAt(Save::INTEGRITY_HASH_1 + 2, hashBuffer[2]);
	this->save->setValueAt(Save::INTEGRITY_HASH_2 + 2, hashBuffer[2]);

	this->save->setValueAt(Save::INTEGRITY_HASH_1 + 3, hashBuffer[3]);
	this->save->setValueAt(Save::INTEGRITY_HASH_2 + 3, hashBuffer[3]);

	this->save->applySaves();

}

void SaveManager::saveChanges(std::string newSource) {

	this->save->applySaves(newSource);

}

int SaveManager::getSeedCount() {

	return (int)(this->save->getValueAt(Save::SEEDS_COUNT_1, 2));

}

void SaveManager::setSeedCount(int nuts) {

	this->save->setValueAt(Save::SEEDS_COUNT_1, (unsigned char)(nuts & 0x000000FF));
	this->save->setValueAt(Save::SEEDS_COUNT_1 + 1, (unsigned char)((nuts >> 8) & 0x000000FF));

	this->save->setValueAt(Save::SEEDS_COUNT_2, (unsigned char)(nuts & 0x000000FF));
	this->save->setValueAt(Save::SEEDS_COUNT_2 + 1, (unsigned char)((nuts >> 8) & 0x000000FF));

}

std::string SaveManager::getUsername() {

	return this->extractHamtaroString(this->getStringAt(Save::USERNAME_1, 15 * 4));

}

void SaveManager::setUsername(std::string username) {

	this->setHamtaroStringAt(username, Save::USERNAME_1);
	this->setHamtaroStringAt(username, Save::USERNAME_2);
}

std::string SaveManager::getGreetingMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::GREETING_MESSAGE_1, 15 * 4));

}

void SaveManager::setGreetingMessage(std::string greeting) {

	this->setHamtaroStringAt(greeting, Save::GREETING_MESSAGE_1);
	this->setHamtaroStringAt(greeting, Save::GREETING_MESSAGE_2);

}

std::string SaveManager::getGoodbyeMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::BYE_MESSAGE_1, 15 * 4));

}

void SaveManager::setGoodbyeMessage(std::string goodbye) {

	this->setHamtaroStringAt(goodbye, Save::BYE_MESSAGE_1);
	this->setHamtaroStringAt(goodbye, Save::BYE_MESSAGE_2);
	
}

std::string SaveManager::getGratitudeMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::GRATITUDE_MESSAGE_1, 15 * 4));

}

void SaveManager::setGratitudeMessage(std::string gratitude) {

	this->setHamtaroStringAt(gratitude, Save::GRATITUDE_MESSAGE_1);
	this->setHamtaroStringAt(gratitude, Save::GRATITUDE_MESSAGE_2);

}

std::string SaveManager::getReasoningMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::REASONING_MESSAGE_1, 15 * 4));

}

void SaveManager::setReasoningMessage(std::string reasoning) {

	this->setHamtaroStringAt(reasoning, Save::REASONING_MESSAGE_1);
	this->setHamtaroStringAt(reasoning, Save::REASONING_MESSAGE_2);
	
}

std::string SaveManager::getJobMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::FUTURE_JOB_MESSAGE_1, 15 * 4));

}

void SaveManager::setJobMessage(std::string job
) {

	this->setHamtaroStringAt(job, Save::FUTURE_JOB_MESSAGE_1);
	this->setHamtaroStringAt(job, Save::FUTURE_JOB_MESSAGE_2);
	
}

std::string SaveManager::getLanguageMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::LANGUAGE_MESSAGE_1, 15 * 4));

}

void SaveManager::setLanguageMessage(std::string language) {

	this->setHamtaroStringAt(language, Save::LANGUAGE_MESSAGE_1);
	this->setHamtaroStringAt(language, Save::LANGUAGE_MESSAGE_2);
	
}

std::string SaveManager::getFoodMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::FAVORITE_FOOD_MESSAGE_1, 15 * 4));

}

void SaveManager::setFoodMessage(std::string food) {

	this->setHamtaroStringAt(food, Save::FAVORITE_FOOD_MESSAGE_1);
	this->setHamtaroStringAt(food, Save::FAVORITE_FOOD_MESSAGE_2);
	
}

std::string SaveManager::getVacationMessage() {

	return this->extractHamtaroString(this->getStringAt(Save::DREAM_VACATION_MESSAGE_1, 15 * 4));

}

void SaveManager::setVacationMessage(std::string vacation) {

	this->setHamtaroStringAt(vacation, Save::DREAM_VACATION_MESSAGE_1);
	this->setHamtaroStringAt(vacation, Save::DREAM_VACATION_MESSAGE_2);
	
}