//#includes LOL
#include <iostream>
#include <string>



// Prototypes
void For5L(unsigned long long& theLongNum);
void For4L(unsigned long long& theLongNum);
void For3L(unsigned long long& theLongNum);
void For2L(unsigned long long& theLongNum);
void For1L(unsigned long long& theLongNum);



int main(int argc, char** argv) {

	std::string input;
	unsigned long long theLong = 0;

	std::cout << "The value of theLong: [" << theLong << "]\n\n";

	For5L(theLong);

	std::cout << "The value of theLong: [" << theLong << "]\n\n";

	std::cin >> input;


	return 0;
}

void For5L(unsigned long long& theLongNum) {
	for (short i = 0; i < 100; ++i) {
		std::cout << "The value of theLong: [" << theLongNum << "]\n\n";
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