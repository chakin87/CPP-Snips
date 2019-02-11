#include <iostream>
#include <type_traits>
#include <typeinfo>



template <typename T>
void PrintVarInfo(const T& var, const char* varName) {
	const std::type_info& r1 = typeid(var);
	std::cout << "***********************************************************************\n";
	if (std::is_pointer<T>::value) {
		std::cout << varName << " is pointing to:" << " [" << var << "]\n";
	}
	else {
		std::cout << "Value of " << varName << " is:    [" << var << "]\n";
	}
	std::cout << "Address of " << varName << " is:  [" << &var << "]\n";
	std::cout << "Type of " << varName << " is:     [" << r1.name() << "]\n";
	std::cout << "Size of " << varName << " is:     [" << sizeof(var) << "](bytes)\n";
	std::cout << "Size of " << varName << " is:     [" << (sizeof(var)) * 8 << "](bits)\n";
	std::cout << "***********************************************************************\n";
}


// Prints var info, including min and max.
template <typename T>
void PrintVarInfoFull(T var, const char* varName = "", const char* header = "", const char* footer = "") {
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


int main(int argc, char** argv) {

	int a = 5;

	PrintVarInfo(a, "a");

	getchar();
	return 0;
}