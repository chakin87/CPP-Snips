#include <iostream>
#include <string>


// Recursive Version
void ReverseString(const std::string& str)
{
	size_t numOfChars = str.size();

	if (numOfChars == 1)
		std::cout << str << std::endl;
	else
	{
		std::cout << str[numOfChars - 1];
		ReverseString(str.substr(0, numOfChars - 1));
	}
}


int main()
{
	std::string str;
	while (str != "exit") {

		std::cout << " Please enter a string " << std::endl;
		std::getline(std::cin, str);
		ReverseString(str);

	}


	return 0;
}