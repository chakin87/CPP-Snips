#include "functions.h"


std::set<int> make_random_set_int(const size_t num_of_elems) {
	std::set<int> return_set;
	std::random_device ran;
	std::mt19937 gen(ran());
	std::uniform_int_distribution<> dis(0, num_of_elems - 1);

	std::generate_n(std::inserter(return_set, return_set.end()), num_of_elems, [&]() {return dis(gen); });

	return return_set;
}

void increment_value(int* value) {
	++(*value);// We derefernce the pointer first, then increment it.
}