#include "File.h"
#include "Save.h"


#pragma once
class SaveManager
{
private:
	File* save;
public:
	SaveManager(std::string fileName);
	SaveManager(File* file);
	~SaveManager();

	bool isModified();
	void loadSave(std::string file);

	void saveChanges();
	void saveChanges(std::string newSource);

	int getSeedCount();
	void setSeedCount(int nuts);
	std::string getUsername();
	void setUsername(std::string username);
};

