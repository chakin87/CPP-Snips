//		Basic arrays
//    Arrays are pointers. They are dereferenced with the [] operator.


#include "functions.h"

int main(int argc, char** argv) {

	int ex_array[5];

	for (int i = 0; i < 5; ++i) {
		ex_array[i] = 10;
	}

	std::cin.get();
	return 0;
}