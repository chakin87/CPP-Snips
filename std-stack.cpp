//				STL CONTAINER STD::STACK
//   
//    LIFO operation stile for the std::stack. Stacks are a very important 
// part of the C++ language! I use them all the time! Stacks use the queue 
// (by default, but you can specify other container types if you want)
// as their underlying container, so stacks are really good and fast at 
// pop and push. 
//
//    The std::stack is a container adapter, a wrapper, and adapts an underlying
// container into a LIFO operating container.
// 
//    Check out some basic and advanced uses.

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include "functions.h"

template <typename T>
void report(T & stk) {
	std::cout << "size: " << stk.size() << " top: " << stk.top() << std::endl;
}

// print a simple message
void print(const char * s) { std::cout << s << std::endl; }

int main()
{
	// vector
	print("s1");
	std::vector<int> v1 = { 1, 2, 3, 4, 5 };
	std::stack<int, std::vector<int>> s1(v1);
	report(s1);
	print("s1 push 42");
	s1.push(42);
	report(s1);
	print("s1 pop");
	s1.pop();
	report(s1);

	print("s2 default stack (deque)");
	std::stack<std::string> s2;
	for (std::string s : {"one", "two", "three", "four", "five"}) {
		s2.push(s);
	}
	report(s2);
	print("s2 push forty-two");
	s2.push("forty-two");
	report(s2);
	print("s2 pop");
	s2.pop();
	report(s2);



	WAIT;
	return 0;
}
