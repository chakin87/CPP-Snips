#include <random>
#include <set>
#include <iostream>
#include <algorithm>
#include <future>
#include <iterator>
#include <cstdio>

#include "ChronoTimer.h"

//    Create a function that returns a set of random
// numbers.

std::set<int> make_random_set_int(const size_t num_of_elems) {
	std::set<int> return_set;
	std::random_device ran;
	std::mt19937 gen(ran());
	std::uniform_int_distribution<> dis(0, num_of_elems - 1);

	std::generate_n(std::inserter(return_set, return_set.end()), num_of_elems, [&]() {return dis(gen); });

	return return_set;
}

int main(int argc, char** argv) {
	//    std::async takes the std::launch::asyc to tell async to start the function
	// immediately, otherwise it may defer the launch. The next param is the function to
	// call. Then we enter the called functions' parameter.
	{
		ChronoTimer c;
		auto futr1 = std::async(std::launch::async, make_random_set_int, (1000000));
		auto futr2 = std::async(std::launch::async, make_random_set_int, (1000000));
		auto futr3 = std::async(std::launch::async, make_random_set_int, (1000000));
		auto futr4 = std::async(std::launch::async, make_random_set_int, (1000000));
		//std::cout << futr1.get().size() << " " << futr2.get().size();
	}
		
	{
		ChronoTimer c;
		auto a = make_random_set_int(1000000);
		auto b = make_random_set_int(1000000);
		auto e = make_random_set_int(1000000);
		auto d = make_random_set_int(1000000);
		//std::cout << a.size() << " " << b.size();
	}



	char pause[10];
	std::cin >> pause;
	return 0;
}