#include <vector>

#include "File.h"
#pragma once


class MultiSave
{
public:
	MultiSave(std::vector<std::string> saveFiles);
	MultiSave(std::vector<File*> files);
	~MultiSave();

};