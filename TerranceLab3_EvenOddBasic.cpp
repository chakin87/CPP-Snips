//-----------------------------------------------------------------------------//
//-------------- Prototypes, Utility Functions, Defs, and Includes ------------//
//-----------------------------------------------------------------------------//
#include <iostream>
#include <string>
#include <sstream>
#include<stdio.h> 
#include<stdlib.h> 

//The pause() function pauses program so that the user can read what is on the screen.
void pause();

//The clear() function clears the screen. This function should work on on windows, mac, and linux.
void clear() {
#ifdef _WIN32
	system("cls");
#else
	std::cout << "\033[2J\033[1;1H";
#endif
}


//The CIN_INT(i) macro allows the user to input only an integer value. It also keeps the program from exiting 
//if the user entered a non-integer type.
#define CIN_INT(i)  std::cin >> i;\
	   while(std::cin.fail()) {\
			std::cout << "Improper integer value entered!" << std::endl;\
			std::cin.clear();\
			std::cin.ignore(256, '\n');\
			std::cout << "Please enter a integer value: ";\
			std::cin >> i;\
	   }\

//-----------------------------------------------------------------------------//



int main(int argc, char** argv) {


	bool isFirstRun = true;
	// iBuf stores the user input, iOdds stores the number of odd entered and iEvens keeps track of the number of even numbers entered
	int iBuf = 0, iOdds = 0, iEvens = 0;

	//The strResults string stores the characters == Odds: " << (iOdds) << "   ||   Evens: " << (iEvens);
	std::string strResult;

	while (iBuf >= 0) {
		clear();
		
		//The stringstream ssValues will hold our mix of string and ints so that we can display them in one line.
		std::stringstream ssValues;
		//Here we set up stringstream
		ssValues << "Odds: " << (iOdds) << "   ||   Evens: " << (iEvens);

		//Here we assign the stringstream to a string so that we can use it with std::cout <<
		strResult = ssValues.str();

		//This block of cout is displayed every iteration of the while loop.
		std::cout << ("Hello, welcome to the Even or Odd tally machine.\n\n");
		std::cout << ("Enter a positive integer value to find out if it is Even or Odd.\n");
		std::cout << ("Enter a negative integer value to exit the app.\n\n");
		std::cout << ("Tallys:\n");
		//std::cout << ((const char*)(strResult.c_str()));
		std::cout << "Odds: " << (iOdds) << "   ||   Evens: " << (iEvens);

		//If it is the first time through the while loop the user has not entered information.
		if (isFirstRun) {
			std::cout << ("\n\nEnter a integer: ");
			isFirstRun = false;
		}
		//The user has entered a number so we can display it while the user is typing in another integer.
		else {
			std::cout << "\n\nYou have entered " << iBuf << ".\n";
			std::cout << "\n" << iBuf << " is " << (iBuf % 2 == 0 ? "Even " : "Odd ") << "number!\n\n";
			std::cout << ("\nEnter a integer: ");

		}

		// CIN_INTO allows the user to enter only an integer. If it is not integer it will reprompt the user for an int.
		CIN_INT(iBuf);


		///std::cin >> iBuf;


		//The 8 lines of code below keep track of the even and odd numbers entered. We use the if statement
		//to make sure that the negative number is not counted in our tally.
		if (iBuf % 2 == 0) {
			++iEvens;
		}
		else {
			if (iBuf > 0) {
				++iOdds;
			}
		}
	}

	//Here is the code that is ran after the user elects to exit out of the program by using a negative integer.
	//We use a strinstream to display the results for the user.
	std::stringstream ssValues;
	ssValues << "\n\nTotal Evens: " << iEvens << " || Total Odds: " << iOdds;

	strResult = ssValues.str();

	clear();
	std::cout << ("\n\nThank you for using the Even or Odd tally machine!");
	std::cout << ("\n\n\nHere are your results:");
	//std::cout << (strResult.c_str()) << "\n\n\n\n\n";
	std::cout << "\n\nTotal Evens: " << iEvens << " || Total Odds: " << iOdds << "\n\n\n";


	//The pause function stops the program from exiting while the user reads the above text.
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
