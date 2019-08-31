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
	this->save->setValueAt(Save::SEEDS_COUNT_2, (unsigned char)((nuts >> 8) & 0x000000FF));

	this->save->setValueAt(Save::SEEDS_COUNT_1_SAVE2, (unsigned char)(nuts & 0x000000FF));
	this->save->setValueAt(Save::SEEDS_COUNT_2_SAVE2, (unsigned char)((nuts >> 8) & 0x000000FF));

}

std::string SaveManager::getUsername() {

	return this->save->getStringAt(Save::USERNAME_1, 15);

}

void SaveManager::setUsername(std::string username) {

	this->save->setStringAt(Save::USERNAME_1, username);
	this->save->setStringAt(Save::USERNAME_2, username);

}