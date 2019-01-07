//				Ternary Operators

//    The ternary operator is short hand for an if else statement.
// 

#include "functions.h"

int main(int argc, char** argv) {

	int s_level = 1;
	int s_speed = 3;


	//    The if else statement below can be achieved with a ternary
	// statement. 
	if (s_level > 5){
		s_speed = 10;
	}
	else {
		s_speed = 5;
	}
	//    Watch the maic of the ternary operator, below!
	s_speed = (s_level > 5) ? 10 : 5;
	//    The tenerary can be useful and shortens simple
	// if statements.

	//    Here is an inline example. The parenthesis around the entire ternary 
	// operation are nessecary in this example.
	std::cout << "The speed is " << (s_speed > 10 ? "less than 10!" : "Greater than 10!");

	//    The ternary operation below sets either a or b to 3
	// if cond is true.
	int a, b;
	bool cond;
	a = 1; b = 2; cond = true;
	(cond ? a : b) = 3;
	std::cout << "\n\n" << a << "," << b << "\n";

	std::cin.get();
	return 0;
}