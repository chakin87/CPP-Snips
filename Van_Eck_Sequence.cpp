#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <algorithm>

//std::cout << x;
#define OUT(x) std::cout << x;
#define IN_INT(i)  std::cin >> i;\
	   while(std::cin.fail()) {\
			std::cout << "Integer not entered!" << std::endl;\
			std::cin.clear();\
			std::cin.ignore(256, '\n');\
			std::cout << "Enter an integer: ";\
			std::cin >> i;\
	   }\

void Intro(unsigned long& i, unsigned long& itotal, std::vector<unsigned long>& vaneckVec) {

	OUT("Welcome to the Van Eck Sequence!");
	OUT("\n\nEnter the number of iterations: ");

	//IN_INT(i);   // Uncomment to manually choose a number of iterations of Van Eck Sequence

		// Number of iterations
	i = 10000;
	itotal = i;

	// Insert the first 0 into the list
	vaneckVec.emplace(vaneckVec.end(), 0);
}

void InsertValue(std::vector<unsigned long>& vaneckVec, unsigned long& value) {
	// We insert the next value into the list.
	vaneckVec.emplace(vaneckVec.end(), value);
	// Here we display the iteration and the value at said iteration.
	//OUT("Iteration " << index++ << ": " << value << "\n"); // Uncomment this to display each 'iteration: value'.
}

void Percent(unsigned long i, unsigned long itotal) {
	while (1) {
		if (i % 100 == 0) {
			system("CLS");
			std::cout << "Percent left to process: " << (100 * ((float)i / (float)itotal));
		}
	}
}

int main(int argc, char** argv) {

	unsigned long i;
	unsigned long itotal;
	unsigned long index = 0;
	unsigned long value = 0;
	bool launched = false;
	std::vector<unsigned long> VanEck_Values;
	
	Intro(i, itotal, VanEck_Values);


		
	
	while (i--) {

		InsertValue(VanEck_Values, value);

		///std::thread ins(std::ref(InsertValue), std::ref(VanEck_Values), std::ref(value)); 
		///ins.join();
	
		// Reverse iterate throught VanEck vec to check for values previous loc.
		auto check = std::find(VanEck_Values.rbegin()+1, VanEck_Values.rend(), value);

		// If the value could not be found, then the new value is 0.
		if (check == VanEck_Values.rend()) {
			value = 0;
			// Having continue here increases the speed of a 10,000 iteration 
			// run, with printing the sequence, by roughly .3 sec.
			// Why???
			continue;
		}
		// If the value is found, then we use the distance between the end of the list 
		// and the value index as our new value.
		else {
			auto distance = std::distance(VanEck_Values.rbegin(), check);
				value = distance;
		}

		if (i % 100 == 0) {
			system("CLS");
			OUT("Percent completed: " << 100 - (100 * ((float)i / (float)itotal)));
		}

	}
	
	
	// Now that we are out of the loop, we print the entire list in csv format.
	OUT("\n\nComplete list of Van Eck Sequence:\n")

	for (auto& value : VanEck_Values)
	{
		// If this is the last value in the list, then we don't need a comma.
		if (value == *(VanEck_Values.end() - 1)){
			OUT(value);
		}
		// If it is not the last value, then we can add the comma.
		else {
			OUT(value << ", ");
		}
	}


	/* // Uncomment this block to view the sorted sequence
	//Let's sort the vector and reprint it to see how many 0s pop up
	std::sort(VanEck_Values.begin(), VanEck_Values.end());


	// Now that we are out of the loop, we print the entire list in csv format.
	OUT("\n\nComplete SORTED list of Van Eck numbers:\n")

		for (auto& value : VanEck_Values)
		{
			// If this is the last value in the list, then we don't need a comma.
			if (value == *(VanEck_Values.end() - 1)) {
				OUT(value);
			}
			// If it is not the last value, then we can add the comma.
			else {
				OUT(value << ", ");
			}
		}
	*/


}