//				Multidimensional Arrays!
//    2d, 3d, 4d, etc!

//




#include "functions.h"



int main(int argc, char** argv) {

	//    This is the best way to do mutidimensional arrays. (The best that I know of) We will make a 
	// 50x50 array.
	int* d2_array = new int[50 * 50];
	//    Use is below and this sets all ints in array to 5;
	for (int i = 0; i < 50*50; ++i){
		d2_array[i] = 5;
	}
	//    Sometimes it is useful to see things multidimensionally (2d in this case). So, we can do 
	// things like this to simulate such behavior. **Using this artifical 2d array is soo much faster**
	for (int y = 0; y < 50; ++y) {
		for (int x = 0; x < 50; ++x) {
			d2_array[x + y * 50];/*50=width*/
		}
	}






	//    Below are demos on actual multidimensional arrays. I don't suggest using them because you
	// memory may not be allocated next to each other(most likely won't be next to each other) So,
	// everytime you jump to the next dimension of your array, you will have to jump to a different 
	// section of memory. This will lead to cache misses! No good. A big part of writing optimized code
	// is preventing cache misses by keeping memory that should be together together.

	//    We will start with a Heap allocated array. For a 2d array, we need a pointer
	// to a pointer of array type.

	int* array1d = new int[50];   // 200 bytes. Single dimensional array.
	//    To delete 
	delete[] array1d;

	
	int** array2d = new int*[50]; // 200 bytes. Two dimensional array.
	//    For the 2d array, we need to set our pointers to point to int array.
	for (int i = 0; i < 50; ++i) {
		array2d[i] = new int[50];
	}
	//    To delete
	for (int i = 0; i < 50; ++i){
		delete[] array2d[i];
	}delete[] array2d;



	int*** array3d = new int**[50]; // Three dimensional array.
	//    For the 3d array, we need to set our pointers to point to int array.(x2)
	for (int i = 0; i < 50; ++i) {
		array3d[i] = new int*[50];
		for (int j = 0; j < 50; ++j) {
			array3d[i][j] = new int[50];
		}
	}
	//    To delete******************************************************
	//for (int i = 0; i < 50; ++i) {
	//	delete[] array3d[i];
//	}delete[] array2d;


	std::cin.get();
	return 0;
}