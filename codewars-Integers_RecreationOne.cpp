/*
Divisors of 42 are : 1, 2, 3, 6, 7, 14, 21, 42. These divisors squared are: 1, 4, 9, 36, 49, 196, 441, 1764. The sum of the squared divisors is 2500 which is 50 * 50, a square!

Given two integers m, n (1 <= m <= n) we want to find all integers between m and n whose sum of squared divisors is itself a square. 42 is such a number.

The result will be an array of arrays or of tuples (in C an array of Pair) or a string, each subarray having two elements, first the number whose squared divisors is a square and then the sum of the squared divisors.

#Examples:

list_squared(1, 250) --> [[1, 1], [42, 2500], [246, 84100]]
list_squared(42, 250) --> [[42, 2500], [246, 84100]]
The form of the examples may change according to the language, see Example Tests: for more details.

Note

In Fortran - as in any other language - the returned string is not permitted to contain any redundant trailing whitespace: you can use dynamically allocated character strings.
*/


//Libraries - NOTE: all may not be used in this file.
//--------------------------------------------------------------------------------------//
//My code
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <utility>


class SumSquaredDivisors
{
public:
	static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n) {
		std::vector<std::pair<long long, long long>> retVec;
		long long bruh;
		for (; m <= n; ++m) {
			bruh = square_sum(m);
			//std::cout << bruh << std::endl;
			if (bruh != 0) {
				retVec.push_back( std::make_pair(m, bruh) );
			}
		}

	//	for (auto pair : retVec) {													  //debug
	//		std::cout << "[" << pair.first << ", " << pair.second << "]" << std::endl;//debug
	//	}																			  //debug


		return retVec;
	}
	//The function square_sum will find the divisors of num and then add them up and check if it is a square.
	static long long square_sum(long long num) {
		long long divs = 0;
		for (long long i = 1; i <= num; ++i) {
			//std::cout << "if (" << num << " % " << i << " == 0) == " << (((num % i) == 0)? "yes":"no") << std::endl;//debug
			if (num % i == 0) {
				divs += (i * i);
			}
		}
		if (isPerfectSquare(divs)) {
			return divs;
		}

		return 0;
	}
	static bool isPerfectSquare(long double x)
	{
		// Find floating point value of  
		// square root of x. 
		long double sr = sqrt(x);

		// If square root is an integer 
		return ((sr - floor(sr)) == 0);
	}
};

//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {



	SumSquaredDivisors s;

	s.listSquared(1, 250);





	char c;
	std::cin >> c; //Keep the darn window open! LOLz

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem
std::string listSquared(long long m, long long n)
{
	std::string ret;
	for (int i = m; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= i; j++)
			if (i % j == 0) sum += j * j;
		double sqrt_sum = sqrt(sum);
		if (floor(sqrt_sum) == sqrt_sum)
			ret += "{" + std::to_string(i) + ", " + std::to_string(sum) + "}, ";
	};
	return "{" + ret.substr(0, ret.size() - 2) + "}";
}
//--------------------------------------------------------------------------------------//
std::string
SumSquaredDivisors::listSquared(long long m, long long n)
{
	std::string temp;                                       // stores divsAreSquare result
	std::stringstream res;                                  // stores stringified output
	int tokens = 0;                                         // enables proper comma placement
	res << "{";                                             // start the result
	for (long long i = m; i <= n; i++)                          // for the given range
		if ((temp = divsAreSquare(i)) != "")                  // if the divisors are ^2
			tokens++ > 0 ? res << ", " << temp : res << temp;   // add the result to output
	res << "}";                                             // close the result
	return res.str();                                       // stringify && return 
};

std::string
SumSquaredDivisors::divsAreSquare(long long n)
{
	std::stringstream res;
	unsigned long long sum = 0;
	for (auto i = 1; i <= std::sqrt(n); i++)                    // from 1 to sqrt(n)
		if (n%i == 0)                                           // if we find a factor
			sum = (n / i * n / i == i * i ? i * i : n / i * n / i + i * i) + sum; // ^2 and add (but only once)
	if (std::sqrt(sum) == std::floor(std::sqrt(sum)))       // if the sum is square
		res << "{" << n << ", " << sum << "}";                // wrap it up
	return res.str();                                       // stringify && return
};
//--------------------------------------------------------------------------------------//
string SumSquaredDivisors::listSquared(long long m, long long n) {
	ostringstream oss;
	if (m == 1) {
		oss << "{1, 1}, ";
		++m;
	}
	for (int i = m; i <= n; i++) {
		int sum = 1 + i * i;
		double sqrt_i_f = sqrt(i);
		int sqrt_i_i = floor(sqrt_i_f);
		if (sqrt_i_f == sqrt_i_i) sum += i * i;
		for (int j = 2; j <= sqrt_i_i; j++)
			if (i % j == 0) sum += j * j + pow(i / j, 2);
		double sqrt_sum = sqrt(sum);
		if (floor(sqrt_sum) == sqrt_sum) oss << "{" << i << ", " << sum << "}, ";
	};
	string ret = oss.str();
	return "{" + ret.substr(0, ret.size() - 2) + "}";
};
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

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
