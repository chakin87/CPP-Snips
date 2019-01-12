//				STL CONTAINER - STD::LIST


//				STL Containor std::list();
//    Lists are similar to std::vector, but std::list does not allow
// random access. Std::list must be iterated.
// Most things you can do with a std::vector, you can do with a 
// std::list.
// 
//    Lists are fast and lean at the expense of some funcitonality.
// So, if you can afford to use them, do so!
// 
//
//    Check http://www.cplusplus.com/reference/list/list/insert/
// for iterator and insert help. 


#include "functions.h"

//    Include list to use the lists.
#include <list>
#include <cstdlib>
#include <ctime>
#include <iterator>


int main(int argc, char** argv) {
	//    Seed rand() with the current time as a seed.
	srand(time(NULL));
	//    Let's instanciate an integer list.
	std::list<int> a;
	//    Let's go ahead and populate the list with random numbers.
	// Then, we create a lambda to print out the lists.
	auto b = [&](std::list<int>& l, const int n = 100) {
		for (size_t i = 0; i < n; ++i)
			l.push_back(rand() % 101);
		l("Finished Populating the list!\n");
	};
	auto c = [&](const std::list<int>& l) {		
		for (auto item : l) {LIST(item);}};
	auto printlist = c;
	b(a);
	c(a);
	//    To insert into or erase in a list you need an iterator that points
	// at the position you want to insert to or erase.
	std::list<int>::iterator itr = a.begin();
	//    Inserting into the 5th element
	std::cout << "\n*itr: " << *itr << "\n";

	LOG("inserting 555 in pos 0 of list\n\n");
	a.insert(itr, 555);
	//    itr is it 'index' 1 now that we inserted 555 at pos
	// 0. The insert puts the int before the iterator and the
	// iterater stays at the number that it was pointing to,
	// so that is why itr is pointing at index 1 (so to say)
	LOG("inserting 555 in pos 2 of list\n\n");
	a.insert(++itr, 555);
	printlist(a);
	//    Now, we can remove ALL of the 555s with one command.
	a.remove(555);
	LOG("\nRemoving 555s"); // Love those 555 timers.
	printlist(a);
	//    We can erase any number between 25 and 75, since our
	// list is sorted! NOTE: We can't use std::sort because std:
	// :sort requires iterators to be random access.
	a.insert(++itr, 75);
	a.insert(++itr, 25);
	a.sort([](int a, int b) {return a < b; });
	LOG("\n a sorted <\n");
	printlist(a);

	auto itr1 = a.begin();
	auto itr2 = a.begin();
	//    A pretty quick way to set an iterator in this scenario.
	while ((*(++itr1) != 25) && (itr1 != a.end()));
	while ((*(++itr2) != 75) && (itr2 != a.end()));
	//std::cout << "\n" << std::boolalpha << (itr1 == a.end()) << (itr2 == a.end()) << "\n";
	if (itr1 != a.end() && itr2 != a.end()) {
		LOG("TRACER *itr1: " << *itr1);
		LOG("TRACER *itr2: " << *itr2);
		printlist(a);
		itr2 = a.erase(itr1, itr2);
		if (itr2 != a.end())
		LOG("TRACER");
	}
	//    Let's see if it works..It does!
	printlist(a);






	std::cin.get();
	return 0;
}