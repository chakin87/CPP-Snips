//        How many times can I say reference? See below!

#include "functions.h"

int main(int argc, char** argv) {
	//    References are not new variables. They are a reference
	// or alias of the variable. Once a reference is set it cannot
	// be set to refernce a different variable. Also, a refernce must
	// be initialized immediately.

	int a = 5;
	//    The & is next to the type and therfore it creates a refernce
	// and is not a memory address.
	int& ref = a;
	LOG(a);// prints 5

	ref = 2;

	LOG(a);// prints 2 now that the reference changed the value of what it references

	//increment_value(a);// takes an int pointer as its param
	// If we try to pass an int instead of a ptr or ref, it doesn't work.
	// We can pass a by reference.
	increment_value(&a);
	LOG(a);// prints 3

	increment_value(&ref);
	LOG(a);// prints 4

	std::cin.get();
	return 0;
}