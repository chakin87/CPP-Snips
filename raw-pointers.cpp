//        Raw Pointers and everything they point to!

#include <iostream>

#include "functions.h"

//    A pointer is integer that stores an address.
// If you declare a char pointer, then you are telling
// the pointer that a char is presumably at the address.

int main(int argc, char** argv) {

	int var = 8;
	//    a void pointer means that we do
	// not care what type the actually data
	// it points to. We just want
	// to hold an address.
	void* ptr = nullptr;

	ptr = &var;
	//    If we look at the memory in this line of the program,
	// we will see that ptr points to the address of var and at
	// that address is 4 bytes(sizeof int). The 4 bytes = 08 00 00 00
	// As you can see the value at the address is 8.

	int* ptr2 = &var;
	double* ptr3 = (double*)&var;
	//    Looking above, we find that at this line in the program 
	// both ptrs will point to the same address that holds the value 8.

	//    If we want to modify var with a pointer, we need to use a ptr that 
	// is the same type of the type that it points to. This is so that the 
	// compiler knows how to handle what we are accessing and how many bytes
	// it is. 
	
	int var2 = 10;
	int* ptr4 = &var2;

	//    To read and write to the address the pointer points to,
	// we must 'derefernce' the pointer, as seen below*.

	*ptr4 = 20;
	LOG(*ptr4); // prints 20
	LOG(var2);  // prints 20 because we modified the memory with ptr4

	//    The types in c++ allocate different amount of bytes. An int is 4 bytes
	// while a char is 1 byte.
	//    I declare a char* that allocates a block of 8 bytes in memory ON THE HEAP!
	// NOTE: Using the new keyword allocates to the Heap and memory must be deallocated!
	char* buffer = new char[8];
	// buffer will return the start(first byte) of the address of the block of 8 bytes.

	//    memset function fill a block of memory with data that we specify.
	// - memset params -
	// 1) a pointer to the beginning of the block of memory.
	// 2) The value
	// 3) How many bytes should it fill.
	memset(buffer, 0, 8);
	// So, at the addres buffer points to we add 0 to 8 bytes.
	// If we look at the memory at the addres that buffer points to,
	// we will see that it is all 0s. We are done with buffer so we 
	// must delete or it from the Heap. Since it is an array we use 
	// the delete[] keyword instead.

	//SIDE NOTE: double ptr.
	char** bufptr = &buffer; 
	//    bufptr just points to the address that buffer is at and not
	// the address that buffer points to.

	delete[] buffer;

	std::cin.get();
	return 0;
}