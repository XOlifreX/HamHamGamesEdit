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
	std::string getGreetingMessage();
	void setGreetingMessage(std::string greeting);
	std::string getGoodbyeMessage();
	void setGoodbyeMessage(std::string goodbye);
	std::string getGratitudeMessage();
	void setGratitudeMessage(std::string gratitude);
	std::string getReasoningMessage();
	void setReasoningMessage(std::string reasoning);
	std::string getJobMessage();
	void setJobMessage(std::string job);
	std::string getLanguageMessage();
	void setLanguageMessage(std::string language);
	std::string getFoodMessage();
	void setFoodMessage(std::string food);
	std::string getVacationMessage();
	void setVacationMessage(std::string vacation);
};

