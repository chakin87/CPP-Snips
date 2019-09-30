/*
The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character appears only once in the original string, or ")" if that character appears more than once in the original string.Ignore capitalization when determining if a character is a duplicate.

Examples
"din" = > "((("
"recede" = > "()()()"
"Success" = > ")())())"
"(( @" = > "))(("
Notes

Assertion messages may be unclear about what they display in some languages.If you read "...It Should encode XXX", the "XXX" is the expected result, not the input!
*/

#include <string>
#include <iostream>
std::string duplicate_encoder(const std::string& word) {
	std::string retstr = "";
	std::string wordstr = word;
	bool found = false;
	auto itr = wordstr.begin();

	for (int i = 0; i < word.size(); ++i) {
		auto loopitr = wordstr.begin();
		for (int j = 0; j < word.size(); ++j) {
			if ((tolower(*itr) == tolower(*loopitr)) && (itr != loopitr)) {
				retstr += ')';
				found = true;
				break;
			}
				++loopitr;
		}
		if (found == false) {
			retstr += '(';
		}
		else { found = false; }
			++itr;
	}
	return retstr;
}


//----------------------------------------------------------------------------------------------------//


int main(int argc, char** argv) {

	std::string teststr = "Hhello";

	std::cout << duplicate_encoder(teststr) << std::endl; //Function test.

	char c = ' ';
	std::cin >> c;


	return 0;
}
//----------------------------------------------------------------------------------------------------//