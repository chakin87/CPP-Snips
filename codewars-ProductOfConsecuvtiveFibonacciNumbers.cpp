/*

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

typedef unsigned long long ull;

class ProdFib
{
public:
	static std::vector<ull> productFib(ull prod){}
	static ull fibIndex(int nthFib) {
		if (nthFib <= 1) return nthFib;
		return fibIndex(nthFib - 1) + fibIndex(nthFib - 2);
	}
};

//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {


	std::cout << ProdFib::fibIndex(9);







	char c;
	std::cin >> c; //Keep the darn window open! LOLz

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem

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

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//