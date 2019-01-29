//				STD::TRANSFORM
//
//     One thing I want to mention about this std-transform.cpp file. This   
// file is meant to be used as a reference for myself and anyone else that 
// can find value in it. That being said, the code you see is NOT optimized
// and some of it may not be best practice.
//
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include "functions.h"


//-----------------------------------------------------------------------------//
//------------------------Some Functions Used in File--------------------------//
//-----------------------------------------------------------------------------//
//

template <typename T>
class randomize {
	T m_val = 0;
	randomize() {}
public:
	randomize(T n) : m_val(n){}
	T operator() (T y) {
		m_val += y; 
		m_val *= rand() % 114;
		m_val /= 14;
		int ret = m_val;
		m_val = 1;
		return ret; 
	}
};
//    The accumulate functor class is used in the fist demonstration.
template <typename T>
class accumulate {
	T m_val = 0;
	accumulate() {}
public:
	accumulate(T n) : m_val(n) {}
	T operator() (T y) { m_val += y; return m_val; }
};

//    The accumulateProduct
template <typename T>
class accumulateProduct {
	T m_val = 1;
public:
	accumulateProduct() : m_val(1) {}
	accumulateProduct(T n) : m_val(n) {}
	T operator() (T y) { m_val *= y; return m_val; }
	T operator() (const T& lhs, const T& rhs) { return m_val *= lhs * rhs;  }
};

template<typename T>
void print(const T& msg) {
	std::cout << msg << std::endl;
}
void print(std::string & s, const char* string_name) {
	if (!s.size()) { return; }
	std::cout << "Printing std::string " << string_name << std::endl;
	for (int i = 0; i < s.size(); ++i) { std::cout << s[i]; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T> & v) {
	if (!v.size()) { return; }
	std::cout << "Printing std::vector " << std::endl;
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T> & v, const char* vec_name) {
	if (!v.size()) { return; }
	std::cout << "Printing std::vector " << vec_name << std::endl;
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T> & v, const char* vec_name, const char* vec_type) {
	if (!v.size()) { return; }
	std::cout << "Printing std::vector<"<< vec_type<< "> " << vec_name << std::endl;
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T> & v, const char* vec_name, bool is_comma_seperated) {
	if (!v.size()) { return; }
	std::cout << "Printing std::vector " << vec_name << std::endl;
	for (T e : v) { 
		if (is_comma_seperated) { is_comma_seperated = false; }
		else
		std::cout << e; 
	}
	std::cout << std::endl;
}

//    Here is a simple functor class that we will use in the String Transform
// demonstration. ex 'the apple is junk' to 'The Apple Is Junk'.
class title_case {
	char m_lastch;
	char m_sepch = 0;
public:
	title_case() : m_lastch(0) {}
	title_case(const char c) : m_lastch(1), m_sepch(c) {}
	//const char operator() (const char c);

const char operator() (const char c) {
	if (m_sepch) m_lastch = (!m_lastch || m_lastch == m_sepch) ? toupper(c) : c;
	else m_lastch = (!m_lastch || isblank(m_lastch)) ? toupper(c) : c;
	return m_lastch;
}
};
//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
	srand(time(NULL));
	//-----------------------------------------------------------------------------//
	//---------------------------------Demonstration-------------------------------//
	//-----------------------------------------------------------------------------//
	//
	print_new_section("Transform Accumulate");
	accumulate<int> a(7);
	std::cout << "accumulate a: " << a(7) << std::endl;

	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9,
							10, 11, 12, 13, 14, 15, 16,
							17, 18, 19, 20, 21, 22, 23 };
	print(v1);
	print("Transfoming with a()");
	std::vector<int> v2(v1.size());
	std::transform(v1.begin(), v1.end(), v2.begin(), a);

	print(v2);


	//-----------------------------------------------------------------------------//
	//---------------------------------Randomize XForm-----------------------------//
	//-----------------------------------------------------------------------------//
	//
	print_new_section("Transform Randomize");
	randomize<int> r(1);
	std::vector<int> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9,
						10, 11, 12, 13, 14, 15, 16,
						17, 18, 19, 20, 21, 22, 23 };
	print(v3);
	print("Transfoming with a()");
	std::vector<int> v4(v3.size());
	std::transform(v3.begin(), v3.end(), v4.begin(), r);
	print(v4);


	//-----------------------------------------------------------------------------//
	//------------------------------Lambda in Transfrom----------------------------//
	//-----------------------------------------------------------------------------//
	//
	print_new_section("Lambda in Transfrom");

	auto lambda = [](int& a) mutable->int {a *= rand() % 20; a *= (a % 2) + 1; return a; };

	std::vector<int> v5 = { 1, 2, 3, 4, 5, 6, 7, 8, 9,
					10, 11, 12, 13, 14, 15, 16,
					17, 18, 19, 20, 21, 22, 23 };
	print(v5);
	print("Transfoming with lambda[](int& a)"
		"{a *= rand() % 20; a *= (a % 2) + 1; return a;}");
	std::vector<int> v6(v5.size());
	std::transform(v5.begin(), v5.end(), v6.begin(), lambda);
	print(v6);
	//-------------------------------------------------
	std::vector<std::string> v5s = { "one", "two", "three", "four", "five",
						"six", "seven", "eight", "nine", "ten",
						"eleven", "twelve", "thirteen", "fourteen",
						"fifteen", "sixteen", "seventeen", "eighteen",
						"nineteen", "twenty", };
	print(v5s);
	print("Transform string vec with [](std::string& s){std::toupper(s[0]);}");
	std::vector<size_t> v6s(v5s.size());
	std::transform(v5s.begin(), v5s.end(), v6s.begin(), [](std::string& s) ->size_t {return s.size(); });
	print(v6s);

	//-----------------------Not Working Yet----------------------------//
	print_sub_section("Not Working Yet");
	std::vector<std::string> v5ss = { "one", "two", "three", "four", "five",
					"six", "seven", "eight", "nine", "ten",
					"eleven", "twelve", "thirteen", "fourteen",
					"fifteen", "sixteen", "seventeen", "eighteen",
					"nineteen", "twenty", };
	print(v5ss);
	print("Transform string vec with [](char c) {return static_cast<char>(std::toupper(c)); }");
	std::vector<std::string> v6ss(v5ss.size());
	std::transform(v5ss.begin(), v5ss.begin() + 1, v6ss.begin(),
		[](std::string& s) ->std::string {static_cast<char>(std::toupper(s[0])); return (std::string)s; });
	print(v6ss);
	//---------------------------------------------------------------


	//-----------------------------------------------------------------------------//
	//------------------------------String   Transfroms----------------------------//
	//-----------------------------------------------------------------------------//
	//
		//   This section will show that an indidual string is basiccally a
		// container. Therfore, it can be used as such!
	print_new_section("String Transfrom");
	std::string s1 = "this is a string";
	print(s1, "s1");

	std::string s2(s1.size(), '.');
	print(s2, "s2");
	transform(s1.begin(), s1.end(), s2.begin(), std::toupper);

	print(s2, "s2 - after transform"
		"(s1.begin(), s1.end(), s2.begin(), ::toupper);");

	transform(s1.begin(), s1.end(), s2.begin(), std::tolower);

	print(s2, "s2 - after transform"
		"(s1.begin(), s1.end(), s2.begin(), std::tolower);");
	//    Notice when we pass title_class, we use (), because we are using the class
	// and not an object of the class. we could pass 't' from title_case t; -same result.
	transform(s1.begin(), s1.end(), s2.begin(), title_case());
	print(s2, "s2 - after transform"
		"(s1.begin(), s1.end(), s2.begin(), title_case());");



	//-----------------------------------------------------------------------------//
	//------------------------------Binary   Transfroms----------------------------//
	//-----------------------------------------------------------------------------//
	//
		//    The binary transform override in use!
	print_new_section("Binary Transfroms");
	std::vector<long> vb1 = { 1, 2, 3, 4 ,5 };
	std::vector<long> vb2 = { 5, 10, 15, 20, 25 };
	std::vector<long> vb3(vb1.size(), 0);
	accumulateProduct<long> funcap;

	print(vb1, "vb1");
	print(vb2, "vb2");
	print(vb3, "vb3");
	std::cout << std::endl;

	transform(vb1.begin(), vb1.end(), vb2.begin(), vb3.begin(), funcap);
	print(vb1, "vb1");
	print(vb2, "vb2");
	print(vb3, "vb3");
	//    As you can see, this transform override is very powerful and it can be 
	// used with most of the STL Functors. Also, you can send the results to any
	// vector, you do not need a third vector.


//-----------------------------------------------------------------------------//
//------------------------------Type     Transfroms----------------------------//
//-----------------------------------------------------------------------------//
//
	//    Type1 to type 2
	class uint64tostring {
		std::string m_str;
	public:
		uint64tostring():m_str("") {}
		std::string operator() (const uint64_t& i) { return m_str = std::to_string(i); }
	};
	print_new_section("Type Transfroms");
	const std::vector<uint64_t> v64i = { 11, 22, 33, 44, 55, 66, 77, 88, 999, 123456789 };
	print(v64i, "v64i");

	std::vector<std::string> vstr1(v64i.size());
	transform(v64i.begin(), v64i.end(), vstr1.begin(), uint64tostring());
	print(vstr1, "vstr1", "std::string");



	WAIT;
	return 0;
}

