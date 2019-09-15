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


void File::setValueAt(long index, unsigned char value) {

	if (index >= 0 &&
		index < SAVE_SIZE
	) {
		this->content[index] = value;
	}

}

void File::applySaves() {

	std::ofstream stream(this->file, std::ios::binary | std::ios::out | std::ios::in);

	for (int i = 0; i < SAVE_SIZE; i++)
		stream.put(content[i]);

	stream.close();

}

void File::applySaves(std::string newSource) {

	this->file = newSource;
	this->applySaves();

}


void File::reloadSave() {

	this->loadFile();

}


bool File::isModified() {

	for (int i = 0; i < SAVE_SIZE; i++) {
		if (this->content[i] != this->originalContent[i])
			return true;
	}

	return false;

}