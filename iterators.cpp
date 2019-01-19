//					Everything Iterators!
//
//    There are several types of iterators and you are going to learn everything
// you'll ever need to know about iterators in this one file! Money Back Guarantee!
//
//    Iterators behave very similar to pointers. They can be incremented and 
// dereferenced, just like a pointer.
//
//    The Type of the iterator is bound to the type of the class. 
//
//    Iterators can usually be created by the .begin() or .end() funcitions. These
// functions will set the iterator at those positions.
//
//
//    Types of Iterators:	
// 1) Input Iterators - Simplest Iterator. Reads values once and incements.
// 2) Output Iterators
// 3) Forward Iterators
// 4) Bi-directioal Iterators
// 5) Random Access Iterators
//
//    Each of these iterator types have different properties and capabilities 
// according to the container they are associated with. NOTE:**These ITERATOR TYPES
// ARE NOT EXCLUSIVE!** ## ITERATORS MAY HAVE PROPERTIES OF MORE THAN 1 TYPE!##
//
//
//


#include <iostream>
#include <vector>
#include <iterator>
#include <forward_list>
#include <set>
#include "functions.h"

void print(const char* msg) { std::cout << msg << std::endl; }
void print(const char * m, int i) { std::cout << m << ": " << i << std::endl; }

int main() {
//-----------------------------------------------------------------------------//
//-----------------------------Iterator Demonstration--------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Iterator Demo");
	std::vector<int> veci1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//    Here we instanciate a vector<int> iterator named itr1. This iterator will
	// only work on a vector<int>.
	std::vector<int>::iterator itr1;
	//    Grabbing iterators at the end and beginning positions of the vector<int>.
	std::vector<int>::iterator ibegin = veci1.begin();
	std::vector<int>::iterator iend = veci1.end();
	//    Here is the Basic example of an iterator working.
	for (itr1 = ibegin; itr1 < iend; ++itr1) {
		std::cout << *itr1 << " ";
	}
	std::cout << std::endl;

//-----------------------------------------------------------------------------//
//-----------------------------Input Iterators---------------------------------//
//-----------------------------------------------------------------------------//
//
//    Input Iterators can only read a value once and then increment. Then it reads 
// the next value and increments. The input iterator can not do much once it == .end()
//
//
//
//
	print_new_section("Input Iterators");
	double d1 = 0, d2 = 0;

	std::cout << "Two numeric values: " << std::flush;
	std::cin.clear();
	//    The default constructor is end-of-stream - eos.
	std::istream_iterator<double> eos;    
	//    A stdin iterator. - input itr - iitr.
	std::istream_iterator<double> iitr(std::cin);
	//    Check if the cin iterator is end-of-stream.
	if (iitr == eos) {
		print("no values");
		return 0;
	}
	//    Store the contents of *iitr in d1. Space is delimiter.
	else {
		d1 = *iitr++;
	}
	//    Check if the cin iterator is end-of-stream.
	if (iitr == eos) {
		print("no second value");
		return 0;
	}
	//    Store the contents of *iitr in d2. endline is delimiter.
	else {
		d2 = *iitr;
	}
	//    Now we can use what we have pulled from the cin iitr!
	std::cin.clear();
	std::cout << d1 << " * " << d2 << " = " << d1 * d2 << std::endl;




//-----------------------------------------------------------------------------//
//----------------------------Output Iterators---------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Output Iterators");
	//    Create an ostream iterator call output with " " seperating values outputted.
	// The output iterator is defined seperately from std::cout.
	std::ostream_iterator<int> output(std::cout, " ");
	//    First set output = i (cout happens here), then derefernce, then increment output.
	// This will repeat until the end of the loop. output will cout what it's set to.
	for (int i : { 3, 197, 42 }) {
		*output++ = i; 
	}
	output = 1; output = 1; output = 1;
	std::cout << std::endl;



//-----------------------------------------------------------------------------//
//----------------------------Forward Iterators--------------------------------//
//-----------------------------------------------------------------------------//
//

	print_new_section("Forward Iterators");
	std::forward_list<int> flist = { 1, 2, 3, 4, 5 };
	//    This is a forward iterator.(NOTE: Forward iterator cannot be decrementd!)
	// Forward iterators can read, write, and ++. That's about what they can do.
	std::forward_list<int>::iterator fwitr;     

	for (fwitr = flist.begin(); fwitr != flist.end(); ++fwitr) {
		std::cout << *fwitr << " ";
	}
	std::cout << std::endl;

//-----------------------------------------------------------------------------//
//--------------------------Bidirection Iterators------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Bi-directional Iterators");
	std::set<int> set1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//    Bi-directional iterator
	std::set<int>::iterator bitr1;  
	//    We can iterate forward.
	for (bitr1 = set1.begin(); bitr1 != set1.end(); ++bitr1) {
		std::cout << *bitr1 << " ";
	}
	std::cout << std::endl;

	//   And even iterate backward.
	for (bitr1 = set1.end(); bitr1 != set1.begin();) {
		std::cout << *--bitr1 << " ";
	}
	std::cout << std::endl;

	//   Sets make great use of the range-based for loop, ince a bi-directional
	// iterator can do anything a forward iterator can do.
	for (int i : set1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

//-----------------------------------------------------------------------------//
//--------------------------Random Access Iterators----------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Random Access Iterators");
	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int>::iterator it1;   // iterator object

	// iterate forward
	for (it1 = v1.begin(); it1 != v1.end(); ++it1) {
		std::cout << *it1 << " ";
	}
	std::cout << std::endl;

	// iterate backward
	for (it1 = v1.end(); it1 != v1.begin();) {
		std::cout << *--it1 << " ";
	}
	std::cout << std::endl;

	// range-based for loop
	for (int i : v1) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	it1 = v1.begin() + 5;
	print("element begin + 5", *it1);
	print("element [5]", v1[5]);

	it1 = v1.end() - 3;
	print("element end - 3", *it1);


//-----------------------------------------------------------------------------//
//------------------------------End Of Iterators-------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("End Of Iterators");

	WAIT;
	char c;
	std::cin >> c;
	return 0;
}