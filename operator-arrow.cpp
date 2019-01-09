#include "functions.h"

struct Vector3i {
	//    The offsets of this struct will be in 4 bytes (int).
	// x is at 0 bytes, then y is 4 bytes, and z is at 8 bytes.
	// 
	int x, y, z;
};

int main(int argc, char** argv) {

	//    Grab the offset of a member. This is not the offset 
	// from the memory address, but from zero.
	// Below, we cast 0 or nullptr into a Vector3i pointer. Then
	// use the -> to acces x. Looks like : ((Vector3i*)nullptr)->x;
	// That will give you an invalid address. So we must take the ref.
	// Looks like &((Vector3i*)nullptr)->x; This gives the offset. We 
	// then cast it to an integer. Looks like (int)&((Vector3i*)nullptr)->x;
	// Now we have the offset in int (4 byte) increments.
	int offsetx = (int)&((Vector3i*)nullptr)->x;
	int offsety = (int)&((Vector3i*)nullptr)->y;
	int offsetz = (int)&((Vector3i*)nullptr)->z;

	std::cout << "[offset x]: " << offsetx << "\n"; // [offset x]: 0
	std::cout << "[offset y]: " << offsety << "\n"; // [offset y]: 4
	std::cout << "[offset z]: " << offsetz << "\n"; // [offset z]: 8

	//    We used the -> operator to grab an offset from memory. This 
	// can be useful when you are trying to serialize data into a a stream of bytes
	// and you want to figure out offsets of certain things.

	std::cin.get();
	return 0;
}