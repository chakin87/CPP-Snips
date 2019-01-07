

#include <string>
#include "functions.h"


int main(int argc, char** argv) {

	
	
	// c-style str. const is not manditory,
	// but is usually used for saftey.
	const char* name = "Chris"; 

	//    Other types of const char*
	const char* name1 = u8"Chris";// 8 bit char utf16
	const wchar_t* name2 = L"Chris";// (2 or 4 byte) 16 bit char
	const char16_t* name3 = u"Chris";// 16 bit char
	const char32_t* name4 = U"Chris";// 32 bit char

	
	//    must add null terminator at end 0 or '\0'
	char cname[6] = {'C', 'h', 'r', 'i', 's', 0}; 

	std::string str = std::string("Chris") + " Rocks";
	using namespace std::string_literals;
	std::string strlit = "name"s + "append";
	std::u16string byte2 = u"2bytechar";
	std::u32string byte4 = U"4bytechar";
	bool contains = str.find("ris") != std::string::npos;

	//    The std::boolalpha replaces 1 or 0 to true or false.
	LOG(std::boolalpha << contains);
	LOG(str);

	//    String copying is rather slow, so make sure you pass
	// strings by const ref. 

	std::cin.get();
	return 0;
}
