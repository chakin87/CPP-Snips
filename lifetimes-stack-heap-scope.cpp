//					Stack and Heap
//    The stack and heap are both located in ram. The work differently from each
// other but can both be accessed and allocated to in our programs. The difference 
// is how it stores the data.
//    The Stack allocations work like this: [        ] <- empty stack, no allocations.
// As you create variables and containers on the stack, it fills up in order,
// like this: [||     ] <-2 variables  [|||    ]<-3 variables [|||||| ]<-6 variables 
// The Stack fills up like you were stacking the variables right next to each other.
// Stack allocations are very fast. Allocating to the Stack is basically a single
// cycle. The stack keeps a pointer(stack pointer) to where it's at and when you allocate to the 
// stack it gives the memory address, allocates the variables, and then moves then moves then
// stack pointer to the end of the newly allocated memory. That's it. Super easy, super fast.
//
//    The Heap is allocated to by using the new keyword. Heap allocations must be 
// removed via delete or delete[] keywords. If you are using smart pointers then 
// they will be allocated to the Heap, but the smart pointers will handle their 
// own delete/delete[]. **The easiest way to remember when to use delete/delete[],
// is if you use new/new[] then you must use delete/delete[].**
//


#include "functions.h"

struct Demo {
	Demo() { std::cout << "\nDemo Created\n"; }
	Demo(int x):x(x) { std::cout << "\nDemo(int " << x << ") Created\n"; }
	~Demo() { std::cout << "\nDemo " << x << " Destroyed\n"; }

	int x;
};

//    This is a stack allocated array and will not work because it leaves scope
// when it is returned. This is a problem, stack based variables created in functions
// cannot be returned.
int* create_array() {
	int array[50];
	return array;
}
//    You can fix it by allocating to the Heap.
int* create_array_s() {
	int* array = new int[50];
	return array;
}

//    Here is a little solution to controlling the lifetime of a Heap allocated
// pointer. This is a specific example/wrapper class, but the implementation is
// powerful.
class scoped_ptr {
private:
	Demo* m_ptr;
public:
	scoped_ptr(Demo* d_ptr) :m_ptr(d_ptr) {}
	~scoped_ptr() { delete m_ptr; }

	Demo* operator->() {
		return m_ptr;
	}
};

int main(int argc, char** argv) {

	//    Create a Demo obj on the Stack.
	// As soon as program leaves the {} scope d was created in,
	// d is destroyed.
	{
		Demo d = (0);
		Demo demo;
		demo.x = 1;
		system("pause");
	}
	//    Create a Demo obj on the Heap.
		// When the program leaves the {} scope de was created in,
	// de does not die. It will live until delete de; is called.
	{
		Demo* de = new Demo(2);
		system("pause");
	}
	//    Here, I use the wrapper class to delete my Heap allocated Demo obj 
	// after the scope ends. Lifetime control.
	{
		//    implicit ctor
		scoped_ptr sptr = new Demo(3);
		//    explicit ctor
		scoped_ptr sptr2(new Demo(4));
		
		system("pause");
	}
	//    As you see, the sptr and sptr2 are both Heap allocated, but the wrapper
	// class does well to make sure that they are destroy after the scope ends.
	// Stack allocated item lifetimes can be used to your advantage and should be!
	system("pause");
	std::cin.get();
	return 0;
}