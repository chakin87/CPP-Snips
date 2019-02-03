//-----------------------------------------------------------------------------//
//---------------------STD::STRING_VIEW What is that for?----------------------//
//-----------------------------------------------------------------------------//
//    Most importantly it should be used for efficient programming when working 
// with strings. std::string_view allows certain string manip and data collection
// directly and without reallocating a string. See the examples below.
// Cppref ->https://en.cppreference.com/w/cpp/string/basic_string_view
// NOTE: Make sure to add 'ISO C++17 Standard (/std:c++17)' to compiler lang flag

	/*
	  --Types of String Views--
	std::string_view	strview;
	std::wstring_view	wstrview;
    std::u8string_view	u8strview;  // c++20
	std::u16string_view	u16strview;
	std::u32string_view	u32strview;
	*/


//-----------------------------------------------------------------------------//
//------------------------ Printing and Utility Functions----------------------//
//-----------------------------------------------------------------------------//
#include <iostream>
#include <string>
#define WAIT std::cin.get();
#define LOG(log_msg) std::cout << log_msg << "\n";
void pause();
void pad_to(std::string& str, const size_t len, const char padding_char);
void pad_to_offset(std::string& str, const size_t len, int offset, const char padding_char);
void print_new_section(const char * msg_80_chars);
void print_sub_section(const char * msg_80_chars);
void print_note_section(const char * multi_line);
void print_note_sections(const char * multi_line);
//-----------------------------------------------------------------------------//


#include <string_view> // string view header is needed to use these features.


//    Let's look at one use case using the 2 functions below
size_t get_string_length(std::string string) {
	return string.size();
}
//    Only dif is the param. One is string and one is a pointer to the beginning and end of a string
size_t get_string_view_length(std::string_view string) {
	return string.size();
}

	
	
int main(int argc, char** argv) {

	//    When I call this funciton, most compilers will create and allocate a new string obj to
	// memory, and then store the length. Then, the compiler deletes the stirng from memory.
	// After all of that, the compiler will retrun the length.
	get_string_length("I am a string that is about to be allocated into memory!");
	//    Here the string_view will just iterate to the end and return the length. This reduces 
	// the amount of compiler steps around 4x.
	get_string_view_length("I am a string_view and I have a pointer to the begin and end of this string!");
	//    A string_view should be used when you need to look at a string. It is a veery efficient way to do
	// just that. They are designed to look like a string and have quite a few operations that can be used
	// on them. std::string_view allows you to do comparisons that are extremely efficient and in the same 
	// manor as doing an std::string comparison. It has most of all the non-modifying capabilities of an
	// std::string.


	std::cin.get();
	return 0;
}






// 
//-----------------------------------------------------------------------------//
//-------------------------Defines for the Prototypes--------------------------//
//-----------------------------------------------------------------------------//
//
//-----------------------------------------------------------------------------//
void pause() // Make-shift cross-platform console pause.
{
	std::cout << std::endl << "Press Enter 2x to continue...";
	getchar();
	std::cin.ignore();
}
//-----------------------------------------------------------------------------//
void pad_to(std::string& str, const size_t len, const char padding_char) {
	if (len > str.size()) {
		int front = ((len - str.size()) / 2);
		//int back = ((len - str.size()) / 2);
		str.insert(0, front, padding_char);
		str.insert(str.size(), (len)-str.size(), padding_char);
	}

}
//-----------------------------------------------------------------------------//
void pad_to_offset(std::string& str, const size_t len, int offset, const char padding_char) {
	if (len > str.size()) {
		int front = ((len - str.size()) / 2);
		front -= offset;
		str.insert(0, front, padding_char);
		str.insert(str.size(), (len)-str.size(), padding_char);
	}

}
//-----------------------------------------------------------------------------//
void print_new_section(const char * msg_80_chars)
{
	std::string msg_80(msg_80_chars);
	pad_to(msg_80, 81, '-');
	std::cout << "\n\n"
		"//-----------------------------------------------------------------------------------------------------//\n"
		"//----------" << msg_80 << "----------//\n"
		"//-----------------------------------------------------------------------------------------------------//\n\n";
}
//-----------------------------------------------------------------------------//
void print_sub_section(const char * msg_80_chars)
{
	std::string msg_80(msg_80_chars);
	pad_to(msg_80, 81, '-');
	std::cout << "\n"
		"//----------" << msg_80 << "----------//\n";

}
//----------------------------------------------------------------------------//
void print_note_section(const char * multi_line) {
	int itr = 0;
	std::string top_bot = "";
	pad_to(top_bot, 89, '.');
	//    strlen(char*) best way to get char.size();
	// This for loop fills note_pad indexes with strings around
	// 20 - 30 ish chars.
	std::string note_pad[10]; bool lfspc = false;
	for (int i = 0; i < strlen(multi_line); ++i) {
		if (i > 1 && i % 68 == 0)lfspc = true;
		if (lfspc && multi_line[i] == ' ') {
			lfspc = false;
			++itr;
			continue;
		}
		note_pad[itr] += multi_line[i];
	}
	for (int i = 0; i <= itr; ++i) {
		pad_to_offset(note_pad[i], 89, 0, '.');
		std::cout << "/*[NOTE]" << note_pad[i] << "[NOTE]*/\n";
	}
}
//-----------------------------------------------------------------------------//
void print_note_sections(const char * multi_line)
{
	int itr = 0;
	std::string top_bot = "";
	pad_to(top_bot, 89, '.');
	//    strlen(char*) best way to get char.size();
	// This for loop fills note_pad indexes with strings around
	// 20 - 30 ish chars.
	std::string note_pad[10]; bool lfspc = false;
	for (int i = 0; i < strlen(multi_line); ++i) {
		if (i > 1 && i % 68 == 0)lfspc = true;
		if (lfspc && multi_line[i] == ' ') {
			lfspc = false;
			++itr;
			continue;
		}
		note_pad[itr] += multi_line[i];
	}
	std::cout << "/*[NOTE]" << top_bot << "[NOTE]*/\n";
	for (int i = 0; i <= itr; ++i) {
		pad_to_offset(note_pad[i], 89, 0, '.');
		std::cout << "/*[NOTE]" << note_pad[i] << "[NOTE]*/\n";
	}
	std::cout << "/*[NOTE]" << top_bot << "[NOTE]*/\n";
}
//-----------------------------------------------------------------------------//

