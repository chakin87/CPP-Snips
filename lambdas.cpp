#include "functions.h"

int main(int argc, char** argv) {

	int x = 8;


	//    We create a lambda variable 'lam'. The [] is the capture box. 
	// It handles how the variables are captured. & for ref or = for value.
	// Or &x to only take x by ref. Mutable allows lambda to use vars by value
	// in the lambda function.
	auto lam = [=]() mutable{
		LOG(x);
		++x;
		LOG(x);
	};
	lam();

	std::cin.get();
	return 0;
}