//				STD::VECTOR

//    The array that resizes!
// NOTES:
// 1) Vectors should always try to be passed by ref. Copying a vector can
//    be taxing!
// 2) If pushing to a vector and the item being pushed is will not fit in the existing
//    vector, a new and larger vector will be created and then said vector will COPY
//    the other vecs values. This can cause a performance drop.
// 3) Vectors can be great and fast if the above 'resizing' is not done.
// 4)
// 5)


//    This is needed for vector. std::vector has an inappropriate name.
// It is not a mathmatical vector, but more of a dynamic array. It is 
// similar to a set that doesn't enforce any type of uniqueness. 
#include <vector>

#include "functions.h"

struct Vector3i {
	int x, y, z;
	Vector3i(int x, int y, int z)
		:x(x), y(y), z(z) {}
	//    We will go ahead and declare a default copy constructor.
	// This will tell us everytime the vector is copied and it will help
	// demonstrate how and when Vectors resize.
	Vector3i(const Vector3i& vec)
		:x(vec.x), y(vec.y), z(vec.z){
		std::cout << "\nCopied!\n";
	}
	const int& operator[](unsigned int index) {
		return index == 0 ? x : index == 1 ? y : index == 2 ? z : 0;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector3i& vec3i) {
		stream << vec3i.x << ", " << vec3i.y << ", " << vec3i.z;
		return stream;
	}
};

int main(int argc, char** argv) {

	//    There are mulitple factors on whether or not to use stack objs
	// or ptrs in a std::vector. It depends on the type, amount of resizes.
	std::vector<Vector3i> vecs;

	//    In this scenario we see that 6 vector copies happen. This is because
	// The vector3i are created in the main function and then must be copied in
	// to the vector. Thats 3 copies, but then the vector resizes 2 times. This
	// causes the Vector3i that are in the vector to be recopied into each resized
	// vector. This is too much over-head and we really haven't done much yet!
	vecs.push_back(Vector3i(1, 2, 3));
	vecs.push_back(Vector3i(4, 5, 6));
	vecs.push_back(Vector3i(7, 8, 9));


	//    So, 6 copies can be reduced to 3 copies by instanciating the vector and
	// then call .reserve(3). This will make sure the vector has enough room for at
	// least 3 of the objects/types.
	std::vector<Vector3i> vecs1;
	vecs1.reserve(3);

	vecs1.push_back(Vector3i(1, 2, 3));
	vecs1.push_back(Vector3i(4, 5, 6));
	vecs1.push_back(Vector3i(7, 8, 9));
	//    So after this we have 3 copies. The vector3i are created in main() and then copied 
	// into the vector when they are pushed. This is much better, BUT we can imporve this!
	// So, instead on pushing these copies into a vector, we need to instanciate the vector3i 
	// inside the vector itself. To do this we use the .emplace(Vector3i(7, 8, 9)). This will
	// do just that and as you can see, there are no copies made from the code below.
	std::vector<Vector3i> vecs2;
	vecs2.reserve(3);
	std::cout << "Begin of emplace().\n";
	vecs2.emplace_back(1, 2, 3);
	vecs2.emplace_back(4, 5, 6);
	vecs2.emplace_back(7, 8, 9);

	std::cout << "End of emplace().\n";

	//    Different ways to loop through vecs.
	for (unsigned int i = 0; i < vecs.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << vecs[i][j];
		}
	}
	for (auto v : vecs) {
		std::cout << "\n" << v << "\n";
	}

	//    To erase an index in vector, you must feed it an iterator
	// to the position you want to erase. Below erases index 1.
	vecs.erase(vecs.begin() + 1);


	std::cin.get();
	return 0;
}
/*#include "functions.h"



int main(int argc, char** argv) {



	std::cin.get();

	return 0;
}*/