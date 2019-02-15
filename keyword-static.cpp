//-----------------------------------------------------------------------------//
//------------------------ Static Keyword - Costs and Benefits-----------------//
//-----------------------------------------------------------------------------//
//
//
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



int main(int argc, char** argv) {



	std::cin.get();
	return 0;
}






// 
//-----------------------------------------------------------------------------//
//-------------------------Defines for the Prototypes--------------------------//
//-----------------------------------------------------------------------------//
//
//-----------------------------------------------------------------------------//
void pause()
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

