//Code Wars.com
//Challenge Name: Sum of the Two Lowest Positive Integers
//
//
//Challenge Instructions: 
//Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.
//
//For example, when an array is passed like[19, 5, 42, 2, 77], the output should be 7.
//
//[10, 343445353, 3453445, 3453545353453] should return 3453455. (10 + 3453445)

#include <vector>
#include <iostream>

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
	unsigned long low_1 = 4294967294; //The largest number for ulong-1
	unsigned long low_2 = 4294967295; //The largest number for ulong

	for (auto number : numbers) {
		if ((number < low_1) || (number < low_2)) {
			if (low_1 < low_2) {
				low_2 = number;
			}
			else {
				low_1 = number;
			}
		}

		return (low_1 + low_2); //This returns the correct solution.
	}
}

//Microsoft Docs on type sizes:
/*
CHAR_BIT	Number of bits in the smallest variable that is not a bit field.	8
SCHAR_MIN	Minimum value for a variable of type signed char. - 128
SCHAR_MAX	Maximum value for a variable of type signed char.	127
UCHAR_MAX	Maximum value for a variable of type unsigned char.	255 (0xff)
CHAR_MIN	Minimum value for a variable of type char. - 128; 0 if / J option used
CHAR_MAX	Maximum value for a variable of type char.	127; 255 if / J option used
MB_LEN_MAX	Maximum number of bytes in a multicharacter constant.	5
SHRT_MIN	Minimum value for a variable of type short. - 32768
SHRT_MAX	Maximum value for a variable of type short.	32767
USHRT_MAX	Maximum value for a variable of type unsigned short.	65535 (0xffff)
INT_MIN	Minimum value for a variable of type int. - 2147483648
INT_MAX	Maximum value for a variable of type int.	2147483647
UINT_MAX	Maximum value for a variable of type unsigned int.	4294967295 (0xffffffff)
LONG_MIN	Minimum value for a variable of type long. - 2147483648
LONG_MAX	Maximum value for a variable of type long.	2147483647
ULONG_MAX	Maximum value for a variable of type unsigned long.	4294967295 (0xffffffff)
LLONG_MIN	Minimum value for a variable of type long long - 9223372036854775808
LLONG_MAX	Maximum value for a variable of type long long	9223372036854775807
ULLONG_MAX	Maximum value for a variable of type unsigned long long	18446744073709551615 (0xffffffffffffffff)
*/
