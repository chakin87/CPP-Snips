//				Templates!
//    Templates allows you to define a template that will be compiled by the use
// case. When you write a template function you are writing a blueprint function.
// The compiler will determine the appropriate type/types to use and then it will
// complile a function that meets those needs.


#include "functions.h"

//    An array allocated on the stack with a size that is unknown at compile time.
// This cannot be done with traditional methods, but a template will let us do it.
template<typename T, int N>
class StackArray {
private:
	T m_array[N];
public:
	int size() const { return N; }
};

//    Let's look at a simple example, to get started. Here we have 3 different 
// functions that are all very similar, but have different parameters.
void print(int i) { std::cout << i << "\n"; }
void print(std::string s) { std::cout << s << "\n"; }
void print(float f) { std::cout << f << "\n"; }
//    We can accomplish all 3 of those overloaded functions, and more, in one 
// template function. Look below
template<typename T>
void print(T t) { std::cout << t << " USED TEMPLATE f(x)\n"; }

int main(int argc, char** argv) {

	//    This is just scratching the surface but you can see how powerful
	// templates can be.
	StackArray<int, 25> a;
	StackArray<std::string, 25> b;


	bool t = true;
	print(25);
	print("const char*");
	print(3.1459);
	print(3.1459f);
	print(3.14592134l);
	print((std::string)"std::string");
	std::cout << std::boolalpha;
	print(t);
	//    Template functions can also be used as seen below.
	print<int>(3.1459); // Prints 3 through the template f(x).

	std::cin.get();

	return 0;
}