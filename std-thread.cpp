//				STD::THREADS 
//    Divide and conquer with threaded workloads!
 




#include "functions.h"
#include <thread>
#include <conio.h>

static bool work = true;
static int th = 0, an = 0;

void working_hard_for_a_dollar() {
	while (work) {
		++an;
		std::cout << "working hard for a dollor\n";
	}
}
void working_hard_not_getting_far() {
	while (work) {
		++th;
		std::cout << "working my fingers to the bone!\n";
	}
}
void hardly_working() { 
	using namespace std::literals::chrono_literals;
	std::this_thread::sleep_for(10s);
	
	int i = 100, j = 0;
	while (--i) {
		++j;
		std::cout << "\n" << i << "\n";
	}
	work = false;
	std::cout << "\n\n\n\n\n[needle]: " << j << "\n\n\n\n\n";
}

int main(int argc, char** argv) {
	{

		ChronoTimer c;

		std::thread needle(hardly_working);
		std::thread an(working_hard_for_a_dollar);
		std::thread thread(working_hard_not_getting_far);
		std::thread an1(working_hard_for_a_dollar);
		std::thread thread1(working_hard_not_getting_far);

		needle.join();
		an.join();
		thread.join();
		an1.join();
		thread1.join();



		std::cout << "\n\ndone working\n\n";
	}
	std::cout << "\n\n\n\n\n[an]: " << an << "\n\n\n\n\n";
	std::cout << "\n\n\n\n\n[thread]: " << th << "\n\n\n\n\n";

	std::cin.get();
	return 0;
}