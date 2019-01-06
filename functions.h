#pragma once
#include <random>
#include <set>
#include <iterator>
#include <iostream>

#define LOG(log_msg) std::cout << log_msg << "\n";

//    Create a function that returns a set of random
// numbers.
std::set<int> make_random_set_int(const size_t num_of_elems);

//    Increments param by 1
void increment_value(int* value);