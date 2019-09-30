/*Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet : a = 1, b = 2, c = 3 etc.

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::string highestScoringWord(const std::string &str)
{

	std::vector<std::string> list;
	std::vector<int> rank;
	std::string buffer = "";
	int value = 0;

	for (char letter : str) {

		if (letter != ' ') {
			buffer += letter;
			value += (int)(letter - 96);	
		}
		else {
			list.push_back(buffer);
			rank.push_back(value);
			buffer = "";
			value = 0;
			//std::cout << "----------------------------------------------------------------" << std::endl;//debug
			//std::cout << "----------------------------------------------------------------" << std::endl;//debug
		}
		
			//std::cout << "Buffer: '" << buffer << "', Value: " << value << std::endl;//debug
	}
	list.push_back(buffer);
	rank.push_back(value);

	return list[(std::max_element(rank.begin(), rank.end())) - rank.begin()];;
}


int main(int argc, char** argv) {

	int var = 0;
	char c = 'a';

	std::string testPhrase = "whatz zvolcano time are we climbingzz up the zzzzvolcano";
	std::string nuStr = highestScoringWord(testPhrase);

	std::cout << "Higest value of the testPhrase: " << nuStr << std::endl;

	std::cin >> c;

	return 0;
}