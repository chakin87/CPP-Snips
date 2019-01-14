//				STL CONTAINER STD::MAP
//				
//    The std:: class provides a sorted set of key-value pairs, similar to an associative array. 			
//				
//				
//				
//		multimap must use .find() vs [] or .at()		
//				
//			


#include <iostream>
#include <string>
#include <map>
#include "functions.h"

// print a pair
template <typename T1, typename T2>
void print_pair(std::pair<T1, T2> & p) {
	std::cout << p.first << ": " << p.second << std::endl;
}

//    Print the elements of the map.
template<typename T>
void print(T & m) {
	if (m.empty()) return;
	for (auto x : m) print_pair(x);
	std::cout << std::endl;
}

//    Print a simple message.
void print(const char * m) { std::cout << m << std::endl; }
template <typename T>
void print(const char * m, const T & v) { std::cout << m << ": " << v << std::endl; }



int main() {
	print("map of strings from initializer list");
	std::map<std::string, std::string> mapstr = { { "George O'Malley", "Father of Disaster, Blind to Busses" }, { "Ellen Degenerisss", "Mother-Lover" },
		{ "Ruth", "Dancer" }, { "Spike Lee", "Neighbor's Son's Friend's Director" } };

	print("size", mapstr.size());
	print("get some values");
	print("George O'Malley", mapstr["George O'Malley"]);
	print("Ellen Degenerisss", mapstr.at("Ellen Degenerisss"));
	print("Spike Lee", mapstr.find("Spike Lee")->second);
	print("print_map:");
	print(mapstr);

	print("insert an element");
	mapstr.insert({ "Luke", "Neighbor" });
	print("size", mapstr.size());
	print(mapstr);

	std::cout << "insert a duplicate:" << std::endl;
	auto rp = mapstr.insert({ "Luke", "Neighbor" });
	if (rp.second) {
		print("insert succeeded");
		print_pair(*rp.first);
	}
	else {
		print("insert failed");
	}
	print("size", mapstr.size());
	print(mapstr);

	print("find and erase Spike");
	auto it = mapstr.find("Spike");
	if (it != mapstr.end()) {
		print("found");
		print_pair(*it);
		mapstr.erase(it);
		print("erased");
	}
	else {
		print("not found");
	}
	print("size", mapstr.size());
	print(mapstr);



	WAIT;
	return 0;
}