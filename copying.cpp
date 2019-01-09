//				Copying and Copy Constructors
//    Let's talk about the benefits of copyiing data, variables, and other
// items. Copying can be extremely beneficial, but if the copying is 
// unintended it can be wasteful in the performance department.

//				NOTE: A Thought Pulled from this Lesson. 
//    Most often you want to pass a parameter as const ref. Otherwise it will
// copy the data, wasting time and memory... a bit of a performance hit...
// Everytime you can, pass function params by const ref.


//#include <conio.h>
#include "functions.h"

struct Vector2f {
	float x, y;
};

//    This string class is for demonstration purposes only. This is not the way
// that I would recommend creating an official string class. This class serves its
// purpose in helping to demonstrate copying and copy constructors - etc.
class String {
public: // Constructors
	String(const char* string) {
		m_size = strlen(string);
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, string, m_size);
		//    Adding null terminator to the end of the new string.
		m_buffer[m_size] = 0;
	}
	//    Below is an example of what the default copy constructor looks like.
	// This is what c++ will give as default, either one of these 2 examples.
	// These are supplied by the compiler automatically, similar to the default
	// constructor of a class. You don't have to write them for them to exist.

			// --------------------------------------------------------------------------
				//String(const String& other)
					//:m_buffer(other.m_buffer), m_size(other.m_size){}
			// ---- or ------------------------------------------------------------------
				//String(const String& other) {
				//	memcpy(this, &other, sizeof(String));
				//}
			// --------------------------------------------------------------------------

	//    Side note, if you don't want to allow your class to be copied at all...

			//	//String(const String& other) = delete;  
			// --------------------------------------------------------------------------

	//    These are fine in some circumstances, but not for this case. We don't want
	// to just copy the pointer, we need to allocate a new one for the new obj.
	// Below is what we need in order to get a 'full' copy of the obj.
	String(const String& other)
	: m_size(other.m_size){
		//    We allocate a new m_buffer at the needed size and then copy the buffer
		// into it.
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, other.m_buffer, m_size + 1);
		std::cout << "\nA String was copied!\n";
	}
	~String() { 
		//    Here we make sure to clean up the Heap allocated buffer.
		delete m_buffer; 
	}
public: // Methods
	friend std::ostream& operator<<(std::ostream& stream, const String& string) {
		stream << string.m_buffer;
		return stream;
	}
	char& operator[](unsigned int index) {
		//TODO: Add saftey measures, boundaries, etc.
		return m_buffer[index];
	}


private: // Members
	char* m_buffer;
	unsigned int m_size;
};
//    Using this pass-by-value function, will call the copy constructor in the 
// String class. We have overrided it, but other wise it would have called the
// default copy constructor.
void print_string(String string) {
	std::cout << string << "\n";
}
//    Using this pas-by-ref function will pass the string obj by reference and
// is faster. It is also pretty safe via const.
void print_string(const String& string) {
	std::cout << string << "\n";
}

int main(int argc, char** argv) {

	//    Vector b is a literaly copy of a. Vector b created a new object
	// with the values copied from a. When we change b.x, a.x remains the same.
	Vector2f a{ 2, 3 };
	Vector2f b = a;
	b.x = 5.f;

	//    Vector d is not a constructed vector, it just points to the vector that c
	// points to. Vector c instanciated the vecctor that c and d point to when the 
	// new keyword was called.
	Vector2f* c = new Vector2f();
	Vector2f* d = c;
	//    The asignment below modifies the vector that c and d both point to.
	d->x = 7;

	//    Without a proper conpy constructor str2 will copy the exact m_buffer ptr.
	// This means that str and str2 will be sharing the m_buffer, and when one of them goes out 
	// of scope the m_buffer ptr is deleted. This leaves the other with a dangling ptr!  :(
	
	String str = "Christopher";
	std::cout << str << "\n";
	String str2 = str;
	std::cout << "str1: " << str << ", str2: " << str2 << "\n";
	
	//    Again,  without a proper conpy constructor str2 has the exact same m_buffer ptr.
	// That means that str2[2] = 'a' will change str as well. It is changing the same memory!
	// Since we have overided the copy constructor, it creates its own m_buffer and copies the
	// value from the other.m_buffer.
	str2[2] = 'a';
	std::cout << "str1: " << str << ", str2: " << str2 << "\n";


	std::cin.get();
		return 0;
}