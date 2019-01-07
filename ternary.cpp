//				Ternary Operators

//    The ternary operator is short hand for an if else statement.
// 

#include "functions.h"

int main(int argc, char** argv) {

	static int s_level = 1;
	static int s_speed = 3;


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

	//    Here is an inline example.




	std::cin.get();
	return 0;
}