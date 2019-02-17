
#ifndef STACK_H
#define STACK_H

#include <exception>

// simple exception class
class StackExeption : public std::exception {
	const char * m_msg;
	StackExeption() {};    // no default constructor
public:
	explicit StackExeption(const char * s) throw() : m_msg(s) { }
	const char * what() const throw() { return m_msg; }
};

// simple fixed-size LIFO stack template
template <typename T>
class Stack {
private:
	static const int m_defaultSize = 10;
	static const int m_maxSize = 1000;
	int m_size;
	int m_top;
	T * m_stackPtr;
public:
	explicit Stack(int s = m_defaultSize);
	~Stack() { delete[] m_stackPtr; }
	T & push(const T &);
	T & pop();
	bool isEmpty() const { return m_top < 0; }
	bool isFull() const { return m_top >= m_size - 1; }
	int top() const { return m_top; }
	int size() const { return m_size; }
};

#include "templates-stack-class.inl"

#endif // STACK_H
