/*
Instructions
Output
In this Kata, you will implement the Luhn Algorithm, which is used to help validate credit card numbers.

Given a positive integer of up to 16 digits, return true if it is a valid credit card number, and false if it is not.

Here is the algorithm:

Double every other digit, scanning from right to left, starting from the second digit (from the right).

Another way to think about it is: if there are an even number of digits, double every other digit starting with the first; if there are an odd number of digits, double every other digit starting with the second:

1714 ==> [1*, 7, 1*, 4] ==> [2, 7, 2, 4]

12345 ==> [1, 2*, 3, 4*, 5] ==> [1, 4, 3, 8, 5]

891 ==> [8, 9*, 1] ==> [8, 18, 1]
If a resulting number is greater than 9, replace it with the sum of its own digits (which is the same as subtracting 9 from it):

[8, 18*, 1] ==> [8, (1+8), 1] ==> [8, 9, 1]

or:

[8, 18*, 1] ==> [8, (18-9), 1] ==> [8, 9, 1]
Sum all of the final digits:

[8, 9, 1] ==> 8 + 9 + 1 = 18
Finally, take that sum and divide it by 10. If the remainder equals zero, the original credit card number is valid.

  18 (modulus) 10 ==> 8 , which is not equal to 0, so this is not a valid credit card number

*/


//Libraries - NOTE: all may not be used in this file.
//--------------------------------------------------------------------------------------//
//My code
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <list>


class Kata {
public:
	static bool validate(long long int n) {
		std::list<int> diglist;
		bool isOdd = false;
		long long int total = 0;
		
		isOdd = (splitNumber(diglist, n) % 2 != 0);
		
		doubleBubble(isOdd, diglist);

		spltDoubleDigit(diglist);


		for (auto num : diglist) {
			total += num;
			std::cout << num << ", ";
		}
		std::cout << "-------------->Total: " << total << ", " << (total % 10);

		return (total % 10 == 0);
	}

	static int splitNumber(std::list<int>& list, long long int& number) {
		if (0 == number) {
			list.push_back(0);
			return 0;
		}
		else {
			int numOfDigits = 0;
			while (number != 0) {
				int last = number % 10;
				number = (number - last) / 10;
				list.emplace_front(last);
				++numOfDigits;
			}
			return numOfDigits;
		}
	}

	static void doubleBubble(bool isOdd, std::list<int>& list) {

		auto itr = list.begin();

		if (isOdd) {
			for (int i = 0; i < list.size(); ++i) {
				if (i % 2 != 0) {
					*itr *= 2;
				}
				std::advance(itr, 1);
			}
		}
		else {
			for (int i = 0; i < list.size(); ++i) {
				if (i % 2 == 0) {
					*itr *= 2;
				}
				std::advance(itr, 1);
			}
		}

	}

	static void spltDoubleDigit(std::list<int>& list) {
		auto itr = list.begin();

			for (int i = 0; i < list.size(); ++i) {
				if (*itr >= 10){
					*itr -= 9;
				}
				std::advance(itr, 1);
			}
	}
};


//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {


	Kata k;

	k.validate(123);
	std::cout << std::endl;
	k.validate(1417);
	std::cout << std::endl;
	k.validate(891);
	std::cout << std::endl;
	k.validate(8911);







	char c;
	std::cin >> c; //Keep the darn window open! LOLz

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem

static bool validate(long long int n) {
	int sum = 0;
	bool doubleDigit = false;

	while (n > 0)
	{
		int digit = n % 10;

		if (doubleDigit)
		{
			digit *= 2;

			if (digit > 9)
				digit -= 9;
		}

		sum += digit;
		doubleDigit = !doubleDigit;
		n /= 10;
	}

	return sum % 10 == 0;
}

//--------------------------------------------------------------------------------------//
static bool validate(long long int n) {
	long long int r = 0;
	while (n > 0) {
		r += (n % 10);
		n /= 10;
		r += ((n % 10) * 2 - ((n % 10) >= 5 ? 9 : 0));
		n /= 10;
	}
	return ((r % 10) == 0);
}
//--------------------------------------------------------------------------------------//

static bool validate(long long int n) {
	long long int r = 0;
	while (n > 0) {
		r += (n % 10);
		n /= 10;
		r += ((n % 10) * 2 - ((n % 10) >= 5 ? 9 : 0));
		n /= 10;
	}
	return ((r % 10) == 0);
}
//--------------------------------------------------------------------------------------//
static bool validate(long long int n) {
	int sum = 0;
	bool dbl = false;
	while (n > 0) {
		int digit = n % 10;
		n /= 10;
		if (dbl) {
			digit *= 2;
			if (digit > 9) digit -= 9;
		}
		dbl = !dbl;
		sum += digit;
	}
	return (sum % 10 == 0);
}

//--------------------------------------------------------------------------------------//
static bool validate(long long int n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	int index = 0;
	std::transform(digits.begin(), digits.end(), digits.begin(), [&index](long long i) { if (index++ % 2 == 1) return 2 * i >= 10 ? 2 * i - 9 : 2 * i; return i; });
	return std::accumulate(digits.begin(), digits.end(), 0) % 10 == 0;
}

//--------------------------------------------------------------------------------------//
static bool validate(long long int n) {
	bool second = false;
	long long total = 0;
	int temp;
	while (n > 0)
	{
		temp = n % 10;
		temp = second ? temp * 2 : temp;
		temp = temp < 10 ? temp : ((temp % 10) + (temp / 10));
		total += temp;
		second = second ? false : true;
		n /= 10;
	}
	return (total % 10 == 0 ? true : false);
}
//--------------------------------------------------------------------------------------//
static bool validate(long long int n) {

	int a = 0, b = 0, i = 0;
	int sum = 0;
	do {
		a = n % 10;    //分离最后一位
		n = n / 10;

		i += 1;
		if (i % 2 == 0) {  //判断是否为偶数位
			b = a * 2;
			b > 9 ? a = b - 9 : a = b;
		}
		sum += a;

	} while (n != 0);

	if (sum % 10 == 0)
		return true;

	return false;
}
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//