//				std::sort




#include "functions.h"
#include <algorithm> //std::sort
#include <vector>    // std:::vector


int main(int argc, char** argv) {

	std::vector<int> v = { 88, 6, 55, 43, 2, 1, 4, 5, 7, 36, 12, 45, 67, 3, 23, 56, 32, 12, 4 };
	std::cout << "\n[Unsorted][N/A]\n";
	for (auto i : v) {
		std::cout << i << " ";
	}std::cout << "\n";
	
	//    Let's sort the vector with the tradition std::sort(starting itr, end itr) - sort ascending.
	std::sort(v.begin(), v.end());

	std::cout << "\n[Sorted][std::sort(v.begin(), v.end())\n";
	for (auto i : v) {
		std::cout << i << " ";
	}std::cout << "\n";


	std::sort(v.begin(), v.end(), std::greater<int>());

	std::cout << "\n[Sorted][std::sort(v.begin(), v.end(), std::greater<int>())\n";
	for (auto i : v) {
		std::cout << i << " ";
	}std::cout << "\n";



	//    This lambda sorts in ascending order, but it puts 1 at the end.
	auto lambda = [](int a, int b) {
		if (a == 1)
			return false;
		if (b == 1)
			return true;
		return a < b;
	};
	std::sort(v.begin(), v.end(), lambda);

	std::cout << "\n[Sorted][std::sort(v.begin(), v.end(), lambda)\n";
	for (auto i : v) {
		std::cout << i << " ";
	}std::cout << "\n";



	std::cin.get();
	return 0;
}