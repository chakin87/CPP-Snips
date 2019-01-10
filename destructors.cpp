//				Destructors and Virtual Destructors
//    Destructors are very important! Proper or improper destructors can make or break
// a program or game!




#include "functions.h"


//    Here we set up some demo classes. A base class and a derived class.
class Base {
public:
	Base() {LOG("BASE CONSTRUCTED") }
	~Base() { LOG("BASE DESTRUCTED") }
};
class BaseVD {
public:
	BaseVD() { LOG("BASE CONSTRUCTED") }
	virtual ~BaseVD() { LOG("BASE DESTRUCTED") }
};
class Derived : public Base {
public:
	Derived() { LOG("DERIVED CONSTRUCTED") }
	~Derived() { delete[] m_arr; LOG("DERIVED DESTRUCTED") }
private:
	int* m_arr = new int[5];
};
class DerivedVD : public BaseVD {
public:
	DerivedVD() { LOG("DERIVED CONSTRUCTED") }
	~DerivedVD() { delete[] m_arr; LOG("DERIVED DESTRUCTED") }
private:
	int* m_arr = new int[5];
};

int main(int argc, char** argv) {

	Base* base = new Base();
	delete base;
	LOG("-\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/-");
	Derived* derived = new Derived;
	delete derived;
	LOG("-\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/-");
	LOG("So far, we're all good. Let's go deeper.");
	Base* poly = new Derived;
	delete poly;
	LOG("poly doesn't call Derived Destructor!")
	LOG("-\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/-");
	BaseVD* polynu = new DerivedVD;
	delete polynu;
	LOG("As you can see, we are all good now!")

	std::cin.get();
	return 0;
}