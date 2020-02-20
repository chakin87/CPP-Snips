//-----------------------------------------------------------------------------//
//-------------- Prototypes, Utility Functions, Defs, and Includes ------------//
//-----------------------------------------------------------------------------//
#include <iostream>
#include <string>
#include <sstream>
#include<stdio.h> 
#include<stdlib.h> 

void pause();

void clear() {
#ifdef _WIN32
	system("cls");
#else
	std::cout << "\033[2J\033[1;1H";
#endif
}

void print_sub_section(const char * msg_80_chars);

void pad_to_offset(std::string& str, const size_t len, int offset, const char padding_char);

void pad_to(std::string& str, const size_t len, const char padding_char);

#define CIN_INT(i)  std::cin >> i;\
	   while(std::cin.fail()) {\
			std::cout << "Improper integer value entered!" << std::endl;\
			std::cin.clear();\
			std::cin.ignore(256, '\n');\
			std::cout << "Please enter a integer value: ";\
			std::cin >> i;\
	   }\

#define IS_WINDOWS 0
//-----------------------------------------------------------------------------//



int main(int argc, char** argv) {
	

	bool isFirstRun = true;
	int iBuf = 0, iOdds = 0, iEvens = 0;
	std::string strResult;
	
		while (iBuf >= 0) {
			clear();
			std::stringstream ssValues;
			
			ssValues << "Odds: " << (iOdds) << "   ||   Evens: " << (iEvens);
			strResult = ssValues.str();

			print_sub_section("Hello, welcome to the Even or Odd tally machine.");
			print_sub_section("Enter a positive integer value to find out if it is Even or Odd.");
			print_sub_section("Enter a negative integer value to exit the app.");
			print_sub_section("Tallys:");
			print_sub_section((const char*)(strResult.c_str()));
			if (isFirstRun) {
				std::cout << ("\nEnter a integer: ");
				isFirstRun = false;
			}
			else {
				std::cout << "\nYou have entered " << iBuf << ".\n";
				std::cout << "\n" << iBuf << " is " << (iBuf % 2 == 0 ? "Even " : "Odd ") << "number!\n\n";
				std::cout << ("\nEnter a integer: ");

			}
			CIN_INT(iBuf);


			if (iBuf % 2 == 0) {
				++iEvens;
			}
			else {
				if (iBuf > 0) {
					++iOdds;
				}
			}


			//pause();



		}

		std::stringstream ssValues;
		ssValues << "Total Evens: " << iEvens << " || Total Odds: " << iOdds;

		strResult = ssValues.str();

		print_sub_section("Thank you for using the Even or Odd tally machine!");
		print_sub_section("Here are your results:");
		print_sub_section(strResult.c_str());

		pause();

	return 0;
}



//-----------------------------------------------------------------------------//
//-------------------------Defines for the Prototypes--------------------------//
//-----------------------------------------------------------------------------//
//
//-----------------------------------------------------------------------------//
void pause()
{
	std::cout << std::endl << "Press Enter to continue...";
	getchar();
	std::cin.ignore();
}


//-----------------------------------------------------------------------------//
void print_sub_section(const char * msg_80_chars)
{
	std::string msg_80(msg_80_chars);
	pad_to(msg_80, 81, '-');
	std::cout << "\n"
		"//----------" << msg_80 << "----------//\n";

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