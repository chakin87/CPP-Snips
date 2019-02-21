
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>

// The BubbleGum Sort :P
// Works with most STL containers.
// NOTE: Will not work with maps AND container class
// must have the .size() member. 
template<typename Container>
void BubbleSort(Container& container) {

	int i = container.size() - 1;

	while (i >= 1) {
		int  j = 0;
		while (j < i) {
			if (container[j] >= container[j + 1]) {
			int temp = container[j];
				container[j] = container[j + 1];
				container[j + 1] = temp;
			}
			j += 1;
		}
		i -= 1;
	}
}

std::vector<int> RandomIntVec(int numOfNums, int min, int max);


int main() {


	std::vector<int> vecVals = RandomIntVec(10, 1, 50);

	BubbleSort(vecVals);

	for (auto x : vecVals)
		std::cout << x << "\n";

	std::getchar();
	return 0;

}

std::vector<int> RandomIntVec(int numOfNums,
	int min, int max) {
	std::vector<int> vecValues;

	srand(time(NULL));

	int i = 0, randVal = 0;

	while (i < numOfNums) {

		randVal = min + std::rand() % ((max + 1) - min);
		vecValues.push_back(randVal);
		i++;
	}
	return vecValues;
}