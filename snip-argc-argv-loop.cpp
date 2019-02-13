#include <iostream>



int main(int argc, char** argv) {


	std::cout << "Welcome to the argv loop!\n"
		<< "To use this program, run the .exe this cpp compiles to from terminal\n"
		<< "Example type: './a.out I Love CPP'\n";

	std::cout << "There are " << argc << " arguments in argv.\n"
		<< "Here are the contents of argv[]\n";

	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << "\n";
	}


	getchar();
	return 0;
}