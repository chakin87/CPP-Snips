#include <iostream>

#define IN_DBL(i)  std::cin >> i;\
	   while(std::cin.fail()) {\
			std::cout << "Improper monetary value entered!" << std::endl;\
			std::cin.clear();\
			std::cin.ignore(256, '\n');\
			std::cout << "Please enter a monetary value: ";\
			std::cin >> i;\
	   }\

using namespace std;


int main(int argc, char** argv) {

	double userInput = 0.0;
	char pause;
	char correctAmount;
	int  tens, fives, ones, quarters, dimes, nickels, pennies;

	bool exit = false;
	char cont;

	while (exit == false) {

		cout << "Welcome to the coin collector app." << std::endl; 
		cout << "Please enter the amount of money that you have. $";
		//cin >> userInput;
		IN_DBL(userInput);
		cout << "You have entered: " << userInput << ". Is this correct? (y/n)";
		cin >> correctAmount;

		if (correctAmount == 'y') {

			tens = userInput / 10;
			userInput -= (tens * 10);
			
			//std::cout << "User input value after /=10: " << userInput << std::endl;

			fives = (userInput / 5);
			userInput -= (fives * 5);

			//std::cout << "User input value after /=5: " << userInput << std::endl;
			
			ones = (userInput / 1);
			userInput -= (ones * 1);

			//std::cout << "User input value after /=1: " << userInput << std::endl;
		
			quarters = (int)(userInput / .25);
			userInput -= (double)(quarters * .25);

			//std::cout << "User input value after /=.25: " << userInput << std::endl;

			dimes = (userInput / .1);
			userInput -= (double)(dimes * .1);

			//std::cout << "User input value after /=.1: " << userInput << std::endl;

			nickels = (userInput / .05);
			userInput -= (double)(nickels * .05);

			//std::cout << "User input value after /=.05: " << userInput << std::endl;

			pennies = (userInput / .01);
			userInput -= (double)(pennies * .01);

			//std::cout << "User input value after /=.01: " << userInput << std::endl;
		
		
		}
		else {
			continue;

		}
		

		cout << "Here is your change: ";
 
		std::cout << "\nTens: " << tens << "\nFives: " << fives << "\nOnes: " << ones << "\nQuaters: " << quarters << "\nDimes: " << dimes << "\nNickels: " << nickels << "\nPennies: " << pennies;

		cout << "\nWould you like to try another number? (y/n): ";
		cin >> cont;

		if (cont == 'y') {
			continue;

		}
		else {
			break;
		}
	}
	

	return 0;
}