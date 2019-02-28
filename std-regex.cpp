


#include <regex>
#include <string>
#include <iostream>


void PrintMatches(std::string str,
	std::regex reg) {


	std::smatch matches;


	std::cout << std::boolalpha;


	while (std::regex_search(str, matches, reg)) {
		std::cout << "Checked for Results : " <<
			matches.ready() << "\n";

		std::cout << "Are there no matches : " <<
			matches.empty() << "\n";

		std::cout << "Number of matches : " <<
			matches.size() << "\n";


		std::cout << matches.str(1) << "\n";


		str = matches.suffix().str();

		std::cout << "\n";
	}
}


void PrintMatches2(std::string str,
	std::regex reg) {


	std::sregex_iterator currentMatch(str.begin(),
		str.end(), reg);


	std::sregex_iterator lastMatch;


	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		std::cout << match.str() << "\n";
		currentMatch++;
	}
	std::cout << std::endl;

}

