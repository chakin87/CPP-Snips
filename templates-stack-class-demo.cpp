
#include "templates-stack-class.h"
#include <iostream>
#include <string>
using namespace std;

constexpr int nums[] = { 1, 2, 3, 4, 5 };
constexpr const char * strs[] = { "one", "two", "three", "four", "five" };

int main() {
	try {
		Stack<int> i_stack(5);

		cout << "i_stack size: " << i_stack.size() << endl;
		cout << "i_stack top: " << i_stack.top() << endl;

		for (int i : nums) {
			i_stack.push(i);
		}

		cout << "i_stack top after pushes: " << i_stack.top() << endl;
		cout << "i_stack is " << (i_stack.isFull() ? "" : "not ") << "full" << endl;

		while (!i_stack.isEmpty()) {
			cout << "popped " << i_stack.pop() << endl;
		}
	}
	catch (StackExeption & e) {
		cout << "Stack error: " << e.what() << endl;
	}

	try {
		Stack<string> s_stack(5);

		cout << "s_stack size: " << s_stack.size() << endl;
		cout << "s_stack top: " << s_stack.top() << endl;

		for (const char * s : strs) {
			s_stack.push(s);
		}

		cout << "s_stack top after pushes: " << s_stack.top() << endl;
		cout << "s_stack is " << (s_stack.isFull() ? "" : "not ") << "full" << endl;

		while (!s_stack.isEmpty()) {
			cout << "popped " << s_stack.pop() << endl;
		}
	}
	catch (StackExeption & e) {
		cout << "Stack error: " << e.what() << endl;
	}

	std::cin.get();

	return 0;
}
