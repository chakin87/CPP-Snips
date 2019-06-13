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
	unsigned short index = 0;
	unsigned long value = 0;
	std::vector<unsigned long> VanEck_Values;
	
	
	OUT("Welcome to the Van Eck Sequence!");
	OUT("\n\nEnter the number of iterations: ");
	IN_INT(i);
	
	VanEck_Values.emplace(VanEck_Values.end(), value);

	while (i--) {
		
		VanEck_Values.emplace(VanEck_Values.end(), value);
		OUT("Iteration " << index++ << ": " << value << "\n");
	

		// Reverse iterate throught VanEck vec to check for values previous loc.
		auto check = std::find(VanEck_Values.rbegin()+1, VanEck_Values.rend(), value);

		if (check == VanEck_Values.rend()) {
			value = 0;
		//	OUT("\n        IN  IF     \n");
			continue;
		}
		else {
			auto distance = std::distance(VanEck_Values.rbegin(), check);
				value = distance;
			//	OUT("distance: " << distance << "\n");
			//OUT("\n        IN  else    \n");

		}


	}





}