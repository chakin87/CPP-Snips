#include "functions.h"


//    I will use O in place of Object(sometimes) to be lazy :p
typedef Object O;

void PrintObject(const O& obj) {
	std::cout << "\nThis is printing an object!\n";
}

int main(int argc, char** argv) {

	//    Normal way to instanciate objects.
	Object a = Object("Chris");
	Object b = Object(22);
	O c("Chris");
	Object d(23);
	//    BUT, you can implicitly instanciate them, as seen below.
	Object e = (const std::string&)"Chris";
	O f = 24;

	//    Implicit call - this will create an Object with the age of 22
	PrintObject(25);
	//    C++ is only allowed to do 1 implicit conversion.
	// So, I first explicitly convert "Chris" from const char* to a std::string.
	// Then c++ converts the string "Chris" intp the Object Ctor Object(std::string name).
	PrintObject((std::string)"Chris");
	// This would not work at all IF I used 'explicit Object(std::string name)' in the 
	// Object struct. Explicit Keyword before a obj or other items will prevent auto 
	// or implicit casting. This will add saftey.


	std::cin.get();
	return 0;
}