//				Operator Overloading!
//    Get ready to learn one of the most useful and manditory skills
// of the C++ language!
//    An operator is a symbol or word that performs a task without
// a function. Operators are plentiful and everywhere. The new keyword
// is actually an operator. 
// Some other operators include, but not limited to:
// ?:  ::  ()  +  ++  +=  -  --  -=  []  <<   >>   <>  *  new  delete
// ,  ->  and many more.
// When this file is done, I would like to have named and addressed every
// operator in C++. This includes their names, uses, and how to overload 
// them.
//    C++ gives us full control over the operators and overloading them.
// This means operators must be overloaded with care and only in cases in
// which are completely logical and follows the practices that C++ uses.

//    I used this excellent resource to help create this file and for
// The Fraction class, similar to what I made in school. When I find it
// I will add it to this file. :)
// https://en.cppreference.com/w/cpp/language/operators
// This site is an excellent reference to this file and was a big help
// in creating 'operator-overloading.cpp.'
#include "functions.h"

//    Lets create a vector object to show how to apply some opereator
// overloading. 
struct Vector2f {
	float x, y;

	Vector2f(float x, float y)
	: x(x), y(y){}
	//    Vector2f addition and overload
	Vector2f add(const Vector2f& other) const {
		return Vector2f(x + other.x, y + other.y);
		//return add(other)  - (a) This would work as well
	}
	Vector2f operator+(const Vector2f& other) const {
		return add(other);
		//return Vector2f(x + other.x, y + other.y);  - (a) This would work as well
	}
	//    Vector2f multiplication and overload
	Vector2f multiply(const Vector2f& other) const {
		return Vector2f(x * other.x, y * other.y);
	}
	Vector2f operator*(const Vector2f& other) const {
		return multiply(other);
	}
	//    friend keyword used to sneak this operator into the class; convenient to 
	// have it in the class.
	friend std::ostream& operator<<(std::ostream& stream, const Vector2f& other) {
		stream << "[x: " << other.x << "][y: " << other.y << "]";
		return stream;
	}
	//    Overloadiung[] incase i want to iterate through x,y with a for loop.
	// This would be more useful if there were more members to loop through.
	const int& operator[](unsigned int index) {
		return index == 0 ? x : index == 1 ? y : 0.0f;
	}
};

class scoped_ptr {
private:
	Demo* m_ptr;
public:
	scoped_ptr(Demo* d_ptr) :m_ptr(d_ptr) {}
	~scoped_ptr() { delete m_ptr; }

	//    This is an instance in which you would want to overload the ->
	// operator. It would conform to the C++ standards.
	Demo* operator->() {
		return m_ptr;
	}
	//    For const ptrs..
	const Demo* operator->() const {
		return m_ptr;
	}
};

class Fraction
{
	int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
	int n, d;
public:
	Fraction(int n, int d = 1) : n(n / gcd(n, d)), d(d / gcd(n, d)) { }
	int num() const { return n; }
	int den() const { return d; }
	Fraction& operator*=(const Fraction& rhs)
	{
		int new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
		d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
		n = new_n;
		return *this;
	}
};
std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	return out << f.num() << '/' << f.den();
}
bool operator==(const Fraction& lhs, const Fraction& rhs)
{
	return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
bool operator!=(const Fraction& lhs, const Fraction& rhs)
{
	return !(lhs == rhs);
}
Fraction operator*(Fraction lhs, const Fraction& rhs)
{
	return lhs *= rhs;
}


class String {
public: // Constructors
	String(const char* string) {
		m_size = strlen(string);
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, string, m_size);
		//    Adding null terminator to the end of the new string.
		m_buffer[m_size] = 0;
	}

	String(const String& other)
		: m_size(other.m_size) {
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

int main(int argc, char** argv) {

	Vector2f pos(3.f, 2.44f);
	Vector2f spd(.5f, .325f);
	Vector2f powerup(1.1f, 1.1f);

	//    Below is identical code, thanks to operator overloading.
	Vector2f result1 = pos.add(spd.multiply(powerup));
	Vector2f result2 = pos + spd * powerup;

	//    Let's use the new overloaded std::ostream << operator!
	std::cout << "Position: " << pos << "\nSpeed: " << spd << "\n\n";
	std::cout << "Powerup: " << powerup << "\n\n";
	std::cout << "Result1: " << result1 << "\nResult2: " << result2 << "\n\n";

	std::cin.get();
	return 0;
}