//#include <cstdlib>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>


//
//
//
//
//
//
//
//
//
//
//

std::mutex vectorLock;
std::vector<unsigned int> vPrimeNumbers;

void FindPrimeNumbers(unsigned int start,
	unsigned int end) {

	// For loop that skips evens
	for (unsigned int x = start; x <= end; x += 2) {

		// If a modulus is 0 we know it isn't prime
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) {
				break;
			}
			else if ((y + 1) == x) {
				vectorLock.lock();
				vPrimeNumbers.push_back(x);
				vectorLock.unlock();
			}
		}
	}
}

void FindPrimesWithThreads(unsigned int start,
	unsigned int end,
	unsigned int numThreads) {

	std::vector<std::thread> vThreads;

	// Split calculations between threads
	unsigned int threadSpread = end / numThreads;
	unsigned int newEnd = start + threadSpread - 1;

	// Create prime list for each thread
	for (unsigned int x = 0; x < numThreads; x++) {
		vThreads.emplace_back(FindPrimeNumbers,
			start, newEnd);

		start += threadSpread;
		newEnd += threadSpread;
	}

	for (auto& t : vThreads) {
		t.join();
	}

}


int main()
{
	// Start Timer
	int cStart = clock();

	FindPrimesWithThreads(1, 100000, 6); // Using 6 threads.

	// End Time
	int cEnd = clock();

	for (auto i : vPrimeNumbers)
		printf_s("%d\n", i);       // Faster print?
		//std::cout << i << "\n";  // Slower print? I'll have to time it...

	// Print results
	std::cout << "[Prime Number Calculation Time] (" <<
		(cEnd - cStart) / double(CLOCKS_PER_SEC)
		<< "s)"<< std::endl;



	std::getchar();

	return 0;
}
