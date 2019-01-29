//				Function Pointers 
//    Functions are just cpu instructions(upon compiliation). So, what function 
// pointers do is when the function is called, the function pointer points to those
// cpu instructions.
//NOTE:**A function pointer is a not-so-anonomous lambda.**




#include "functions.h"
#include <vector>


void print_love() {
	std::cout << "\nI love programming!\n"
		"The best programs are programmed by programmers that love programming!\n";
}

void print_love(const std::string& name) {
	std::cout << "\nI, " << name << ", love programming!\n"
		"The best programs are programmed by programmers that love programming!\n";
}

//    Here is a function that takes a function pointer as a parameter.
void for_each_vec(const std::vector<std::string>& vec, void(*func)(const std::string&)) {
	for (std::string str : vec) {
		std::cout << str << " says: \n "; 
		func(str);
		std::cout << str << "\n\n\n";
	}
}

int main(int argc, char** argv) {
	//    Below are function pointers for the no-parameter print fucntion.
	// all are equivelent. Ref or no ref, I believe it is converted to ref.
	void(*a)();
	a = &print_love;

	typedef void(*function_ptr)();
	function_ptr fp = print_love;

	a();
	fp();
	//auto b = &print_love();

	//    Below are function pointers for the string parameter print fucntion.
	typedef void(*sfunction_ptr)(const std::string&);
	sfunction_ptr sfp1 = print_love;

	sfp1("Chris");


	//    Here is the vector scenario. We pass a vector of strings into a function along
	// with a function pointer. So much could be done with this, but lets see this example.
	std::vector<std::string> v;
	v.reserve(3);
	v.emplace_back("one of the Jonas brothers");
	v.emplace_back("Bill from accounting");
	v.emplace_back("Michael Bolton of Compu-Tech");

	for_each_vec(v, sfp1);

	std::cout << "\n\n";
	//    Similiarly, a lambda could be used.
	for_each_vec(v, [](const std::string& s) {
		std::cout << s << (s[0] == 'o' ? " is a goose!" :
			s[0] == 'B' ? " is a Jackal Crack!" :
			s[0] == 'M' ? " is a Bad-A$$!" : " is someone that I haven't hard-coded into this lambda"); });

	std::cin.get();
	return 0;
}