#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <type_traits>

// Allows you to use string features and use strings in cout and such.
#include <string>

// Allows you to check the limits of variables.
#include <limits>

// This is a global variable. The scope is 'Global.'
int g_iRandNum = 0;

// A const variable..
const double PI = 3.1415926535897932;

// Prints var info, including min and max.
template <typename T>
void PrintVarInfoFull(T& var, const char* varName = "", const char* header = "", const char* footer = "") {
	size_t vmin = std::numeric_limits<T>::min();
	size_t vmax = std::numeric_limits<T>::max();
	const std::type_info& r1 = typeid(var);
	std::cout << "***********************************************************************\n";
	std::cout << header << (header != "" ? ("\n") : "");
	std::cout << "Type of " << varName << " is:       [" << r1.name() << "]\n";
	std::cout << "Value of " << varName << " is:      [" << var << "]\n";
	std::cout << "Max Value of " << varName << " is:  [" << vmax << "]\n";
	std::cout << "Min Value of " << varName << " is:  [" << vmin << "]\n";
	std::cout << "Address of " << varName << " is:    [" << &var << "]\n";
	std::cout << "Size of " << varName << " is:       [" << sizeof(var) << "](bytes)\n";
	std::cout << "Size of " << varName << " is:       [" << (sizeof(var)) * 8 << "](bits)\n";
	std::cout << footer << (footer != "" ? ("\n") : "");
	std::cout << "***********************************************************************\n";
}
// COUT args: (T var, const char* varName = "", const char* header = "", const char* footer = "") 
#define COUT(...) PrintVarInfoFull(__VA_ARGS__)

int main() {


	// bools store true 1, or false 0
	bool myTrueBool = true;
	COUT(myTrueBool, "myTrueBool");

	// Single char; Use '' to represent char.
	char chMyGrade = 'A';
	COUT(chMyGrade, "chMyGrade");
	// Unsigned means UNable to go below 0.
	// Unsigned allows for double the max value, while 
	// sacrificing negative numbers.
	// unsigned short ints hold values from 0 to 65,535
	// unsigned int & unsigned long int double their max value
	unsigned short int age = 43;
	COUT(age, "age");
	// short ints store between -32,768 to 32,767
	short int myShortInt = 180;
	COUT(myShortInt, "myShortInt");
	// ints range from -2147483648 to 2147483647
	int regularInt = 7;
	COUT(regularInt, "regularInt");
	// Big Big int, High values.
	long long intnum = 1000000;
	COUT(intnum, "intnum");
	// floats range from 1.17549e-38 to 3.40282e+38
	float NotThePieYouEat = 3.14159;
	COUT(NotThePieYouEat, "NotThePieYouEat");
	// Between OS' the precision of floats and doubles will vary.


	// long doubles range from 3.3621e-4932 to 1.18973e+4932
	constexpr long double BigPie = 3.1415926535897932;
	COUT(BigPie, "BigPie");
	// You can have the compiler assign a type
	auto compilerDeterminsType = true;
	COUT(compilerDeterminsType, "compilerDeterminsType");

	printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi");

	PrintVarInfoFull(BigPie, "BigPie");



	getchar();
	return 0;
}