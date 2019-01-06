
#include <iostream>
#include <algorithm>
#include <future>
#include <cstdio>

#include "ChronoTimer.h"
#include "functions.h"





int main(int argc, char** argv) {

	//    std::async takes the std::launch::asyc to tell async to start the function
	// immediately, otherwise it may defer the launch. The next param is the function to
	// call. Then we enter the called functions' parameter.
	//    Below we call this function 4 times 'asynchronously' and we time it.
	{
		ChronoTimer c;
		auto futr1 = std::async(std::launch::async, make_random_set_int, (1000000));
		auto futr2 = std::async(std::launch::async, make_random_set_int, (1000000));
		auto futr3 = std::async(std::launch::async, make_random_set_int, (1000000));
		auto futr4 = std::async(std::launch::async, make_random_set_int, (1000000));
		//std::cout << futr1.get().size() << " " << futr2.get().size();
	}
	//    Below we call and time the same function 4 times in a single thread.
	{
		ChronoTimer c;
		auto a = make_random_set_int(1000000);
		auto b = make_random_set_int(1000000);
		auto e = make_random_set_int(1000000);
		auto d = make_random_set_int(1000000);
		//std::cout << a.size() << " " << b.size();
	}
	//   The results of the above average around 2x-3x faster using futures and asynch.
	// Initially, I assumed the results would be closer to 4x faster, but I will explain
	// why this is not the case below. Results very from debug to release versions as well. 
	//    I am runnning an i7 8700k 6 core w/ hyper-threading; stock everything.
	//        3.7 GHz that turbos to 4.7 GHz stock. 
	//    During the 4 async tasks, it reports only 33-38% of all processors are at use.
	// If I am using 4 of 12 threads ( 4/12 == 33%), then 33% use means that I am using 
	// the hyper-threading rather than the true physical cores. This means that the spead
	// could be increased if 4 of 6 true cores were being utilized over the hyper-threads.
	// This could lead closer to the 4x speeds that I assumed we would get. If I ran more
	// concurrent async tasks, I imagine the results would be even better.
	


	std::cin.get();
	return 0;
}