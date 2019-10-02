/*
Two Sum
1855388% of 1,127601 of 8,457wthit56
C++
14
VIM
EMACS
Instructions
Output
Write a function that takes an array of numbers (integers for the tests) and a target number. It should find two different items in the array that, when added together, give the target value. The indices of these items should then be returned in a tuple like so: (index1, index2).

For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.

The input will always be valid (numbers will be an array of length 2 or greater, and all of the items will be numbers; target will always be the sum of two different items from that array).

Based on: http://oj.leetcode.com/problems/two-sum/

twoSum [1, 2, 3] 4 === (0, 2)
*/

//Libraries - NOTE: all may not be used in this file.
//--------------------------------------------------------------------------------------//
//My code
#include <vector>
#include <iostream>
#include <string>

#include <algorithm>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
	std::vector<int> copy;
	for (int i = 0; i < numbers.size(); ++i) {
		copy.push_back(numbers[i]);
	}
	bool found = false;
	std::pair<std::size_t, std::size_t> goldenTicket;
	std::sort(copy.begin(), copy.end(), ([&goldenTicket,&found, &copy, &target](int l, int r) {
		if ((l + r) == target && found == false && (std::find(copy.begin(), copy.end(), l) - copy.begin()) != (std::find(copy.begin(), copy.end(), r) - copy.begin())) {
			found = true;
			goldenTicket = { (std::find(copy.begin(), copy.end(), l) - copy.begin()), (std::find(copy.begin(), copy.end(), r) - copy.begin()) };
		}
		return 0; })
	);
	std::cout << "GolderTicket: {" << goldenTicket.first << ", " << goldenTicket.second	<< "}" << std::endl;	   //debug
	return goldenTicket;
}


std::pair<std::size_t, std::size_t> btwo_sum(const std::vector<int>& numbers, int target) {


	std::vector<int> copy;
	for (int i = 0; i < numbers.size(); ++i) {
		copy.push_back(numbers[i]);
	}
	std::pair<std::size_t, std::size_t> goldenTicket;
	std::sort(copy.begin(), copy.end(), ([&goldenTicket, &copy, &target](int l, int r) {
		if ((l + r) == target) {
			goldenTicket = { (std::find(copy.begin(), copy.end(), l) - copy.begin()), (std::find(copy.begin(), copy.end(), r) - copy.begin()) };
		}

		return 1; })
	);
	//std::cout << "GolderTicket: {" << goldenTicket.first << ", " << goldenTicket.second	<< "}" << std::endl;	   //debug

	std::cout << "copy {";
	for (auto number : copy) {
		std::cout << number << ":";
	}std::cout << "}" << std::endl;
	return goldenTicket;
}
//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {


	std::vector<int> testVec{ 11, 78, 87, 86, 99, 102, 34, 1, 4, 2, 9, 7, 5, 4,9, 10, 15, 19, 1 };
	std::vector<int> testVec2{ 5, 4, 3, 3, 1};
	std::vector<int> testVec3{2, 5, 4, 3, 3, 1};
	std::vector<int> testVec4{ 6, 0, 5, 4, 3, 3, 1};
	
	two_sum(testVec, 9);
	two_sum(testVec2, 6);
	two_sum(testVec3, 6);
	two_sum(testVec4, 6);







	char c;
	std::cin >> c; //Keep the darn window open! LOLz

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
	for (auto i = 0; i < numbers.size(); i++)
		for (auto j = i + 1; j < numbers.size(); j++)
			if (numbers[i] + numbers[j] == target) return { i, j };
}
//--------------------------------------------------------------------------------------//
#include <unordered_map>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
	std::unordered_map<int, std::size_t> counterparts;
	for (std::size_t i = 0; i < numbers.size(); ++i) {
		auto it = counterparts.find(numbers[i]);
		if (it != counterparts.end())
			return { it->second, i };
		counterparts.emplace(target - numbers[i], i);
	}
	return { -1, -1 };
}
//--------------------------------------------------------------------------------------//
std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
	int pos;
	std::vector<int>::const_iterator vit = numbers.begin(), pit = vit;
	for (pit++; vit != numbers.end(); vit++, pit++)
		if ((pos = std::find(pit, numbers.end(), target - *vit) - numbers.begin()) != numbers.size())
			return std::make_pair(vit - numbers.begin(), pos);
	return std::make_pair(0, 0);
}
//--------------------------------------------------------------------------------------//
#include <unordered_map>
std::pair<std::size_t, std::size_t> two_sum(const std::vector<int32_t>& numbers, const int32_t target) {
	if (!numbers.size()) return { ~0,~0 };
	std::unordered_map<int32_t, uint32_t> map;
	map.reserve(numbers.size());
	for (uint_fast32_t i = 0; i < numbers.size(); map[target - numbers[i]] = i, ++i)
		if (map.find(numbers[i]) != map.end()) return { map[numbers[i]],i };
	return { ~0,~0 };
}
//--------------------------------------------------------------------------------------//

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
	for (auto it1 = numbers.cbegin(); it1 != numbers.cend(); it1++)
	{
		for (auto it2 = std::next(it1); it2 != numbers.cend(); it2++)
		{
			if (*it1 + *it2 == target)
			{
				return std::make_pair(
					std::distance(numbers.cbegin(), it1),
					std::distance(numbers.cbegin(), it2)
				);
			}
		}
	}
	return { 0, 0 };
}










