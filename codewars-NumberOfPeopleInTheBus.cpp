/*
Number of people in the bus
There is a bus moving in the city, and it takes and drop some people in each bus stop.

You are provided with a list (or array) of integer arrays (or tuples). Each integer array has two items which represent number of people get into bus (The first item) and number of people get off the bus (The second item) in a bus stop.

Your task is to return number of people who are still in the bus after the last bus station (after the last array). Even though it is the last bus stop, the bus is not empty and some people are still in the bus, and they are probably sleeping there :D

Take a look on the test cases.

Please keep in mind that the test cases ensure that the number of people in the bus is always >= 0. So the return integer can't be negative.

The second value in the first integer array is 0, since the bus is empty in the first bus stop.
*/

#include <utility>
#include <vector>

unsigned int number(const std::vector<std::pair<int, int>>& busStops) {
	unsigned int peeps = 0;

	for (auto pair : busStops) {
		peeps += pair.first;
		peeps -= pair.second;
	}

	return peeps;
}


//Other Answers I liked.
//----------------------------------------------------------------------------------------------//
#include<vector>
#include<numeric>

unsigned int number(const std::vector<std::pair<int, int>>& busStops) {
	return std::accumulate(busStops.begin(), busStops.end(), 0, [](int sum, const auto& p) {
		return sum + p.first - p.second;
	});
}
//----------------------------------------------------------------------------------------------//



/*
Sample Tests:


----------------------------------------------------------------------------------------------
using V = std::pair<int, int>;

using V2 = std::vector<V>;

Describe(Number){
  It(BasicTests){
	Assert::That(number(V2{V{10,0},V{3,5},V{5,8}}), Equals(5));
	Assert::That(number(V2{V{3,0},V{9,1},V{4,10},V{12,2},V{6,1},V{7,10}}), Equals(17));
	Assert::That(number(V2{V{3,0},V{9,1},V{4,8},V{12,2},V{6,1},V{7,8}}), Equals(21));
	Assert::That(number(V2{V{0,0}}), Equals(0));
	Assert::That(number(V2{V{10,0},V{13,0},V{17,40}}), Equals(0));

  }

};
----------------------------------------------------------------------------------------------
*/