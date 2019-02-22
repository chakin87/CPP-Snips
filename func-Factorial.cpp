
#include<iostream>

int Factorial(int n) {
	static int i = 1;
	std::cout << i << " : time(s)\n" << "Value: " << n << "\n";

	if (n == 1) {
		return 1;
	}
	else {
		i++;
		return  n = n * Factorial(n - 1);
	}
}

int main() {

	std::cout << "Enter to number to find Factorial: ";
	int num;
	std::cin >> num;
	num = Factorial(num);
	std::cout << "\nFactorial of number is: " << num << std::endl;


	std::cin >> num;
	return 0;
}
