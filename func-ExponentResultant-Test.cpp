#include <iostream>
// There are better ways to do this, but heres one way lolz.
int ExponentResultant(int coefficient, int power) {
	int result = 1;

	for (int i = 0; i < power; ++i) {
		result *= coefficient;
	}
	return result;
}


// This PrintInt(args) function is for demonstration purposes only. It is not efficient at all
// as for as the assembly that it compiles.
void PrintInt(int var, const char* varName, const char* title = "", const char* append = "") {
	std::cout << title << (title != "" ? ("\n") : "")
		<< "[" << varName << "]{" << var << "}\n"
		<< append << (append != "" ? ("\n") : "");
}

int main(int argc, char** argv) {

	int x = 2, y = 5, z = 0;

		PrintInt(x, "x", "Initial Value of x");
		PrintInt(y, "y", "Initial Value of y","\n");

	if (x < y) {
		x += y;
		PrintInt(x, "x", "Value after x += y;");
		PrintInt(y, "y", "Value after x += y;", "\n");
		y = x - y;
		PrintInt(x, "x", "Value after y = x - y;");
		PrintInt(y, "y", "Value after y = x - y;", "\n");
		x -= y;
	}
	PrintInt(x, "x", "Value after x -= y;");
	PrintInt(y, "y", "Value after x -= y;", "\n\n");

	z = ExponentResultant(x, y);

	PrintInt(x, "x", "Value after z = ExponentResultant(x, y);");
	PrintInt(y, "y", "Value after z = ExponentResultant(x, y);");
	PrintInt(z, "z", "Value after z = ExponentResultant(x, y);");


	getchar();
	return 0;

}