
C++ - stringstreams
The C++ stream library is powerful and it allows easy formatted input output operations.With stringstreams you can perform this input / output to string, this allows you to convert numbers(or any type with the << >> stream operators overloaded) to and from strings.
With stringstreams you can use the same syntax to convert the different numeric types.
To use stringstreams you need to #include <sstream>
Number to String
Converting a number to a string takes two steps using stringstreams:
Outputting the value of the number to the stream
Getting the string with the contents of the stream
As with this conversion needs only output operation with the stream, an ostringstream(output string stream) can be used instead of the stream for both input and output(stringstream)

Here is an example which shows each step :
1
2
3
4
5
6
7
8
9
10
11
int Number = 123;       // number to be converted to a string

string Result;          // string which will contain the result

ostringstream convert;   // stream used for the conversion

convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

Result = convert.str(); // set 'Result' to the contents of the stream

		  // 'Result' now is equal to "123" 

This operation can be shorten into a single line :
1
2
int Number = 123;
string String = static_cast<ostringstream*>(&(ostringstream() << Number))->str();
Here is constructed an unnamed stringstream object and performed the output ostringstream() << Number Then, since the << returns a reference to an ostream(a base of ostringstream) the result of the operation needs to be casted back to a stringstream static_cast<ostringstream*> Finally, we get the contents of the resulting stream as a string->str() and we assign that value to the string string String =
Custom formatting

Stringstreams allow manipulators and locales to customize the result of these operations so you can easily change the format of the resulting string

Example : -This is not a complete program -
	1
	2
	3
	4
	5
	6
	7
	8
	9
	10
	11
	12
	13
	14
	15
	16
	17
	18
	19
	20
	21
	22
	23
	24
	25
	26
	27
	28
	29
	30
	31
	32
	33
	// Headers needed:

#include <iomanip>
#include <locale>
#include <sstream>
#include <string> // this should be already included in <sstream>


// Defining own numeric facet:

class WithComma : public numpunct<char> // class for decimal numbers using comma instead of point
{
protected:
	char do_decimal_point() const { return ','; } // change the decimal separator
};


// Conversion code:

double Number = 0.12;           // Number to convert to string

ostringstream Convert;

locale MyLocale(locale(), new WithComma);// Crate customized locale

Convert.imbue(MyLocale);       // Imbue the custom locale to the stringstream

Convert << fixed << setprecision(3) << Number; // Use some manipulators

string Result = Convert.str(); // Give the result to the string

// Result is now equal to "0,120"

String to Number
Also converting a string to a number via stringstream takes two steps :
Constructing the stream from the string
Reading the value into the variable
For this (as you need to read input from the stream) an istringstream will be used
While a number can always be converted in a string, a string must be valid to be converted to a number(eg : An attempt of converting "hello" to an integer would certainly fail) so on this conversion, some checking must be done

Here is the code example :
1
2
3
4
5
6
7
8
9
10
11
string Text = "456"; // string containing the number

int Result;          //number which will contain the result

istringstream convert(Text); // stringstream used for the conversion constructed with the contents of 'Text' 
							 // ie: the stream will start containing the characters of 'Text'

if (!(convert >> Result)) //give the value to 'Result' using the characters in the stream
Result = 0;             //if that fails set 'Result' to 0

//'Result' now equal to 456  

This conversion is even easier to reduce to a single line :
1
2
3
string Text = "456";
int Number;
if (!(istringstream(Text) >> Number)) Number = 0;
In the above code an object of istringstream gets constructed from 'Text' istringstream(Text) and its contents get read into the numeric variable >> Number.
If that operation fails if (!, 'Number' is set to zero Number = 0;
	Locales and manipulators can be used as well as with any stream

	More complex cases

	A generic stringstream(which could be used both for input and for output) can be useful in some more complex situations and in almost any situation you need to perform operations not provided by string
	Simple Sample Functions

	Here are listed some functions to perform these conversion using stringstreams:

1
2
3
4
5
6
7
template <typename T>
string NumberToString(T Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}
Usage: NumberToString(Number);
1
2
3
4
5
6
7
template <typename T>
T StringToNumber(const string &Text)
{
	istringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}
Usage: StringToNumber<Type>(String);

Notice: In the code examples std::was omitted to make the code simpler
	Using the last functions, there is no way of detecting whether the conversion succeded or failed


	C++11
	C++11 introduced some standard library functions that can directly convert
	basic types to std::string objects and vice - versa.

	std::to_string Converts basic numeric types to strings.

	The set of functions
	stoi, stol, stoll convert to integral types, the functions
	stof, stod, stold to floating - point values.
	These functions are declared in declared in <string>.

	Note that since these functions were added in the latest version of the C++ standard,
	they may not be available unless your implementation is very recent.

	1
	2
	3
	4
	5
	int number = 123;
		string text = to_string(number);

		text = "456"
			number = stoi(number);

