

// L Values and R Values names originate from lhs and rhs from assignment operator.
// An lvalue is anything on the left side of an assignment operator and rvalue is 
// what is on the right side of an assignment operator.
// An lvalue for example, x=2; x is an lvalue. Where as 2+2 is a rvalue expression.
// In C++11, the && operator stands for a rvalue reference.
//
//
//
#include <iostream>
// Demonstrational overloaded function..
void intPrint(int& i) { std::cout << "lvalue ref " << i << std::endl; }
void intPrint(int&& i) { std::cout << "rvalue ref " << i << std::endl; }
//----------------------------------------------------------------------//
class BigClass {
public:
	BigClass() {};
	// The copy constructor makes a deep copy.
	BigClass(const BigClass& rhs) { // Copy Ctor
		m_size = rhs.m_size;
		m_darr = new double[m_size];
		for (size_t i = 0; i < m_size; i++){
			m_darr[i] = rhs.m_darr[i];
		}
		std::cout << "\nCopy Constructor called\n";
	}
	// The move constructor performs a shallow copy
	BigClass(BigClass&& rhs) { // Move Ctor
		m_size = rhs.m_size;
		m_darr = rhs.m_darr;
		rhs.m_darr = nullptr;
		std::cout << "\nMove Constructor called\n";
	}
	~BigClass() { 
		std::cout << "\nDestructor called\n";
		delete m_darr; }
private:
	int m_size;
	double* m_darr;
};

// Since we have the move constructor, copybC() will use it and 
// this will increase the performance of the program.
void copybC(BigClass b);
void refbC(BigClass& b);
BigClass createBigClass();

int main(int argc, char** argv) {


	int a = 5;	// a is an lvalue;

	int& b = a;	// b is an lvalue ref

	//int && c; // c is a rvalue ref


	intPrint(a); // Calls intPrint(int& i)
	intPrint(6); // Calls intPrint(int&& i)
	
	BigClass recycle = createBigClass();

	// refbc() takes recycle as ref, so there is no move or copy.
	refbC(recycle);
	// copybC(std::move(recycle)); uses the move constructor to do a shallow copy
	// and then the copy is discarded after the function scope.
	copybC(std::move(recycle));
	// This copybc makes a deep copy and discards the copy after the scop ofthe function.
	copybC(recycle);
	
 

	getchar();
	return 0;
}

void copybC(BigClass b) { std::cout << "\nin copyBC\n"; }
void refbC(BigClass& b) { std::cout << "\nin refBC\n"; }
BigClass createBigClass() { return  BigClass(); }