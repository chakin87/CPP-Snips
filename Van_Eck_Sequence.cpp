#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

//std::cout << x;
#define OUT(x) std::cout << x;
#define IN_INT(i)  std::cin >> i;\
	   while(std::cin.fail()) {\
			std::cout << "Integer not entered!" << std::endl;\
			std::cin.clear();\
			std::cin.ignore(256, '\n');\
			std::cout << "Enter an integer: ";\
			std::cin >> i;\
	   }\


int main(int argc, char** argv) {

	unsigned short i;
	unsigned long value = 0;
	std::vector<unsigned long> VanEck_Values;
	
	
	OUT("Welcome to the Van Eck Sequence!");
	OUT("\n\nEnter the number of iterations: ");
	IN_INT(i);
	
	while (i--) {
		VanEck_Values.emplace_back(value);
		OUT("Iteration " << i << ": " << value << "\n");
	

		// Reverse iterate throught VanEck vec to check for values previous loc.
		auto check = std::find(VanEck_Values.rbegin(), VanEck_Values.rend(), value);

		if (check == VanEck_Values.rend()) {
			value = 0;
			continue;
		}
		else {
			auto distance = std::distance(check, VanEck_Values.rbegin());
				value = ++distance;
				OUT(distance);
		}


	}





}