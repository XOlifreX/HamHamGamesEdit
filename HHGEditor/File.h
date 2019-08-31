#include <iostream>
#include <fstream>

#include "Save.h"


#pragma once
class File
{
private:
	unsigned char content[SAVE_SIZE];
	unsigned char originalContent[SAVE_SIZE];
	std::string file;

	void loadFile();
	void clearData();
public:
	File(std::string file);
	~File();

	long getValueAt(long index, short size);
	void setValueAt(long index, unsigned char value);
	std::string getStringAt(long index, short size);
	void setStringAt(long index, const std::string value);

	void applySaves();
	void applySaves(std::string newSource);
	void reloadSave();
	long getIntegrityHash();

	void loadFile(std::string file);
	bool isModified();
};

