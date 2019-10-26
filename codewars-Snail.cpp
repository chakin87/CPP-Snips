/*
Instructions
Output
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
		 [4,5,6],
		 [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
		 [8,9,4],
		 [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as [[]]


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

// My First Prototype. This will eventually be consolidated greatly. //Not Finished
std::vector<int> snail(std::vector<std::vector<int>> snail_map) {
	enum {
		RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3
	};
	int ptrDir = RIGHT;
	int xPtr = 0;
	int yPtr = 0;
	int rPtr = 0;
	int rowLength = snail_map[0].size();
	std::vector<int> retVec;
	//std::cout << std::endl << "rowLength: " << rowLength << std::endl;

	for (int i = 0; i <= ((snail_map[0].size() * snail_map[0].size()) + 3); ++i) {

		if(ptrDir == RIGHT) {
			if (rPtr < rowLength) {
				retVec.push_back(snail_map[yPtr][xPtr]);//if right incr x for row len; decr row len; NOTE [y][++x] 
				std::cout << "snail_map[" << yPtr << "][" << xPtr << "]: " << snail_map[yPtr][xPtr] << ", rowPtr: " << rPtr << ", rowLength: " << rowLength << std::endl;
				++rPtr; ++xPtr;
			}
			else {
				if (rowLength == 0) {
					break;
				}
				rPtr = 0; --rowLength; --xPtr; ++yPtr; ptrDir = DOWN;
			}
		}
		if (ptrDir == DOWN) {
			if (rPtr < rowLength) {
				std::cout << "snail_map[" << yPtr << "][" << xPtr << "]: " << snail_map[yPtr][xPtr] << ", rowPtr: " << rPtr << ", rowLength: " << rowLength << std::endl;
				retVec.push_back(snail_map[yPtr][xPtr]);  //if down incr y for row len;; NOTE [++y][x]
				++rPtr; ++yPtr;

			}
			else {
				if (rowLength == 0) {
					break;
				}
				rPtr = 0; --yPtr; --xPtr; ptrDir = LEFT;
			}
		}
		if (ptrDir == LEFT) {
			if (rPtr < rowLength) {
				std::cout << "snail_map[" << yPtr << "][" << xPtr << "]: " << snail_map[yPtr][xPtr] << ", rowPtr: " << rPtr << ", rowLength: " << rowLength << std::endl;
				retVec.push_back(snail_map[yPtr][xPtr]);  //if left decr x for row len; decr row len; NOTE [y][--x]
				++rPtr;  --xPtr;
			}
			else {
				if (rowLength == 0) {
					break;
				}
				rPtr = 0; --rowLength; ++xPtr; --yPtr; ptrDir = UP;
			}
		}
		if (ptrDir == UP) {
			if (rPtr < rowLength) {
				std::cout << "snail_map[" << yPtr << "][" << xPtr << "]: " << snail_map[yPtr][xPtr] << ", rowPtr: " << rPtr << ", rowLength: " << rowLength << std::endl;
				retVec.push_back(snail_map[yPtr][xPtr]);  //if up decr y for rowlen; NOTE [--y][x]
				++rPtr; --yPtr;
			}
			else {
				if (rowLength == 0) {
					break;
				}
				rPtr = 0; ++yPtr; ++xPtr;   ptrDir = RIGHT;
			}
		}
	}


	
	return {};
}

//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {

	std::vector<std::vector<int>> test_snail_mapA{ {1, 2},
											      {4, 5},
											     };

	std::vector<std::vector<int>> test_snail_mapB{ {1, 2}
	};


	std::vector<std::vector<int>> test_snail_map{ {1, 2 ,3}, 
												  {4, 5, 6}, 
												  {7, 8, 9} };

	std::vector<std::vector<int>> test_snail_map2{ {1,  2,  3,  4,  5,  6},
											       {7,  8,  9,  10, 11, 12},
											       {13, 14, 15, 16, 17, 18},
												   {19, 20, 21, 22, 23, 24}, 
												   {25, 26, 27, 28, 29, 30},
												   {31, 32, 33, 34, 35, 36}


	};


	std::vector<std::vector<int>> test_snail_map3{ {1,  2,  3,  4,  5,  6, 61},
												   {7,  8,  9,  10, 11, 12, 121},
												   {13, 14, 15, 16, 17, 18, 181},
												   {19, 20, 21, 22, 23, 24, 241},
												   {25, 26, 27, 28, 29, 30, 301},
												   {31, 32, 33, 34, 35, 36, 361},
	                                               {37, 38, 39, 40, 41, 42, 43}


	};

	snail(test_snail_map);

	std::cout << std::endl << "-------------------------------------------------" << std::endl;

	snail(test_snail_map2);

	std::cout << std::endl << "-------------------------------------------------" << std::endl;

	snail(test_snail_map3);

	std::cout << std::endl << "-------------------------------------------------" << std::endl;

	snail(test_snail_mapA);

	std::cout << std::endl << "-------------------------------------------------" << std::endl;

	snail(test_snail_mapB);

	std::cout << std::endl << "-------------------------------------------------" << std::endl;

//	snail(test_snail_mapC);







	
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