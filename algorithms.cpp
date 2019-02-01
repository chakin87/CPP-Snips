//				The Algorithms in the STL ALGORITHMS 
//
//
//
//
//
//
//
#include <functional>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

///#include "functions.h"
// 
//-----------------------------------------------------------------------------//
//------------------------ Printing and Utility Functions----------------------//
//-----------------------------------------------------------------------------//
//-
#include <iostream>
#include <string>
#define WAIT std::cin.get();
#define LOG(log_msg) std::cout << log_msg << "\n";
void pad_to(std::string& str, const size_t len, const char padding_char);
void pad_to_offset(std::string& str, const size_t len, int offset, const char padding_char);
void print_new_section(const char * msg_80_chars);
void print_sub_section(const char * msg_80_chars);
void print_note_section(const char * multi_line);
void print_note_sections(const char * multi_line);
//-----------------------------------------------------------------------------//


//
// 
//-----------------------------------------------------------------------------//
//------------------------Some Functions Used in File--------------------------//
//-----------------------------------------------------------------------------//
//
//    print functions
template<typename T>
void print(const T& msg) {
	std::cout << msg << std::endl;
}
template<typename a1, typename a2>
void print(const a1& arg_one, const a2& arg_two) {
	std::cout << arg_one << arg_two << std::endl;
}
template <typename T>
void print(const std::vector<T>& v) {
	if (!v.size()) return;
	std::cout << "Printing std::vector.\n";
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T>& v, const char* vec_name) {
	if (!v.size()) return;
	std::cout << "Printing std::vector " << vec_name << ".\n";
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T>& v, const char* vec_name, const char* vec_type) {
	if (!v.size()) return;
	std::cout << "Printing std::vector<" << vec_type << "> " << vec_name << ".\n";
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T>& v, const char* vec_name, const char* vec_type, bool is_relational) {
	if (!v.size()) return;
	std::cout << "Printing std::vector<" << vec_type << "> " << vec_name << ".\n";
	if (typeid(T) == typeid(bool)) {
		for (bool e : v) { std::cout << (e ? "T" : "F") << " "; }
	}
	else {
		for (T e : v) { std::cout << e << " "; }
	}
	std::cout << std::endl;
}


// 
//-----------------------------------------------------------------------------//
//------------------------Some functors Used in File--------------------------//
//-----------------------------------------------------------------------------//
//
template <typename T>
const bool is_prime(const T & num) {
	if (num <= 1) return false;
	bool primeflag = true;
	for (T l = 2; l < num; ++l) {
		if (num % l == 0) {
			primeflag = false;
			break;
		}
	}
	return primeflag;
}
//    A functor class for getting a product of 2 numbers.
template <typename T>
class productOf {
	T m_val = 0;
	productOf();
public:
	productOf(T n) : m_val(n) {}
	void set(T n) { m_val = n; }
	T get() const { return m_val; }
	T operator() (T n) const { return m_val * n; }
};

template <typename T>
bool is_even(const T & n) {
	return ((n % 2) == 0);
}
template <typename T>
bool is_even_tens(T & n) {
	if (n < 10) return false;
	return ((n / 10) % 2) == 0;
}
template <typename T>
bool is_odd(const T & n) {
	return ((n % 2) == 1);
}
template <typename T>
bool is_odd_tens(const T& n) {
	return(!is_even_tens(n));
}


int main() {
//
// 
//-----------------------------------------------------------------------------//
//------------------------Algorithm Demo---------------------------------------//
//-----------------------------------------------------------------------------//
//

	print_new_section("Algorithm Demo");
	int n = 42;

	int primes[]= { 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 17, 19, 23, 2, 31, 83, 37, 41, 89, 43, 47, 61, 67, 73, 79 };
	std::vector<int> v1_a;
	v1_a.reserve(24);
	auto rand_prime = [&primes]()mutable ->int { return primes[rand() % 25]; };
	//    Insert 10 prime numbers < 100, randomly.
	for (int i = 0; i < 10; ++i) {
		v1_a.push_back(rand_prime());
	}
	print(v1_a, "v1_a - Unsorted", "int");
	std::sort(v1_a.begin(), v1_a.end());
	print(v1_a, "v1_a - Sorted", "int");
	print_note_section("Now, we will use std::binary_search to like for 42");
	if (std::binary_search(v1_a.begin(), v1_a.end(), n)) {
		std::cout << "found " << n << std::endl;
	}
	else {
		std::cout << "did not find " << n << std::endl;
	}



//
// 
//-----------------------------------------------------------------------------//
//------------------------all_of() algorithm-----------------------------------//
//-----------------------------------------------------------------------------//
//
	LOG("\n");
	print_new_section("all_of(), none_of(), etc");
		print_note_sections("The all_of() Algorithm"
		"This algorithm will iterate thorugh a container and check with or not the predicate function is met.");

	const std::vector<int> v1_b = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	print_note_section("Check v1_b vector if all_of(v1_b.begin(), v1_b.end(), is_prime<int>)");
	print(v1_b, "v1_b", "int");
	if (all_of(v1_b.begin(), v1_b.end(), is_prime<int>)) {
		std::cout << "Result: true" << std::endl;
	}
	else {
		std::cout << "Result: false" << std::endl;
	}
	print_note_section("Check v1_b vector if any_of(v1_b.begin(), v1_b.end(), is_prime<int>)");
	print(v1_b, "v1_b", "int");
	if (all_of(v1_b.begin(), v1_b.end(), is_prime<int>)) {
		std::cout << "Result: true" << std::endl;
	}
	else {
		std::cout << "Result: false" << std::endl;
	}
	print_note_section("Check v1_b vector if none_of(v1_b.begin(), v1_b.end(), is_prime<int>)");
	print(v1_b, "v1_b", "int");
	if (none_of(v1_b.begin(), v1_b.end(), is_prime<int>)) {
		std::cout << "Result: true" << std::endl;
	}
	else {
		std::cout << "Result: false" << std::endl;
	}

//
// 
//-----------------------------------------------------------------------------//
//------------------------Search Algorithms -----------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Search Algorithms!!" );
	print_note_sections("The std::find algorithm is really handy!"
	"Let's look at some of the cool things we can di with it!");
	print_note_section("We use std::find to look through v1_b and we are looking for 41");
	auto it1_b = std::find(v1_b.begin(), v1_b.end(), 41);
	if (it1_b != v1_b.end()) {
		//    To get the index, we subtract v1_b.begin() from the iterator.
		size_t index = it1_b -v1_b.begin();
		std::cout << "Result: found at index " << index << ": " << *it1_b << std::endl;
	}
	else {
		std::cout << "Result: not found" << std::endl;
	}
	//---------------------------------------------------
	print_note_sections("We use std::find_if with std::is_odd<int> to look through v1_b."
	"This will return an iterator to the first odd number.");
	auto it2_b = std::find_if(v1_b.begin(), v1_b.end(), is_odd<int>);
	if (it2_b != v1_b.end()) {
		//    To get the index, we subtract v1_b.begin() from the iterator.
		size_t index = it2_b - v1_b.begin();
		std::cout << "Result: found at index " << index << ": " << *it2_b << std::endl;
	}
	else {
		std::cout << "Result: not found" << std::endl;
	}
	// -------------------------------------------------- -
	print_note_sections("We use std::find_if_not with std::is_odd<int> to look through v1_b."
		"This will return an iterator to the first not odd number.");
	auto it3_b = std::find_if_not(v1_b.begin(), v1_b.end(), is_odd<int>);
	if (it3_b != v1_b.end()) {
		//    To get the index, we subtract v1_b.begin() from the iterator.
		size_t index = it3_b - v1_b.begin();
		std::cout << "Result: found at index " << index << ": " << *it3_b << std::endl;
	}
	else {
		std::cout << "Result: not found" << std::endl;
	}
	// -------------------------------------------------- -
	print_note_sections("We use std::find_if_not with std::is_odd<int> to look through v1_b."
		"This will return an iterator to the first not odd number.");
	auto it4_b = std::find_if_not(v1_b.begin(), v1_b.end(), is_odd<int>);
	if (it4_b != v1_b.end()) {
		//    To get the index, we subtract v1_b.begin() from the iterator.
		size_t index = it4_b - v1_b.begin();
		std::cout << "Result: found at index " << index << ": " << *it4_b << std::endl;
	}
	else {
		std::cout << "Result: not found" << std::endl;
	}
	// -------------------------------------------------- -
	print_note_sections("We use std::search within vector v1_b to look for v1_c."
		"This will return an iterator to the first index");
	const std::vector<int> v1_c = { 41, 43, 47, 53, 59, 61, 67, 71};
	auto it5_b = std::search(v1_b.begin(), v1_b.end(), v1_c.begin(), v1_c.end());
	print(v1_b, "v1_b");
	print(v1_c, "v1_c");
	if (it5_b != v1_b.end()) {
		//    To get the index, we subtract v1_b.begin() from the iterator.
		size_t index = it5_b - v1_b.begin();
		std::cout << "Result: found at index " << index << ": " << *it5_b << std::endl;
	}
	else {
		std::cout << "Result: not found" << std::endl;
	}
	// -------------------------------------------------- -
	print_note_sections("There are many other great search algorithms!"
		"Check out std::count() returns number of search parameters found"
		"std::count_if() returns number of predicates found"
		""
		""
		"");
	
	// -------------------------------------------------- -
//
// 
//-----------------------------------------------------------------------------//
//------------------Replacing and Removing Algorithms -------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Replacing and Removing Algorithms");
	print_sub_section("std::replace");
	std::vector<int> v1_d = { 41, 43, 47, 53, 59, 61, 67, 71 };
	print_note_section("std::replace(begin(), end(), searchFor, replaceWith)");
	print(v1_d, "v1_d");
	print_note_section("std::replace(v1_d.begin(), v1_d.end(), 47, 99);");
	std::replace(v1_d.begin(), v1_d.end(), 47, 99);
	print(v1_d, "v1_d");
	//-----------------------------------------------------------
	print_sub_section("std::replace_if");
	std::vector<int> v1_f = {2, 2, 4, 5, 5, 6, 7, 8, 9, 9, 92,86, 41, 43, 47, 53, 59, 63, 67, 71 };
	print_note_section("std::replace_if(begin(), end(), predicate, replaceWith)");
	print(v1_f, "v1_f");
	print_note_section("std::replace_if(v1_d.begin(), v1_d.end(), is_even<int>, 99);");
	std::replace_if(v1_f.begin(), v1_f.end(), is_even<int>, 99);
	print(v1_f, "v1_f");
	//-----------------------------------------------------------
	print_sub_section("std::remove");
	print_note_section("std::remove removes all parameters and");
	print_note_section(" returns an iterator in front of last removed.");
	//std::vector<int> v1_f = { 2, 2, 4, 5, 5, 6, 7, 8, 9, 9, 92,86, 41, 43, 47, 53, 59, 63, 67, 71 };
	print_note_section("std::remove(begin(), end(), predicate,)");
	print(v1_f, "v1_f");
	print_note_section("std::remove(v1_d.begin(), v1_d.end(), 42);");
	auto itr1_f = std::remove(v1_f.begin(), v1_f.end(), 99);
	if (itr1_f == v1_f.end()) {
		print("No elements removed!");
	}
	else{
		print("Resizing v1_f due to removal of elements!");
		v1_f.resize(itr1_f - v1_f.begin());
	}
	print(v1_f, "v1_f");

	print_note_sections("std::remove_if() is the same, except it take a predicate!");
	print_note_sections("std::unique() removes and duplicates in the conainer section searched!");
//
// 
//-----------------------------------------------------------------------------//
//------------------Modifying Algorithms -------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Modifying Algorithms");
	print_sub_section("std::copy()");
	std::vector<int> v1_g = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	std::vector<int> v2_g(v1_g.size(), 0);
	print(v1_g);
	print(v2_g);
	print_note_section("std::copy(v1_g.begin(), v1_g.end(), v2_g.begin());");
	std:: copy(v1_g.begin(), v1_g.end(), v2_g.begin());
	print(v2_g);

	print_note_sections("std::copy_backward same as copy, but it does it backwards. the destination is .end().");
	print_note_sections("std::reverse_copy - copies elements in reverse order to new container");
	print_note_sections("std::reverse - reverses a coinainers elements");
	print_note_sections("std::fill - fills cointainer with parameter");
	print_note_sections("std::fill_n - fills with ");
	print_note_sections("std::genererate - generate predicate values into container.");
	print_note_sections("std::random_shuffle DEPRICATED - shuffle elements in container,");
	print_note_sections("std::shuffle USE THIS INSTEAD- predicate");
	print_note_sections("std::shuffle - use: random_device rd; mt19937 g(rd)); std::shuffle(.begin(), .end(), g);");

// 
//-----------------------------------------------------------------------------//
//-----------------------------Partitions------------ -------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Partitions");
	print_sub_section("std::partition");
	std::vector<int> v1_h = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	print(v1_h, "v1_h");
	print_note_section("std::partition puts the predicate qualifiers to the front of the list, but does not keep order.");
	print_note_section("std::partition(v1_h.begin(), v1_h.end(), is_even_tens<int>);");
	std::partition(v1_h.begin(), v1_h.end(), is_even_tens<int>);
	print(v1_h, "v1_h");
	print_note_section("std::stable_partition does the same, but keeps order. Obviously,"
		"std::stable_partition will be slower and heavier. The convenience may make up for that!");
	print_note_sections("std::partition_copy(v1.begin(), v1.end(), v2.begin(), v3.begin(), predicate) "
		"This will copy the elements that meet the criteria to v2 and the ones that do not will go"
		"int v3. This can be very powerful, as you can imagaine!");


//
// 
//-----------------------------------------------------------------------------//
//-------------------------------Sorting------- -------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Sorting");
	print_sub_section("std::sort();");
	print_note_section("std::sort(v1_j.begin(), v1_j.end()) is the standard std::sort adn will sort < If"
		"you want you can put in your own predicate or functor as the thrid parameter.");
	std::vector<int> v1_j = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
	std::vector<double> v2_j = { 3.07, 2.49, 3.73, 6.58, 3.3, 2.72, 3.44, 8.78, 9.23, 4.09, 4.4, 1.65, 4.92, 0.42, 4.87, 5.03, 3.27, 7.29, 8.4, 6.12 };
	print(v1_j, "v1_j");
	print(v2_j, "v2_j");
	print_note_section("std::sort(v1_j.begin(), v1_j.end()); ");
	std::sort(v1_j.begin(), v1_j.end());
	print(v2_j, "v2_j");
	print_sub_section("std::stable_sort();");
	print_note_section("std::stable_sort() can be used when floating point numbers are being sorted. "
		"std::sort can have trouble sorting by decimal correctly(sometimes, some systems) so if your"
		"sorting is not right, then try std::stable_sort!");
//
// 
//-----------------------------------------------------------------------------//
//--------------------------Merging Sequences----------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Merging Sequences");
	print_sub_section("std::merge()");
	std::vector<int> v1_k = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67 };
	std::vector<int> v2_k = { 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89, 11 };
	std::vector<int> v3_k(v1_k.size() + v2_k.size());
	print(v1_k, "v1_k");
	print(v2_k, "v2_k");
	std::cout << std::endl;
	print_note_section("Using standard std::sort();");
	std::sort(v1_k.begin(), v1_k.end());
	std::sort(v2_k.begin(), v2_k.end());
	print(v1_k, "v1_k");
	print(v2_k, "v2_k");
	std::cout << std::endl;
	std::merge(v1_k.begin(), v1_k.end(), v2_k.begin(), v2_k.end(), v3_k.begin());
	print_note_section("Using std::sort(v1_k.begin(), v1_k.end(), [](int&a, int&b) {return a > b; });"
		"and std::sort(v2_k.begin(), v2_k.end(), [](int&a, int&b) {return a > b; });");
	std::sort(v1_k.begin(), v1_k.end(), [](int&a, int&b) {return a > b; });
	std::sort(v2_k.begin(), v2_k.end(), [](int&a, int&b) {return a > b; });
	print(v1_k, "v1_k");
	print(v2_k, "v2_k");
	std::cout << std::endl;

	//std::merge(v1_k.begin(), v1_k.end(), v2_k.begin(), v2_k.end(), v3_k.begin());
	print(v3_k, "v3_k");
//
// 
//-----------------------------------------------------------------------------//
//------------------------------Binary Searches--------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Binary Searches");
	print_sub_section("std::binary_search();");
	int n_l = 97;
	std::vector<int> v1_l = { 83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97, 7, 61, 73, 3, 79, 37, 43, 17, 5, 89 };
	print(v1_l, "v1_l");
	print_note_section("Sort the vectors with std::sort.");
	std::sort(v1_l.begin(), v1_l.end());
	print(v1_l, "v1_l");

	std::cout << "Binary_Searching(" << n_l << ") [";
	if (std::binary_search(v1_l.begin(), v1_l.end(), n_l)) {
		std::cout << "Found] ";
	}
	else {
		std::cout << "Not Found]";
	}
	std::cout << std::endl;

	//-----------------------------------------------------------------------
	print_sub_section("std::lower_bound();");
	print_note_sections("std::lower_bound returns an iterator to the lowest found parameter.");
	print_sub_section("std::upper_bound();");
	print_note_sections("std::lower_bound returns an iterator to the highest found parameter++"
		"So, using lower_bound and upper_bound you can fid the range or set between the two bounds.");
	print_sub_section("std::equal_range();");
	print_note_sections("std::equal_range returns an std::pair<itr, itr> of the lower_bound itr .first() and the"
		"upper_bound itr .second(). So, it basically does them both in one search!");



	WAIT;
	return 0;
}





// 
//-----------------------------------------------------------------------------//
//-------------------------Defines for the Prototypes--------------------------//
//-----------------------------------------------------------------------------//
//
//-----------------------------------------------------------------------------//
void pad_to(std::string& str, const size_t len, const char padding_char) {
	if (len > str.size()) {
		int front = ((len - str.size()) / 2);
		//int back = ((len - str.size()) / 2);
		str.insert(0, front, padding_char);
		str.insert(str.size(), (len)-str.size(), padding_char);
	}

}
//-----------------------------------------------------------------------------//
void pad_to_offset(std::string& str, const size_t len, int offset, const char padding_char) {
	if (len > str.size()) {
		int front = ((len - str.size()) / 2);
		front -= offset;
		str.insert(0, front, padding_char);
		str.insert(str.size(), (len)-str.size(), padding_char);
	}

}
//-----------------------------------------------------------------------------//
void print_new_section(const char * msg_80_chars)
{
	std::string msg_80(msg_80_chars);
	pad_to(msg_80, 81, '-');
	std::cout << "\n\n"
		"//-----------------------------------------------------------------------------------------------------//\n"
		"//----------" << msg_80 << "----------//\n"
		"//-----------------------------------------------------------------------------------------------------//\n\n";
}
//-----------------------------------------------------------------------------//
void print_sub_section(const char * msg_80_chars)
{
	std::string msg_80(msg_80_chars);
	pad_to(msg_80, 81, '-');
	std::cout << "\n"
		"//----------" << msg_80 << "----------//\n";

}
//----------------------------------------------------------------------------//
void print_note_section(const char * multi_line) {
	int itr = 0;
	std::string top_bot = "";
	pad_to(top_bot, 89, '.');
	//    strlen(char*) best way to get char.size();
	// This for loop fills note_pad indexes with strings around
	// 20 - 30 ish chars.
	std::string note_pad[10]; bool lfspc = false;
	for (int i = 0; i < strlen(multi_line); ++i) {
		if (i > 1 && i % 68 == 0)lfspc = true;
		if (lfspc && multi_line[i] == ' ') {
			lfspc = false;
			++itr;
			continue;
		}
		note_pad[itr] += multi_line[i];
	}
	for (int i = 0; i <= itr; ++i) {
		pad_to_offset(note_pad[i], 89, 0, '.');
		std::cout << "/*[NOTE]" << note_pad[i] << "[NOTE]*/\n";
	}
}
//-----------------------------------------------------------------------------//
void print_note_sections(const char * multi_line)
{
	int itr = 0;
	std::string top_bot = "";
	pad_to(top_bot, 89, '.');
	//    strlen(char*) best way to get char.size();
	// This for loop fills note_pad indexes with strings around
	// 20 - 30 ish chars.
	std::string note_pad[10]; bool lfspc = false;
	for (int i = 0; i < strlen(multi_line); ++i) {
		if (i > 1 && i % 68 == 0)lfspc = true;
		if (lfspc && multi_line[i] == ' ') {
			lfspc = false;
			++itr;
			continue;
		}
		note_pad[itr] += multi_line[i];
	}
	std::cout << "/*[NOTE]" << top_bot << "[NOTE]*/\n";
	for (int i = 0; i <= itr; ++i) {
		pad_to_offset(note_pad[i], 89, 0, '.');
		std::cout << "/*[NOTE]" << note_pad[i] << "[NOTE]*/\n";
	}
	std::cout << "/*[NOTE]" << top_bot << "[NOTE]*/\n";
}
//-----------------------------------------------------------------------------//

