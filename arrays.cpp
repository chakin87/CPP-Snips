//		Basic arrays
//    Arrays are pointers. They are dereferenced with the [] operator.


#include "functions.h"
#include <array>

int main(int argc, char** argv) {

	int ex_array[5];
	int* same_as_above_ex_array = new int[5]; // This is the same as above, 
											  // except this is allocated on the Heap.

	int ex_array_count = sizeof(ex_array) / sizeof(int);
	// Gets the size of stack allocated array. sizeof()return number of bytes.
	// It's best to keep track of the size/length of an array on your own
	// using a const. Or use a std::array but a little more overhead (usually worth it).
	// std::array is safer.

	delete[] same_as_above_ex_array;

	for (int i = 0; i < 5; ++i) {
		ex_array[i] = 10;
	}

	int* ptr = ex_array;

	*(ptr + 2) = 6; // Sets ex_array[2] = 6
	//    (ptr + 2) adds 2 ints worth of bytes to the position it is pointing
	// at, since it is an int ptr. We add 2 to ptr then dereference it to write
	// to that memory location.

	*(int*)((char*)ptr + 8) = 6; // This does the exact same thing as the above.
	//    It casts ptr to a char* (char is 1 byte). So to get to the index 2
	// we add 8 bytes which is the same amouhnt of bytes as 2 ints. Then we cast
	// back to int so we can set the address to the int 6

	std::cin.get();
	return 0;
}