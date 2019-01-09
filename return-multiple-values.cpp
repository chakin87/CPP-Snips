//				How to Return Muliple Values from a Function!


#include "functions.h"


//    Here is a function that returns 2 strings. 
// You could pass 2 string& into the params and then modify them in the
// function.(pretty efficient) Besides that, you can make the function return 
// a pair<string, string>. might be good for parsing a shader and returning a
// vertex and fragment shader. 

std::pair<std::string, std::string> parse_it() {
	std::string s1, s2;
	// Function does its parsing...
	return std::make_pair<s1, s2>;
}
//    The above function could be done with std::array return. It could return
// an array of strings. You can also do this with a function that returns a vector.
// A tuple would work as well, but I don't like them.
//    My favorite way is to create a struct that is tailored to the function returns.
// this way it is all done on the stack and it is easy to determine what value is what.

struct RetVal {
	std::string big, small;
};
RetVal parse_it_well() {
	RetVal r;
	// Function does its parsing...
	r.big = "This is the big string that needed parsed";
	r.small = "This is the small part";
	return r;
}



int main(int argc, char** argv) {



	std::cin.get();

	return 0;
}
