//				STL CONTAINER STD::DEQUE
//   
//    A deque is similar to a vector in many ways! However, vectors are optimized for
// random access, where as a deque is optimized for rapic push and pops from front or
// back! However, it does allow random accessor iterators!
// 

#include <iostream>
#include <deque>
#include <string>
#include "functions.h"


// report deque info
template <typename T>
void report(T & d) {
	size_t sz = d.size();
	std::cout << "size: " << sz;
	if (sz) std::cout << " front: " << d.front() << " back: " << d.back();
	std::cout << std::endl;
}

// print deque
template <typename T>
void print(T & d) {
	if (d.empty()) return;
	for (auto v : d) std::cout << v << " ";
	std::cout << std::endl;
}

// print a simple message
void print(const char * s) { std::cout << s << std::endl; }

int main() {
	print("Constructing std::deque<std::string>");
	std::deque<std::string> d1 = { "one", "two", "three" };

	print("push_back values");
	d1.push_back("four");
	d1.push_back("five");

	report(d1);
	print(d1);

	print("pop_front");
	d1.pop_front();
	print(d1);

	print("pop_back");
	d1.pop_back();
	print(d1);

	print("push_front");
	d1.push_front("newfront");
	print(d1);

	print("push_back");
	d1.push_back("newback");
	print(d1);



	WAIT;
	return 0;
}
