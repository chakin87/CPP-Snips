//#includes LOL
#include <iostream>
#include <string>
#include <ctime>

#include "func-PrintVarInfo.h"



// Prototypes
void For5L(unsigned long long& theLongNum);
void For4L(unsigned long long& theLongNum);
void For3L(unsigned long long& theLongNum);
void For2L(unsigned long long& theLongNum);
void For1L(unsigned long long& theLongNum);

//defines

#define PRINT(x1, x2)\
	PrintVarInfoFull(theLong, "theLong", x1, x2);

#define PRINT\
	PrintVarInfoFull(theLong, "theLong", "\t\t\t*****", "\t\t\t*****");


int main(int argc, char** argv) {

	std::string input;
	unsigned long long theLong = 0;

	//Stack OverFlow
	//long long theLongArray[129000];


		PRINT;
		int timer = 10000, t = timer, b = 0;


	for (int i = 0; i < 10000; ++i) {
		For4L(theLong);


		while (--t) {
			++b;
		}
		t = timer;
		//++theLong;
		//theLong += (rand() * 10000) +theLong;
		system("CLS");
		PRINT;
	}


	std::cin >> input;


	return 0;
}

void For5L(unsigned long long& theLongNum) {
	for (short i = 0; i < 100; ++i) {
		//std::cout << "The value of theLong: [" << theLongNum << "]\n\n";
		//++theLongNum;
		For4L(theLongNum);
	}
}

void For4L(unsigned long long& theLongNum) {
	for (short i = 0; i < 100; ++i) {
		//++theLongNum;
		For3L(theLongNum);
	}
}

void For3L(unsigned long long& theLongNum) {
	for (short i = 0; i < 100; ++i) {
		//++theLongNum;
		For2L(theLongNum);
	}
}

void For2L(unsigned long long& theLongNum) {
	for (short i = 0; i < 100; ++i) {
		//++theLongNum;
		For1L(theLongNum);
	}
}

void For1L(unsigned long long& theLongNum) {

	for (short i = 0; i < 100; ++i) {
		++theLongNum;
	}

}