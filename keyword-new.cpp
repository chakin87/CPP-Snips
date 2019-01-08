//				The new Keyword (actually new is an operator)
//    The way to manually allocate objects and vars to the Heap.
// Why do I care about allocating to the Heap?
// 1) Is you object really really big?
// 2) Do you want to explicit manage object lifetime manually?
//    Rather than object dying out of scope.
// 3) You will/must call delete or delete[] after allocating to
//    the Heap using new keyword.
// +) Smart pointers allow another way to allocate to the Heap,
//    but they can manage their own lifetime.
// +) Allocating to the Heap is slightly slower compared to using
//    the stack. When you allocate to the Heap, the program must 
//    scan the memory (free list) for a contiguous space of memory.

//    We are programming in C++ so we can get the best performance and
// need complete control of our program. It is very important to 
// understand how memory works. If not, why use C++, there are easier 
// and memory managed languages to use.

#include "functions.h"

struct Object {
	Object() {}
	Object(const std::string& name)
		:m_name(name) {}
	std::string m_name;

};

int main(int argc, char** argv) {
	//    a is allocated to the stack.
	int a = 2;
	//    b is allocated to the Heap. (4 bytes)
	int* b = new int;
	//    c is an array that is allocated to the Heap. (200 bytes)
	int* c = new int[50];

	//    New Object allocated on Heap
	// Also calls the constructor
	Object* o = new Object("bill");// <--() not needed.
	//    When we call the above call, below is what actually happens.
	// Calling 'new' calls the underlying function malloc. Malloc takes 
	// a size and then return a void*. Below is what is going on behing
	// the scenes, notice we need to cast the void* that malloc returns
	// into Object* in order to get the correct pointer. 
	//    The only dif is malloc will not call the Object Ctor.
	Object* oo = (Object*)malloc(sizeof(Object));

		//    New Object array allocated on Heap
	Object* ob = new Object[50]();// Must use default ctor for array.


	//    Allocate to Heap on memory that has been alocated already
	// This would work, but is not proactical. 
	int* i = new int[50];
	Object* object = new(b) Object();


	//    After ANY HEAP allocation, we must delete.
	// Memory will not be freed until delete is called 
	// on every Heap allocated item.(Items allocated like this)
	delete b;
	//delete c;
	delete o;
	delete oo;
	delete object;
	delete[] ob, i, c;



	std::cin.get();
	return 0;
}