//				std::arrays, the static array!




#include "functions.h"
#include <array> // must include <array>

void PrintArray(int array[]) {
	for (int i = 0; i <= sizeof(array) / sizeof(int); i++) {
		std::cout << array[i] << std::endl;
	}
}

template<int SZ>
void PrintArray(const std::array<int, SZ>& data) {
	for (int i = 0; i < data.size(); ++i) {
		std::cout << data[i] << "\n";
	}
}

int main(int argc, char** argv) {
	//    Once it is initialized, you use it just like a normal array!
	std::array<int, 5> a;
	a[0] = 5;
	a[1] = 4;
	a[2] = 3;
	a[3] = 2;
	a[4] = 1;
	a.at(2) = 30;

	//    Direct access data.
	int* ip1 = a.data();
	int* index = &(*a.data());
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << "element " << i << " is " << *ip1++ << std::endl;
		std::cout << "index[" << i << "] is " << index[i] << std::endl;
	}

	std::cin.get();
	return 0;
}