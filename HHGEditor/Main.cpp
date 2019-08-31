#include <iostream>

#include "File.h"


int main() {

	std::string fileName("Hamtaro - Ham-Ham Games (E).sav");
	File file(fileName);

	long nuts = file.getValueAt(0x2D4, 2);
	std::cout << "Current nuts count: " << nuts << "." << std::endl;

	nuts = 9999;
	std::cout << "Changing to:  " << nuts << "." << std::endl;

	file.setValueAt(0x2D4, (unsigned char)(nuts & 0x000000FF));
	file.setValueAt(0x2D5, (unsigned char)((nuts >> 8) & 0x000000FF));

	file.applySaves();

	std::cout << "Save applied." << std::endl;
	std::cin.get();

}