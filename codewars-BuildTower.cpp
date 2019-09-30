/*
Build Tower
Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *

Python: return a list;
JavaScript: returns an Array;
C#: returns a string[];
PHP: returns an array;
C++: returns a vector<string>;
Haskell: returns a [String];
Ruby: returns an Array;
Have fun!

for example, a tower of 3 floors looks like below

[
  '  *  ',
  ' *** ',
  '*****'
]
and a tower of 6 floors looks like below

[
  '     *     ',
  '    ***    ',
  '   *****   ',
  '  *******  ',
  ' ********* ',
  '***********'
]
*/

//--------------------------------------------------------------------------------------//
//My code
#include <vector>
#include <iostream>
#include <string>

class Kata
{
public:
	std::vector<std::string> towerBuilder(int nFloors)
	{
		int row_len = ((nFloors * 2) - 1); // This is the length or each row using '*' and/or ' '
		int num_stars;
		int star_start;
		int star_stop;
		std::string rowstr = "";
		std::vector<std::string> resultant;
		
		for (int i = 0; i < nFloors; ++i) {
			num_stars = ((i * 2) + 1); // This givs the correct number of stars in each row of the loop.
			star_start = ((row_len / 2) - i);
			star_stop = (row_len - ((row_len / 2) - i));

			
			//std::cout << "Row: " << (i + 1) << ", stars: " << num_stars << ", row_len: " << row_len << std::endl; // debug
			//std::cout << "star_start: " << star_start << ", star_stop: " << star_stop << std::endl; // debug
			for (int j = 0; j < row_len; ++j) {
				if (((j ) >= star_start) && ((j ) < star_stop)){
					rowstr += '*';
				}
				else {
					rowstr += ' ';
				}
			}
			//`std::cout << rowstr << std::endl; // debug
			resultant.push_back(rowstr);
			rowstr = "";
		}
		return resultant;
	}
};

//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {


	Kata k;

//	k.towerBuilder(1);	//debug
//	k.towerBuilder(3);	//debug
//	k.towerBuilder(6);	//debug
//	k.towerBuilder(9);	//debug
//	k.towerBuilder(2);	//debug
//	k.towerBuilder(90); //debug

	for (auto star : (std::vector<std::string>)(k.towerBuilder(100))) {
		std::cout << star << std::endl;
	}




	char c;
	std::cin >> c;

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem

std::vector<std::string> towerBuilder(int nFloors)
{
	std::vector<std::string> ret;
	for (int i = 0; i < nFloors; i++)
	{
		ret.push_back(std::string(nFloors - i - 1, ' ') +
			std::string((i * 2) + 1, '*') +
			std::string(nFloors - i - 1, ' '));
	}
	return ret;
}
//--------------------------------------------------------------------------------------//

std::vector<std::string> towerBuilder(const size_t& nFloors)
{
	const size_t center = nFloors - 1;
	std::string floor(2 * nFloors - 1, ' ');
	std::vector<std::string> tower;
	for (size_t shift = 0; shift <= center; ++shift)
	{
		floor.replace(center + shift, 1, "*");
		floor.replace(center - shift, 1, "*");
		tower.push_back(floor);
	}
	return tower;
}
//--------------------------------------------------------------------------------------//

std::vector<std::string> towerBuilder(int nFloors)
{
	std::vector<std::string> vec;

	const int length = nFloors * 2 - 1;
	const int middle = nFloors - 1;
	std::string str(length, ' ');

	for (int i = 0; i < nFloors; ++i)
	{
		str[middle - i] = str[middle + i] = '*';
		vec.push_back(str);
	}

	return vec;
}
//--------------------------------------------------------------------------------------//
std::vector<std::string> towerBuilder(int nFloors)
{
	std::vector<std::string> res(nFloors, std::string((nFloors * 2) - 1, ' '));

	for (unsigned i = 0; i < nFloors; ++i)
		std::fill_n(res[i].begin() + (res[i].size() * 0.5 - i), (i * 2) + 1, '*');

	return res;
}



