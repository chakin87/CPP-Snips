//				Smart_ptr
//    Smart pointers help manage your memory.
// There are several types of smart pointers.

//    unique_ptr<> is basically a scoped pointer. It is allocated on
// the Heap. At the end of the scope, it will automatically call 
// delete. Unique pointers cannot be copied. If you try, you will
// end up with 2 unique pointers pointing to the same memory and 
// when the first one dies, the memory will be freed. This will 
// leave the other pointer dangling.

//    shared_ptr<> is shareable and scopless, so long as there is a pointer
// attached to the memory. These pointers use reference counting, and that 
// means that for every 'copied' shared ptr, they are all kept track of.
// Once the last shared ptr dies, the memory is freed.

//    weak_ptr gets passed a shared pointer but it does not increase
// the reference count of the shared pointer. Weak pointer will not 
// keep shared pointer alive and will die at the end of the scope.


#include "functions.h"
//    Include memory to get smart pointers!
#include <memory>

struct Demo {
	Demo() { 
		std::cout << "\nTrying to create Demo Object...\n Enter a x value: ";
		x = std::cin.get();
		std::cout << "Demo(int " << x << ") Created\n";
	}
	Demo(int x) :x(x) { std::cout << "\nDemo(int " << x << ") Created\n"; }
	~Demo() { std::cout << "\nDemo " << x << " Destroyed\n"; }

	int x;
};

int main(int argc, char** argv) {
	{
		std::weak_ptr<Demo> w0;
		std::shared_ptr<Demo> shptr2;
		{
			//    This is one way to create the pointer...
			std::unique_ptr<Demo> uptr1(new Demo());
			//    This is the ideal way to create a unique ptr. Helps w/ exception saftey.
			std::unique_ptr<Demo> uptr2 = std::make_unique<Demo>();
			//    The unique_ptr is a good, simple, and fast ptr.
	
			//    Shared pointers
			// This is the proper way to make a shared pointer. Do not pass
			// a new.
			std::shared_ptr<Demo> shptr = std::make_shared<Demo>();
			shptr2 = shptr;
			w0 = shptr2;

			system("pause");
		}
		//    unique pointers die here.
	}
	//    weak_ptr w0 dies here.


	system("pause");
	std::cin.get();
	return 0;
	//    shared_ptr die here.
}