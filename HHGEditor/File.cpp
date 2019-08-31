#include "File.h"



File::File(std::string file) : file(file)
{

	this->loadFile(file);

}


File::~File()
{
}


void File::loadFile() {
	
	this->clearData();

	char WORDBuffer[4];
	std::ifstream stream(this->file, std::ios::binary | std::ios::in);
	
	if (stream) {
		for (long i = 0; i < SAVE_SIZE; i++) {
			stream.read(WORDBuffer, 1);
			this->content[i] = (unsigned char)(WORDBuffer[0]);
			this->originalContent[i] = (unsigned char)(WORDBuffer[0]);
		}

		stream.close();
	}
}

void File::loadFile(std::string file) {

	this->file = file;
	this->loadFile();

}

void File::clearData() {

	for (int i = 0; i < SAVE_SIZE; i++)
		this->content[i] = this->originalContent[i] = 0x0;

}


long File::getValueAt(long index, short size) {

	if (index >= 0 && 
		index < SAVE_SIZE && 
		(index + size) < SAVE_SIZE && 
		size <=  sizeof(long) &&
		size >= 1
		) {

		long value = 0x0;

		short j = 0;
		for (int i = index; i < (index + size); i++) {

			value |= (unsigned char)(this->content[i]) << 8 * j;
			j++;

		}

		return value;
		
	}

	return 0xFF;

}


std::string File::getStringAt(long index, short size) {

	size = size * 4;

	if (index >= 0 &&
		index < SAVE_SIZE &&
		(index + size) < SAVE_SIZE &&
		size <= Save::MAX_STRING_SIZE_BYTES &&
		size >= 1
		) {

		std::string value = "";

		short j = 0;
		// Special characters not supported currently
		for (int i = index; i < (index + size); i++) {

			// Actual string value
			if (j % 4 == 2 && this->content[i + 1] == 0x5)
				value += this->content[i];
			// 0x5 is regular char value, 0x4 if special character
			if (j % 4 == 3)
			{

			}

			j++;

		}

		return value;

	}

	return "";

}

void File::setStringAt(long index, const std::string value) {

	int size = value.size() * 4;

	if (index >= 0 &&
		index < SAVE_SIZE &&
		size <= Save::MAX_STRING_SIZE_BYTES
		) {

		short j = 0;
		short stringIndex = 0;
		bool finalSet = false;
		for (int i = index; i < (index + Save::MAX_STRING_SIZE_BYTES); i++) {

			switch (j % 4) {
			case 0:
				this->content[i] = 0x21;
				break;
			case 1:
				this->content[i] = 0xFF;
				break;
			case 2:
				if (stringIndex >= value.size()) {
					if (finalSet) {
						this->content[i] = 0x00;
					}
					else {
						this->content[i] = 0x05;
						finalSet = true;
					}
					continue;
				}
				this->content[i] = value[stringIndex];
				stringIndex++;
				break;
			default:
				this->content[i] = 0x05;
			}

			j++;

		}
	}
}

void File::setValueAt(long index, unsigned char value) {

	if (index >= 0 &&
		index < SAVE_SIZE
	) {
		this->content[index] = value;
	}

}

void File::applySaves() {

	unsigned char hashBuffer[4];
	std::ofstream stream(this->file, std::ios::binary | std::ios::out | std::ios::in);

	long hash = this->getIntegrityHash();

	hashBuffer[0] = (unsigned char)(hash & 0x000000FF);
	hashBuffer[1] = (unsigned char)((hash >> 8) & 0x000000FF);
	hashBuffer[2] = (unsigned char)((hash >> 16) & 0x000000FF);
	hashBuffer[3] = (unsigned char)((hash >> 24)  & 0x000000FF);

	short integrityIndex = 0;
	short counter = 0;
	for (int i = 0; i < SAVE_SIZE; i++) {

		// Integrity hash
		if ((i >= 0x208 && i < 0x20C) || (i >= 0x4008 && i < 0x400C)) {
			integrityIndex = integrityIndex % 4;
			stream.put((unsigned char)(hashBuffer[integrityIndex]));
			integrityIndex++;

			continue;
		}

		stream.put(content[i]);
	}

	stream.close();

}

void File::applySaves(std::string newSource) {

	this->file = newSource;
	this->applySaves();

}


long File::getIntegrityHash() {

	long counter = 0;
	long integrityHash = 0;
	for (int i = 0; i < 0x3fc4; i++) {

		// Padding to save file
		if (i < 0x200)
			continue;

		// Skipped bytes
		if (i >= 0x2cd && i < 0x2cf)
			continue;

		if (i >= 0x2d6 && i < 0x2d8)
			continue;

		if (i >= 0x5e2 && i < 0x05e4)
			continue;

		if (i >= 0x3da4 && i < 0x3da6)
			continue;

		counter += content[i];

	}

	counter = ((counter) & 0x0000FFFF) | (((~counter) << 16) & 0xFFFF0000);

	return counter;

}

void File::reloadSave() {

	// TODO: ask if there are any chances that they need to be discarded
	this->loadFile();

}


bool File::isModified() {

	for (int i = 0; i < SAVE_SIZE; i++) {
		if (this->content[i] != this->originalContent[i])
			return true;
	}

	return false;

}