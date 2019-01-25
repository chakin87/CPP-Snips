//				STL CONTAINER STD::QUEUE
// 
//    The queue is a container wrapper class / adapter. Queues are FIFO and 
// can be quite ueful if they are utilized properly!
//
//     Let's take a look at some basic and advanced uses!
//
#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <string>
#include "functions.h"


template <typename T>
void report(T & q) {
	size_t sz = q.size();
	std::cout << "size: " << sz;
	if (sz) std::cout << " front: " << q.front() << " back: " << q.back();
	std::cout << std::endl;
}

//    Print a simple message.
void print(const char * s) { std::cout << s << std::endl; }

int main(int argc, char** argv)
{
	//    Queue from list.
	print("initialize queue from list");
	std::list<int> l1 = { 1, 2, 3, 4, 5 };
	//    Constructor copies to new list.
	std::queue<int, std::list<int>> q1(l1);    
	report(q1);

	print("pop all from q1");
	while (!q1.empty()) {
		std::cout << q1.front() << " ";
		q1.pop();
	}
	std::cout << std::endl;
	report(q1);

	//    Default queue (deque).
	std::queue<std::string> q2;
	print("push strings onto q2");
	for (std::string s : {"one", "two", "three", "four", "five"}) {
		q2.push(s);
	}
	report(q2);

	print("pop all from q2");
	while (!q2.empty()) {
		std::cout << q2.front() << " ";
		q2.pop();
	}
	std::cout << std::endl;
	report(q2);


	WAIT;
	return 0;
}
