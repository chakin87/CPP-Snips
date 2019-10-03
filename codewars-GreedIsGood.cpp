/*
Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll. For example, a "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   50 + 2 * 100 = 250
 1 1 1 3 1   1000 + 100 = 1100
 2 4 4 5 4   400 + 50 = 450
In some languages, it is possible to mutate the input to the function. This is something that you should never do. If you mutate the input, you will not be able to pass all the tests.
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




int score(const std::vector<int>& dice) {
	int scores[7]{ 0};
	int total = 0;
	for (auto die : dice) {
		scores[die]++;
		std::cout << "scores[" << die << "] == " << scores[die] << std::endl;
	}
	for (int i = 1; i < 7; ++i) {

		if (scores[i] >= 3) {
			if (i == 1) {
				total += 1000;
				scores[i] -= 3;
			}
			else {
				total += i * 100;
				scores[i] -= 3;
			}
		}

		if (i == 1 && scores[i] < 3) {
			total += scores[i] * 100;
		}
		else if (i == 5 && scores[i] < 3) {
			total += scores[i] * 50;
		}
	}
	std::cout << total;

	return total;
}
//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {

#include <vector>




	score({ 1,2,3,3,2}); std::cout << std::endl;
	score({ 3,2,3,3,2});	std::cout << std::endl;
	score({ 2,4,4,5,4});	std::cout << std::endl;
	score({ 1,1,1,3,1});	std::cout << std::endl;
	score({ 5,1,3,4,1});	std::cout << std::endl;





	char c;
	std::cin >> c; //Keep the darn window open! LOLz

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem

#include <vector>

int score(const std::vector<int>& dice) {
	unsigned cs[7] = {};
	for (auto d : dice)
		cs[d]++;
	return
		cs[1] / 3 * 1000 + cs[6] / 3 * 600 + cs[5] / 3 * 500 +
		cs[4] / 3 * 400 + cs[3] / 3 * 300 + cs[2] / 3 * 200 +
		cs[1] % 3 * 100 + cs[5] % 3 * 50;
}
//--------------------------------------------------------------------------------------//
int score(const std::vector<int>& dice)
{
	int score = 0;
	int count[7] = { 0 };
	for (auto v : dice)
		if (++count[v] == 3)
		{
			score += (v == 1) ? 1000 : v * 100;
			count[v] = 0;
		}
	score += count[1] * 100;
	score += count[5] * 50;
	return score;
}
//--------------------------------------------------------------------------------------//
#include <unordered_map>

int score(const std::vector<int>& dice)
{
	std::unordered_map<int, int> counters;
	for (auto value : dice) {
		++counters[value];
	}
	int sum = 0;
	for (auto cnt : counters) {
		sum += cnt.second / 3 * cnt.first * 100 * (cnt.first == 1 ? 10 : 1);                               //1000 200 300 400 500 600 ?
		sum += (cnt.first == 1 ? cnt.second % 3 * 100 : 0) + (cnt.first == 5 ? cnt.second % 3 * 50 : 0);   // 100 500 ?           
	}
	return sum;
}
//--------------------------------------------------------------------------------------//
int score(const std::vector<int>& dice) {
	int counter;
	int score = 0;
	for (int i = 1; i < 7; i++) {
		counter = count(dice.begin(), dice.end(), i);
		if (counter / 3 > 0)
			if (i == 1) score += 1000;
			else score += (i * 100);
		if (i == 1) score += (counter % 3 * 100);
		else if (i == 5) score += (counter % 3 * 50);
	}
	return score;
}
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