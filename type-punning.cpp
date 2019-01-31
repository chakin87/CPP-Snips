//				Type Punning
//    Getting around the type system in C++. In other languages like, Java, there aren't
// much of a type system.
//    In C++ types are enforced, but you can get around it by accessing the memory directly.
// In some circumstance you shouldn't do this, but in some cases it's really handy. If we
// have a struct, we can write it out as a stream of bytes(in some cases!*) in a byte array.
// Then we can do what we want with the data.




#include "functions.h"
//    Through the power of type punning, I can make this static sized(4 int) STACK allocated
// struct, act just like an array!(A few more functions need to be implemented.
struct IntHolder {
	int x, y, z, a;
	//    This function will return a pointer to the first 'index' of the class(see ex below).
	int* set_array() { return &x; }
	//    This give length of
	int size() { return 4; }
	// 
	int* index = &x;
};


int main(int argc, char** argv) {

	int a = 50;
	//    The asignment below does an implicit conversion. The result in the memory
	// is not the same as &a. Memory &a != &b 
	double b = a; // double b = a; == double b = (double)a;
	std::cout << "a: " << a << ", b: " << b << "\n";
	//    This works but it is not the same value in memory. To grab the memory of a
	// and treat it as a double, we must take the memory address of a and the cast it
	// to a (double*) and then dereference it. See below.
	double c = *(double*)&a;
	std::cout << "\na: " << a << ", b: " << b << ", c: " << c << "\n\n\n";
	//    This results in grabbing the 4 bytes of the in a, but also grabs the other
	// 4 bytes the double needs. (double == 8 bytes). So, what we have done is dangerous,
	// but it is an example of type punning. 
	//    Let's look at a better example.
	IntHolder e = {7, 8, 9, 4};
	//    We can make a raw array out of the struct e. See below. As you can see, this could
	// be very powerful and lets you **treat a struct as a Stack allocated array** ^,^
	int* position = (int*)&e;
	std::cout << "Accesing IntHolder e as an array using int* pos = (int*)&e\n";
	for (int i = 0; i < 4; ++i) {
		std::cout << position[i] << " : ";
	}
	//    For the sake of demonstration, let's see how we grab e.z in this fassion of
	// type-punnin' <-lolz. What we have below is raw memory manipulation. Memory is 
	// one of the biggest thing we have to deal with while programming.
	int ugly_z = *(int*)((char*)&e + 2 * sizeof(int)); // NOTE: DO NOT TRY THIS AT HOME :p

	std::cout << "\ne.z = " << e.z << ", ugly_z = " << ugly_z << "\n";

	for(int j = 0; j < 2; ++j)
	for (int i = 0; i < e.size(); ++i)
		std::cout << "\n incrementing*** and indexing*** " << ++e.index[i];


	std::cin.get();
	return 0;
}