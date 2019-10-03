/*
Instructions
Output
A child is playing with a ball on the nth floor of a tall building. The height of this floor, h, is known.

He drops the ball out of the window. The ball bounces (for example), to two-thirds of its height (a bounce of 0.66).

His mother looks out of a window 1.5 meters from the ground.

How many times will the mother see the ball pass in front of her window (including when it's falling and bouncing?

Three conditions must be met for a valid experiment:
Float parameter "h" in meters must be greater than 0
Float parameter "bounce" must be greater than 0 and less than 1
Float parameter "window" must be less than h.
If all three conditions above are fulfilled, return a positive integer, otherwise return -1.

Note:
The ball can only be seen if the height of the rebounding ball is strictly greater than the window parameter.

Example:
- h = 3, bounce = 0.66, window = 1.5, result is 3

- h = 3, bounce = 1, window = 1.5, result is -1

(Condition 2) not fulfilled).
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

class Bouncingball
{
public:
	static int bouncingBall(double h, double bounce, double window) {
			int height_0 = h;
			bool noBounce = false;
			static std::string Err_win = "Height is lower than or equal to window";
			static std::string Err_b = "Ball has too much or too little bounce";
			static std::string Err_h = "Height is less than 0";
			int ret = 1;

			if ((h * bounce) < window) noBounce = true;
			h *= bounce;

		if ((h > 0) && (bounce > 0 && bounce < 1 )&& (window <= h) && noBounce == false) {		
			while (h > window) {
				ret+=2;
				h *= bounce;
			} 
			std::cout << "Bouncingball::bouncingBall(" << height_0 << ", " << bounce << ", " << window << "): " << ret << std::endl; //debug

			return ret; 
		}
		else if (noBounce) { 
			std::cout << "noBouncingball::bouncingBall(" << height_0 << ", " << bounce << ", " << window << "): " << ret << std::endl; //debug
			return ret; }
		else {
			//Here's a fun ternary statement decipher...																   //debug
			//std::cout << "Bouncingball::bouncingBall(" << h << ", " << bounce << ", " << window << "): -1, \n->Due to: " //debug
			//	<< ((h < 0)? Err_h:(bounce <= 0 || bounce >= 1)?Err_b : (window > height_0)? Err_win : "ERROR UNKNOWN!!")  //debug
			//	<< std::endl;																							   //debug
			return ret - 2;
		}
	}
};

//--------------------------------------------------------------------------------------//

//Testing Stage
int main(int argc, char** argv) {


	Bouncingball::bouncingBall(30, .66, 1.5);
	///std::cout << std::endl;
	///Bouncingball::bouncingBall(3, 1, 1.5);
	///std::cout << std::endl;
	///Bouncingball::bouncingBall(300000000, .66, 1.5);
	///std::cout << std::endl;
	///Bouncingball::bouncingBall(300000000, .5, 1.5);
	///std::cout << std::endl;
	///Bouncingball::bouncingBall(3, .66, 3.5);
	///std::cout << std::endl;
	///Bouncingball::bouncingBall(-3, .66, 1.5);
	///std::cout << std::endl;
	///Bouncingball::bouncingBall(3, -.66, 1.5);
	///
	///std::cout << std::endl;
	///std::cout << std::endl;
	Bouncingball::bouncingBall(3, .66, 1.5);
	///std::cout << std::endl;
	///std::cout << std::endl;
	Bouncingball::bouncingBall(1.6, .66, 1.5);
	///std::cout << std::endl;
	///



	char c;
	std::cin >> c; //Keep the darn window open! LOLz

	return 0;
}

//--------------------------------------------------------------------------------------//
//Other code that solved the problem

//This one is genuis. I don't know how they came up with this.
static int bouncingBall(double h, double bounce, double window) {
	if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h) return -1;
	return (int)(floor(log(window / h) / log(bounce)) * 2 + 1);
}
//--------------------------------------------------------------------------------------//
int Bouncingball::bouncingBall(double h, double bounce, double window)
{
	if ((h <= 0) || (window >= h) || (bounce <= 0) || (bounce >= 1))
		return -1;
	int seen = -1;
	while (h > window)
	{
		seen += 2;
		h = h * bounce;
	}
	return seen;
}
//--------------------------------------------------------------------------------------//
int Bouncingball::bouncingBall(double h, double bounce, double window) {
	if (bounce >= 1 || bounce <= 0) return -1;
	int sum = -1;
	for (h; h > window; h *= bounce, sum += 2);
	return sum;
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

//--------------------------------------------------------------------------------------//