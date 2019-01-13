//				Unions and all their glory! 
//    Unions are similar to structs and classes, but are limited to 1 value for all
// their variables. Unions are used anonomously and are good for type punning!
// A Union with two variables gives us 2 ways to access the same memory.


#include "functions.h"


struct Vec2 {
	float x, y;
};
struct Vec4{
	float x, y, z, w;
	//    Let's use type punning to print vec4 through the print_vec2 func.
	// One way to do that would be like this. We could then access the memory
	// and increment by 4 bytes to get the other int.
	Vec2& get2(int set_1_or_2) {  return set_1_or_2 == 1 ? *(Vec2*)&x : *(Vec2*)&z; }
	//    Or
};
struct Vec4u {
	//   OR we can use this setup
	union {
		struct {
			float x, y, z, w;
		};
		struct {
			Vec2 xy, zw;
		};
	};
};
struct Vec6 {
	float x, y, z, w, a, b;
};
//    
void print_vec2(const Vec2& v) {
	std::cout << "\n" << v.x << ", " << v.y << "\n";
}

int main(int argc, char** argv) {
	//    I will put the union in the struct so we can access the members.
	struct Union {
		union {
			float a;
			int b;
		};
	};
	Union a;
	//    Set the float a in the union to 2.0f. This will set int b to the byte 
	// representation of 2 as a float. It is as if we took the memory of float a
	// and used it for int b.
	a.a = 2.0f;
	std::cout << a.a << ", " << a.b << "\n";
	//

	//    Now lets look at the Vec4 printing in print_vec2()
	Vec4u v = { 10.f, 20.f, 30.f, 40.f };
	std::cout << "\n------START Printing Struct Union Struct vector------\n";
	print_vec2(v.xy);
	print_vec2(v.zw);
	v.x += v.z;
	std::cout << "\n------Printing modified vector------\n";
	print_vec2(v.xy);
	print_vec2(v.zw);
	std::cout << "\n------END Printing Struct Union Struct vector------\n";

	std::cin.get();
	return 0;
}