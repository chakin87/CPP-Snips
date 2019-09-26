//Make sure to set compiler to c++17

#include <iostream>
#include <any>
#include <variant>
#include <type_traits>
#include <string>


int main(int argc, char** argv) {

	std::any a_variable; // a variable lol.
	a_variable = 2;
	int val = std::any_cast<int>(a_variable);
	std::cout << "a_variable value: " << val << std::endl;

	a_variable = std::string("This is an std::any var");
	std::string val2 = std::any_cast<std::string>(a_variable); // Casting like this creates a copy.
	std::string& valref = std::any_cast<std::string&>(a_variable); // Cast by ref to avoid making a copy.
	std::cout << "a_variable value: " << val2 << std::endl;
	std::cout << "a_variable& value: " << valref << std::endl;


	std::cin >> val;




	return 0;
}