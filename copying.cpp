//				Copying and Copy Constructors
//    Let's talk about the benefits of copyiing data, variables, and other
// items. Copying can be extremely beneficial, but if the copying is 
// unintended it can be wasteful in the performance department.



//#include <conio.h>
#include "functions.h"

struct Vector2f {
	float x, y;
};


int main(int argc, char** argv) {

	//    Vector b is a literaly copy of a. When we change b.x, a.x
	// remains the same.
	Vector2f a{ 2, 3 };
	Vector2f b = a;
	b.x = 5.f;

	
	std::cin.get();
		return 0;
}