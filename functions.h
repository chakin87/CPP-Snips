#pragma once
#include <random>
#include <set>
#include <iterator>
#include <iostream>
#include <string>

#include "ChronoTimer.h"

#define LOG(log_msg) std::cout << log_msg << "\n";
#define LOGt(log_msg) std::cout << log_msg << "\n"

//    Create a function that returns a set of random
// numbers.
std::set<int> make_random_set_int(const size_t num_of_elems);

//    Increments param by 1
void increment_value(int* value);

//    Demonstration Object

struct Object {
public: // Constructors
	Object() {
		LOG(__FUNCTION__ << " Constructed - Ctor: 0, Name: " << m_name <<", Age: " << m_age << "\n")
	}
	Object(const std::string& name)
		:m_name(name), m_age(-1) {
		LOG(__FUNCTION__ << " Constructed - Ctor: 1, Name: " << m_name << ", Age: " << m_age << "\n")
	}
	Object(int age)
		:m_age(age), m_name("Unknown") {
		LOG(__FUNCTION__ << " Constructed - Ctor: 2, Name: " << m_name << ", Age: " << m_age << "\n")
	}

public: // Methods
	inline const std::string getName() { return m_name; } 
	inline const int getAge() { return m_age; } 
private: // Members
	std::string m_name;
	int m_age;

};