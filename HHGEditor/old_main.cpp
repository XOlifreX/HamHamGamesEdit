#include <iostream>
#include <fstream>
#include <stdlib.h> 


void makeValid(std::string file, long newIntegrityHash);

int old_main() {

	std::string file("Hamtaro - Ham-Ham Games (E).sav");
	long pos = 0x0;
	char WORDBuffer[4];
	std::ifstream stream(file, std::ios::binary | std::ios::in);

	long counter = 0;
	long integrityHash = 0;
	for (int i = 0; i < 0x3fc4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

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

		// Integrity hash
		if (i >= 0x208 && i < 0x20C) 
			integrityHash |= (unsigned char)(WORDBuffer[0]) << 8 * (0x4 - (i + 1));

		counter += (unsigned char)(WORDBuffer[0]);

	}

	std::cout << "Total: 0x" << std::hex << counter << std::endl;

	long totalWithoutIntegrity = counter - (unsigned char)(integrityHash)
		-(unsigned char)(integrityHash >> 8)
		- (unsigned char)(integrityHash >> 8 * 2)
		- (unsigned char)(integrityHash >> 8 * 3);

	long difference = counter - totalWithoutIntegrity;

	std::cout << "Total without Integrity: 0x" << std::hex << totalWithoutIntegrity << std::endl;
	std::cout << "The difference between the hash with integrity and without integrity is: 0x" << std::hex << difference << "." << std::endl;
	std::cout << "Total bytes read: 0x" << std::hex << pos << std::endl;

	stream.close();

	makeValid(file, counter);

	std::cout << "Set hash to: 0x" << std::hex << counter << std::endl;
	std::cin.get();

	return 0;

}

void makeValid(std::string file, long newIntegrityHash) {

	unsigned char WORDBuffer[4];
	std::ofstream stream(file, std::ios::binary | std::ios::out | std::ios::in);

	long nottedIntegrityHash = ~newIntegrityHash;

	WORDBuffer[0] = (unsigned char)(newIntegrityHash & 0x000000FF);
	WORDBuffer[1] = (unsigned char)((newIntegrityHash >> 8) & 0x000000FF);
	WORDBuffer[2] = (unsigned char)(nottedIntegrityHash & 0x000000FF);
	WORDBuffer[3] = (unsigned char)((nottedIntegrityHash >> 8) & 0x000000FF);

	stream.seekp(0x208);
	for (int i = 0; i < 4; i++)
		stream.put(WORDBuffer[i]);

	stream.close();

}

void old() {

	long pos = 0x0;
	char WORDBuffer[4];
	std::ifstream stream("../HHGEditor/File/Test1.sav", std::ios::binary | std::ios::in);

	for (int i = 0; i < 128; i++) {
		stream.read(WORDBuffer, 4);
		pos += 4;
	}

	// Hamtaro
	long counter = 0;
	for (int i = 0; i < 0x8/*0x9DBD*/; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004970: 0x" << std::hex << counter << std::endl;

	// Integrity Hash
	long counter2 = 0;
	long integrityHash = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
		integrityHash |= (unsigned char)(WORDBuffer[0]) << 8 * (0x4 - (i + 1));
	}

	std::cout << "From 02004978: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	/*stream.read(WORDBuffer, 4);
	pos += 4;*/

	// Data part 1
	counter2 = 0;
	for (int i = 0; i < 0xC0; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 0200497C: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// byte #1
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A3C: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	stream.read(WORDBuffer, 2);
	pos += 2;

	// byte #2
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]) == 0xFF ? 0x0 : (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A3F: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// byte #3
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]) == 0xFF ? 0x0 : (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A40: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// byte #4
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]) == 0xFF ? 0x0 : (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A41: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// byte #5
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]) == 0xFF ? 0x0 : (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A42: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// byte #6
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]) == 0xFF ? 0x0 : (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A43: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// 2 byte #1
	counter2 = 0;
	for (int i = 0; i < 0x2; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]) == 0xFF ? 0x0 : (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A44: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	stream.read(WORDBuffer, 2);
	pos += 2;

	// data part 2 (area data?)
	counter2 = 0;
	for (int i = 0; i < 0x18; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A48: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 3
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A60: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 4
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004A80: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 5
	counter2 = 0;
	for (int i = 0; i < 0x40; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004AA0: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 6
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004AE0: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 7
	counter2 = 0;
	for (int i = 0; i < 0x30; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004B00: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 8
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004B30: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 9
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004B50: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 10
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004B70: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 11
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004B90: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 12
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004BB0: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 13
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004BD0: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 14
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004BF0: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 15
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C10: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 16
	counter2 = 0;
	for (int i = 0; i < 0x20; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C30: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 17
	counter2 = 0;
	for (int i = 0; i < 0x30; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C50: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 18
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C80: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 19
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C88: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 20
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C90: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 21
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004C98: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 22
	counter2 = 0;
	for (int i = 0; i < 0xC; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CA0: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 23
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CAC: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 24
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CB4: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 25
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CBC: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 26
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CC4: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 27
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CCC: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 27
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CD4: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 29
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CDC: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 30
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CE4: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 31
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CEC: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 32
	counter2 = 0;
	for (int i = 0; i < 0xC; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004CF4: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 33
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D00: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 34
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D04: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 35
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D08: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 36
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D0C: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 37
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D10: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 38
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D14: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 39
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D18: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 40
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D1C: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 41
	counter2 = 0;
	for (int i = 0; i < 0x18; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D20: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 42
	counter2 = 0;
	for (int i = 0; i < 0x18; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D38: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 43
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D50: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 44
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D51: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	stream.read(WORDBuffer, 2);
	pos += 2;

	// Reading username data
	counter2 = 0;
	for (int i = 0; i < 0x10F; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004D54: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// padding to next messages...
	counter2 = 0;
	for (int i = 0; i < 0x36B0; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02004E64: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 45
	counter2 = 0;
	for (int i = 0; i < 0x1; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02008514: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	stream.read(WORDBuffer, 2);
	pos += 2;

	// All other messages
	counter2 = 0;
	for (int i = 0; i < 0x212; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02008516: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 46
	counter2 = 0;
	for (int i = 0; i < 0x4; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 02008728: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	// data part 47
	counter2 = 0;
	for (int i = 0; i < 0x8; i++) {
		stream.read(WORDBuffer, 1);
		pos++;

		counter2 += (unsigned char)(WORDBuffer[0]);
	}

	std::cout << "From 0200872C: 0x" << std::hex << counter2 << std::endl;
	counter += counter2;

	std::cout << "Total: 0x" << std::hex << counter << std::endl;

	long totalWithoutIntegrity = counter - (unsigned char)(integrityHash)
		-(unsigned char)(integrityHash >> 8)
		- (unsigned char)(integrityHash >> 8 * 2)
		- (unsigned char)(integrityHash >> 8 * 3);

	long difference = counter - totalWithoutIntegrity;

	std::cout << "Total without Integrity: 0x" << std::hex << totalWithoutIntegrity << std::endl;
	std::cout << "The difference between the hash with integrity and without integrity is: 0x" << std::hex << difference << "." << std::endl;
	std::cout << "Total bytes read: 0x" << std::hex << pos << std::endl;

	std::cin.get();
	stream.close();

}