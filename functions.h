#pragma once
#include <random>
#include <set>
#include <iterator>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdio>
#include <Windows.h>

#include "ChronoTimer.h"

#define FOREGROUND_WHITE 0x0007
#define FOREGROUND_YELLOW 0X0006

#define LOG(log_msg) std::cout << log_msg << "\n";
#define LIST(log_msg) std::cout << log_msg << " ";
//    Don't name #define 'l' like below. :P
#define l(log_msg) std::cout << "\n" << log_msg << "\n";
#define LOGt(log_msg) std::cout << log_msg << "\n"
#define WAIT std::cin.get();
void pad_to(std::string& str, const size_t len, const char padding_char);
void pad_to_offset(std::string& str, const size_t len, int offset, const char padding_char);
void print_new_section(const char* msg_80_chars/*80 char max*/);
void print_new_section(const char * msg_80_chars, HANDLE h);
void print_sub_section(const char* msg_80_chars/*80 char max*/);
void print_sub_section(const char * msg_80_chars, HANDLE h);
void print_note_section(const char* multi_line);
void print_note_section(const char* multi_line, HANDLE h);
void print_note_sections(const char* multi_line);
void print_note_sections(const char* multi_line, HANDLE h);



//    Create a function that returns a set of random
// numbers.
std::set<int> make_random_set_int(const size_t num_of_elems);

//    Increments param by 1
void increment_value(int* value);

//    Demonstration Object

struct Object {
public: // Constructors
	Object() {
		LOG(__FUNCTION__ << " Constructed - Ctor: 0, Name: " << m_name <<", Age: " << m_age << "\n")
	}
	Object(const std::string& name)
		:m_name(name), m_age(-1) {
		LOG(__FUNCTION__ << " Constructed - Ctor: 1, Name: " << m_name << ", Age: " << m_age << "\n")
	}
	Object(int age)
		:m_age(age), m_name("Unknown") {
		LOG(__FUNCTION__ << " Constructed - Ctor: 2, Name: " << m_name << ", Age: " << m_age << "\n")
	}



class String {
public: // Constructors
	String(const char* string) {
		m_size = strlen(string);
		m_buffer = new char[m_size];
		memcpy(m_buffer, string, m_size);
	}
public: // Methods
	friend std::ostream& operator<<(std::ostream& stream, const String& string) {
		stream << string.m_buffer;
		return stream;
	}
private: // Members
	char* m_buffer;
	unsigned int m_size;
};

public: // Methods
	inline const std::string getName() { return m_name; } 
	inline const int getAge() { return m_age; } 
private: // Members
	std::string m_name;
	int m_age;

};
struct Vector3i {
	int x, y, z;
	Vector3i(int x, int y, int z)
		:x(x), y(y), z(z) {}
	//    We will go ahead and declare a default copy constructor.
	// This will tell us everytime the vector is copied and it will help
	// demonstrate how and when Vectors resize.
	Vector3i(const Vector3i& vec)
		:x(vec.x), y(vec.y), z(vec.z) {
		std::cout << "\nCopied!\n";
	}
	const int& operator[](unsigned int index) {
		return index == 0 ? x : index == 1 ? y : index == 2 ? z : 0;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector3i& vec3i) {
		stream << vec3i.x << ", " << vec3i.y << ", " << vec3i.z;
		return stream;
	}
};