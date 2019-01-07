#include "functions.h"

#include <algorithm>
#include <future>


int main(int argc, char** argv) {

	int x = 8;
	int k = 8;

	auto f = [&](int msg) {std::cout << msg << "\n"; };
	auto inc = [&](int n) {++n; };

	//    We create a lambda variable 'lam'. The [] is the capture box. 
	// It handles how the variables are captured. & for ref or = for value.
	// Or &x to only take x by ref. Mutable allows lambda to use vars by value
	// in the lambda function.
	auto lam = [=]() mutable{
		ChronoTimer c;
		while (x < 10000)
		{
			LOG(++x);
		}
	};
	lam();

	std::cin.get();
	return 0;
}