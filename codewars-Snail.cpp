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
	int rowLength = snail_map.size();
	std::vector<int> retVec;
	std::cout << std::endl << "rowLength: " << rowLength << std::endl;

	for (int i = 0; i <= snail_map.size() * snail_map.size(); ++i) {

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


	
	return {0};
}

//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {

	std::vector<std::vector<int>> test_snail_map{ {1, 2 ,3}, 
												  {4, 5, 6}, 
												  {7, 8, 9} };

	std::vector<std::vector<int>> test_snail_map2{ {1,  2,  3,  4,  5,  6},
											       {7,  8,  9,  10, 11, 12},
											       {13, 14, 15, 16, 17, 18} };

	snail(test_snail_map);

	std::cout << std::endl << "-------------------------------------------------" << std::endl;

	snail(test_snail_map2);








	
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