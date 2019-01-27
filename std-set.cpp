//					STL CONTAINE STD::SET!
//
//    The std::set is a container that holds a SORTED set of elements. std::set
// can only hold unique elements (no duplicates).
//
//  The std::multiset is a container that holds a SORTED set of elements. std::set
// CAN HOLD DUPLICATES.
//
//    The std::unordered_set is a container that holds an unsorted set of elements. std::set
// can only hold unique elements (no duplicates). The unordered_set provides hashed keys for 
// faster access!
//
//  The std::unordered_multiset is a container that holds an unsorted set of elements. std::set
// CAN HOLD DUPLICATES.
//
//    A lot of vareity in the four types of sets!
//
//    Let's look at some basic and advanced use cases!
//
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

#include "functions.h"



//    Print the elements of the set.
template<typename T>
void print(T & s) {
	if (s.empty()) return;
	for (auto x : s) std::cout << x << " ";
	std::cout << std::endl;
}

//    Print a simple message.
void print(const char * m) { std::cout << m << std::endl; }
template <typename T>
void print(const char * m, const T & v) { std::cout << m << ": " << v << std::endl; }

int main() {
	print("construct set set1");
	//    Try switching from set and multiset
	std::set<std::string> set1 = { "one", "two", "three", "four", "five" };
	//std::multiset<std::string> set1 = { "one", "two", "three", "four", "five" };
	print("size of set", set1.size());
	print("ordered set is alphabetical");
	print(set1);

	print("insert element six");
	set1.insert("six");
	print(set1);

	print("find and erase element six");
	std::set<std::string>::iterator it = set1.find("six");
	if (it != set1.end()) {
		print("erasing", *it);
		set1.erase(it);
	}
	else {
		std::cout << "not found" << std::endl;
	}
	print(set1);
	//    Here we try to insert a duplicate. The .instert() returns a pair, one iterator to the
	// item that was inserted or the item that prevented the duplicate from being inserted,
	// and second .insert() returns a bool t or f if item was inserted succesfully!
	// Let's see .insert() in action!
	print("inserting duplicate element five");
	auto rpair = set1.insert("five");
	if (!rpair.second) {
		print("insert failed", (*rpair.first));
	}
	print(set1);
	std::cout << std::endl;


	print("construct unordered set set1");
	std::unordered_set<std::string> set2 = { "one", "two", "three", "four", "five" };
	print("size of set", set2.size());
	print("unordered set has no defined order");
	print(set2);

	print("insert element six");
	set2.insert("six");
	print(set2);

	print("find and erase element six");
	auto it2 = set2.find("six");
	if (it2 != set2.end()) {
		print("erasing", *it2);
		set2.erase(it2);
	}
	else {
		std::cout << "not found" << std::endl;
	}
	print(set2);

	print("inserting duplicate element five");
	set2.insert("five");
	print(set2);
	std::cout << std::endl;



	WAIT;
	return 0;
}