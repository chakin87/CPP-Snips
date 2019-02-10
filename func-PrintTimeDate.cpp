#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>

#pragma warning(disable : 4996)

const char* GetMonthFromInt(int month);



void PrintTimeDate() {
	// Get current time
	auto nowTime = std::chrono::system_clock::now();

	// Convert to a time we can output
	std::time_t sleepTime =
		std::chrono::system_clock::to_time_t(nowTime);

	// Convert to current time zone
	tm myLocalTime = *localtime(&sleepTime);


	// Get separate pieces
	std::cout << "Month   : " <<
		GetMonthFromInt(myLocalTime.tm_mon) << "\n";
	std::cout << "Day     : " <<
		myLocalTime.tm_mday << "\n";
	std::cout << "Year    : " <<
		myLocalTime.tm_year + 1900 << "\n";
	std::cout << "Hours   : " <<
		myLocalTime.tm_hour << "\n";
	std::cout << "Minutes : " <<
		myLocalTime.tm_min << "\n";
	std::cout << "Seconds : " <<
		myLocalTime.tm_sec << "\n\n";

}

const char* GetMonthFromInt(int month) {
	switch (month) {
	case 1: return "January";
	case 2: return "February";
	case 3: return "March";
	case 4: return "April";
	case 5: return "May";
	case 6: return "June";
	case 7: return "July";
	case 8: return "August";
	case 9: return "September";
	case 10: return "October";
	case 11: return "November";
	case 12: return "December";
	}
}

int main(int argc, char** argv) {

	PrintTimeDate();


	getchar();
	return 0;
}
