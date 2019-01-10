#include "functions.h"

#include <fstream>
#include <algorithm>
#include <future>
#include <functional> // std::function, needed to pass parametized lambdas to functions
#include <cstdlib>
#include <ctime>



void for_each_vec(const std::vector<std::string>& vec, void(*func)(const std::string&)) {
	for (std::string str : vec) {
		std::cout << "\n[Original]: " << str << "\n";
		func(str);
	//	std::cout << "\n[Lambdafied]: " << str << "\n";
	}
}

void for_each_vec(const std::vector<std::string>& vec, const std::function<void(std::string)>& func) {
	for (std::string str : vec) {
		std::cout << "\n[Original]: " << str << "\n";
		func(str);
		//std::cout << "\n[Lambdafied]: " << str << "\n";
	}
}

void for_each_vec(const std::vector<std::string>& vec, const std::function<std::string(std::string)>& func) {
	for (std::string str : vec) {
		std::cout << "\n[Original]: " << str << "\n";
		func(str);
		//std::cout << "\n[Lambdafied]: " << str << "\n";
	}
}

int main(int argc, char** argv) {
	srand(time(NULL));

	int x = 8;
	int k = 8;

	auto f = [&](int msg) {std::cout << msg << "\n"; };
	auto inc = [&](int n) {++n; };

	//    We create a lambda variable 'lam'. The [] is the capture box. 
	// It handles how the variables are captured. & for ref or = for value.
	// Or &x to only take x by ref. Mutable allows lambda to use vars by value
	// in the lambda function.
	auto lam = [=]() mutable{
		ChronoTimer c;
		while (x < 10)
		{
			LOG(++x);
		}
	};
	lam();

	//    The lambda_scrambla lambda takes in a name and returns a scrambled version of it.
	// This shows that lambdas are capable of encryption as well! (.01 bit encryption lolz)
	auto lambda_scrambla = [](const std::string& str) {
		std::string s = "", pool = str;
		while (s.size() < str.size()) {
			int index = rand() % pool.size();
			s += pool[index];
			pool.erase(pool.begin() + index);
		}
		return s;
	};

	std::cout << lambda_scrambla("Billy") << "\n";

	std::vector<std::string> v;
	v.reserve(25);

	//    Below I have created a rediculously long lambda that fills a vec with country names, from 
	// a text file, randomly. This is not why lambdas were made. Lambdas are intended to be used to
	// make light and nimble function on the fly. However, I thought I would show that the size of 
	// the function can be small or big. **NOTE: the mutable keyword in the lambda definition.**
	auto lambda_vecfill_countries = [&](std::vector<std::string>& vec, int size) mutable {
		std::string fbuffer = "", vbuf ="";
		std::ifstream fin("source/list-country-names.txt"); // There are 196 countries in file.
		if (fin.bad()) { std::cout << "Error opening file@!!"; return; }
		fbuffer.assign((std::istreambuf_iterator<char>(fin)),
			(std::istreambuf_iterator<char>()));
		fin.close();
		
		for (int i = 0, it = 0; i < size; ++i) {
			it = rand() % 196;
			for (auto ch : fbuffer) {
				if (ch == '\n') {
					--it; if (it < 0) { break; }
				}
				if (!it) {vbuf += ch;}
			}
			vbuf.erase(vbuf.begin());
			vec.emplace_back(vbuf);
			vbuf = "";
		}
	};

	//    We apply the lambda to the vec and fill it with 25 country names.
	lambda_vecfill_countries(v,25);
	//    Now we iterate throught the vector and cout the countries that were randomly picked!
	for (auto country : v) {
		std::cout << "\n[Name]: " << country << "\n[Encrypted]: " << lambda_scrambla(country) << "\n";
	}

	//    We pass a lambda to find_if which wil return an iterator that points to the index containing 'United States'.
	auto itr = std::find_if(v.begin(), v.end(), [](std::string country) {return country == "United States"; });
	if (itr != v.end()) {
		std::cout << "\nThe iterator was looking for 'United States'! Iterator found: " << *itr << "!\n";
	}
	else {
		std::cout << "\nThe iterator was looking for 'United States'! Iterator did not find it!\n";
	}

	std::cin.get();
	return 0;
}