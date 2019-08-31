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



bool SaveManager::isModified() {

	return this->save->isModified();

}

void SaveManager::loadSave(std::string file) {

	this->save->loadFile(file);

}

void SaveManager::saveChanges() {

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

	return this->save->getStringAt(Save::USERNAME_1, 15);

}

void SaveManager::setUsername(std::string username) {

	this->save->setStringAt(Save::USERNAME_1, username);
	this->save->setStringAt(Save::USERNAME_2, username);

}

std::string SaveManager::getGreetingMessage() {

	return this->save->getStringAt(Save::GREETING_MESSAGE_1, 15);

}

void SaveManager::setGreetingMessage(std::string greeting) {

	this->save->setStringAt(Save::GREETING_MESSAGE_1, greeting);
	this->save->setStringAt(Save::GREETING_MESSAGE_2, greeting);

}

std::string SaveManager::getGoodbyeMessage() {

	return this->save->getStringAt(Save::BYE_MESSAGE_1, 15);

}

void SaveManager::setGoodbyeMessage(std::string goodbye) {

	this->save->setStringAt(Save::BYE_MESSAGE_1, goodbye);
	this->save->setStringAt(Save::BYE_MESSAGE_2, goodbye);

}

std::string SaveManager::getGratitudeMessage() {

	return this->save->getStringAt(Save::GRATITUDE_MESSAGE_1, 15);

}

void SaveManager::setGratitudeMessage(std::string gratitude) {

	this->save->setStringAt(Save::GRATITUDE_MESSAGE_1, gratitude);
	this->save->setStringAt(Save::GRATITUDE_MESSAGE_2, gratitude);

}

std::string SaveManager::getReasoningMessage() {

	return this->save->getStringAt(Save::REASONING_MESSAGE_1, 15);

}

void SaveManager::setReasoningMessage(std::string reasoning) {

	this->save->setStringAt(Save::REASONING_MESSAGE_1, reasoning);
	this->save->setStringAt(Save::REASONING_MESSAGE_2, reasoning);

}

std::string SaveManager::getJobMessage() {

	return this->save->getStringAt(Save::FUTURE_JOB_MESSAGE_1, 15);

}

void SaveManager::setJobMessage(std::string job
) {

	this->save->setStringAt(Save::FUTURE_JOB_MESSAGE_1, job);
	this->save->setStringAt(Save::FUTURE_JOB_MESSAGE_2, job);

}

std::string SaveManager::getLanguageMessage() {

	return this->save->getStringAt(Save::LANGUAGE_MESSAGE_1, 15);

}

void SaveManager::setLanguageMessage(std::string language) {

	this->save->setStringAt(Save::LANGUAGE_MESSAGE_1, language);
	this->save->setStringAt(Save::LANGUAGE_MESSAGE_2, language);

}

std::string SaveManager::getFoodMessage() {

	return this->save->getStringAt(Save::FAVORITE_FOOD_MESSAGE_1, 15);

}

void SaveManager::setFoodMessage(std::string food) {

	this->save->setStringAt(Save::FAVORITE_FOOD_MESSAGE_1, food);
	this->save->setStringAt(Save::FAVORITE_FOOD_MESSAGE_2, food);

}

std::string SaveManager::getVacationMessage() {

	return this->save->getStringAt(Save::DREAM_VACATION_MESSAGE_1, 15);

}

void SaveManager::setVacationMessage(std::string vacation) {

	this->save->setStringAt(Save::DREAM_VACATION_MESSAGE_1, vacation);
	this->save->setStringAt(Save::DREAM_VACATION_MESSAGE_2, vacation);

}