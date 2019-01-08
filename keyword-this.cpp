//				This Keyword! 
//		 this->cool_keyword();
//    


#include "functions.h"
//    Prototypes and example functions - don't mind them just yet.
struct Demo;
void cool_function(Demo* d);
void cool_ref_function(const Demo& d);

struct Demo {
	int x, y;

	Demo(int x, int y) {
		//    Creates a pointer to the Demo Object created.
		// The de is basically the same as d;
		Demo* d = this;
		Demo* const& de = this;
		// All x and y asignments below are equivelent and are 
		// just assigning values to the new Demo objuct constructed.
		d->x = x;
		d->y = y;
		de->x = x;
		//    Using the -> operator instead of the . operator, causes 
		// the pointer to be dereferenced automatically before reading
		// or writing.
		this->x = x;
		this->y = y;
		//    Here is it done manually. We dereference and then assign values.
		(*this).x = x;
		(*this).y = y;

		//    So if I want to use a function that takes a Demo* Obj is a parameter,
		// I can use 'this' for the parameter!
		cool_function(this);

		//    If I want to use a function that takes a const Demo& Obj is a parameter,
		// I can use '*this' for the parameter!
		cool_ref_function(*this);
		//    Below is how the above works out.
		Demo& dref = *this;
		//    Same as above, but if the function was const.
		const Demo& cdref = *this;

		//    Very rarely you would want to, but you can technically do this;
		//'delete this;'
	}
	int getx() const {
		//    In a const function, this is const as well.
		// This example is how to declare it.
		const Demo* demo = this;
		return x;
	}
};


int main(int argc, char** argv) {


	std::cin.get();
	return 0;

}

void cool_function(Demo* d) {
	//TODO
}
void cool_ref_function(const Demo& d) {
	//TODO
}