




#include <iostream>
template<int I>
struct Fibonacci
{
	//typedef Fibonacci F;
	static const int fValue = Fibonacci<I - 1>::fValue + Fibonacci<I - 2>::fValue;
};
template<>
struct Fibonacci<0>
{
	static const int fValue = 0;
};
template<>
struct Fibonacci<1>
{
	static const int fValue = 1;
};

template<size_t ... SZT>
const int fibGit(std::integer_sequence<SZT..>, const int index) {
	constexpr std::array<int, sizeof...(SZT)> fibarray = { Fibonacci<SZT>::fValue... };
	return fibarray[index];
}


const int fibIndex(const int index) {
	return fibGit(std::make_index_sequence<47>, index);
}

int main(int argc, char** argv) {


	std::cout << Fibonacci<47>::fValue << "\n";

	getchar();

	return 0;
}