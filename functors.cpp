//				FUNCTORS
//
//    A functor is a class with an operator overload of ()
//
//
//
//
//
#include <iostream>
#include <functional>
#include <algorithm>
#include "functions.h"
//
// 
//-----------------------------------------------------------------------------//
//------------------------Some Functions Used in File--------------------------//
//-----------------------------------------------------------------------------//
//
//    A functor class for getting a product of 2 numbers.
template <typename T>
class productOf {
	T m_val = 0;
	productOf();
public:
	productOf(T n) : m_val(n) {}
	void set(T n) { m_val = n; }
	T get() const { return m_val; }
	T operator() (T n) const { return m_val * n; }
};
//    print functions
template<typename T>
void print(const T& msg) {
	std::cout << msg << std::endl;
}
template<typename a1, typename a2>
void print(const a1& arg_one, const a2& arg_two) {
	std::cout << arg_one << arg_two << std::endl;
}
template <typename T>
void print(const std::vector<T>& v) {
	if (!v.size()) return;
	std::cout << "Printing std::vector.\n";
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T>& v, const char* vec_name) {
	if (!v.size()) return;
	std::cout << "Printing std::vector " << vec_name << ".\n";
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T>& v, const char* vec_name, const char* vec_type) {
	if (!v.size()) return;
	std::cout << "Printing std::vector<" << vec_type << "> " << vec_name << ".\n";
	for (T e : v) { std::cout << e << " "; }
	std::cout << std::endl;
}
template <typename T>
void print(const std::vector<T>& v, const char* vec_name, const char* vec_type, bool is_relational) {
	if (!v.size()) return;
	std::cout << "Printing std::vector<" << vec_type << "> " << vec_name << ".\n";
	if (typeid(T) == typeid(bool)) {
		for (bool e : v) { std::cout << (e ? "T" : "F") << " "; }
	}else {
		for (T e : v) { std::cout << e << " "; }
	}
	std::cout << std::endl;
}


int main() {
// 
//-----------------------------------------------------------------------------//
//--------------------------Smallftor Demonstration----------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Small Functor Demos");
	print_sub_section("productOf<int> Functor");
	productOf<int> x(9);
	print("x.get is ", x.get());
	print("x(5) is ", x(5));
	print( "x(25) is ", x(25));
	x.set(7);
	print("x.get() is ", x.get());
	print("x(5) is " ,x(5));
	print("x(25) is ", x(25));
//-----------------------productOf<float>---------------------
	print_sub_section("productOf<float>");
	productOf<float> fx(3.33);
	print("fx.get is ", fx.get());
	print("fx(5) is ", fx(5));
	print("fx(25) is ", fx(25));
	fx.set(7.77);
	print("fx.get() is ", fx.get());
	print("fx(5) is ", fx(5));
	print("fx(25) is ", fx(25));
//-----------------------productOf end------------------------
// 
//-----------------------------------------------------------------------------//
//--------------------------Arithemetic Functors-------------------------------//
//-----------------------------------------------------------------------------//
//
	print_new_section("Arithemetic Functors");
	print_sub_section("std::plus<long>");
	std::vector<long> v1_a = { 26, 52, 79, 114, 183 };
	std::vector<long> v2_a = { 1, 2, 3, 4 ,5 };
	std::vector<long> v3_a(v1_a.size(), 0);
	print(v1_a, "v1_a", "long");
	print(v2_a, "v2_a", "long");
	print(v3_a, "v3_a", "long");
	std::cout << std::endl;

	std::plus<long> f;
	std::transform(v1_a.begin(), v1_a.end(), v2_a.begin(), v3_a.begin(), f);
	print(v3_a, "v3_a 'after transform using std::plus<long>'", "long");

//----------------------------std::minus functor------------------------
	print_sub_section("std::minus");
	std::vector<long> v1_b = { 26, 52, 79, 114, 183 };
	std::vector<long> v2_b = { 1, 2, 3, 4 ,5 };
	std::vector<long> v3_b(v1_b.size(), 0);
	print(v1_b, "v1_b", "long");
	print(v2_b, "v2_b", "long");
	print(v3_b, "v3_b", "long");
	std::cout << std::endl;

	std::minus<long> fminus;
	std::transform(v1_b.begin(), v1_b.end(), v2_b.begin(), v3_b.begin(), fminus);
	print(v3_b, "v3_b 'after transform using std::minus<long>'", "long");

//----------------------------std::mulitplies functor------------------------
	print_sub_section("std::mulitplies");
	std::vector<long> v1_c = { 26, 52, 79, 114, 183 };
	std::vector<long> v2_c = { 1, 2, 3, 4 ,5 };
	std::vector<long> v3_c(v1_b.size(), 0);
	print(v1_c, "v1_c", "long");
	print(v2_c, "v2_c", "long");
	print(v3_c, "v3_c", "long");
	std::cout << std::endl;

	std::multiplies<long> fmultiplies;
	std::transform(v1_c.begin(), v1_c.end(), v2_c.begin(), v3_c.begin(), fmultiplies);
	print(v3_c, "v3_c 'after transform using std::multiplies<long>'", "long");


//----------------------------std::divides functor------------------------
	print_sub_section("std::divides");
	std::vector<long> v1_d = { 26, 52, 79, 114, 183 };
	std::vector<long> v2_d = { 1, 2, 3, 4 ,5 };
	std::vector<long> v3_d(v1_b.size(), 0);
	print(v1_d, "v1_d", "long");
	print(v2_d, "v2_d", "long");
	print(v3_d, "v3_d", "long");
	std::cout << std::endl;

	std::divides<long> fdivides;
	std::transform(v1_d.begin(), v1_d.end(), v2_d.begin(), v3_d.begin(), fdivides);
	print(v3_d, "v3_d 'after transform using std::divides<long>'", "long");

//----------------------------std::modulus functor------------------------
	print_sub_section("std::modulus");
	std::vector<long> v1_e = { 26, 52, 79, 114, 183 };
	std::vector<long> v2_e = { 1, 2, 3, 4 ,5 };
	std::vector<long> v3_e(v1_b.size(), 0);
	print(v1_d, "v1_e", "long");
	print(v2_d, "v2_e", "long");
	print(v3_d, "v3_e", "long");
	std::cout << std::endl;

	std::modulus<long> fmodulus;
	std::transform(v1_e.begin(), v1_e.end(), v2_e.begin(), v3_e.begin(), fmodulus);
	print(v3_d, "v3_e 'after transform using std::modulus<long>'", "long");

	//----------------------------std::negate functor------------------------
	//    Makes all ints in vec negated.

// 
//-----------------------------------------------------------------------------//
//--------------------------Relational  Functors-------------------------------//
//-----------------------------------------------------------------------------//
//

	print_sub_section("END ARITHEMETIC FTORS");
	print_new_section("Relationiol Functors");
	print_sub_section("using transform");

	std::vector<long> v1_f = { 26, 52, 79, 114, 183 };
	std::vector<long> v2_f = { 52, 2, 72, 114 ,5 };
	std::vector<bool> v3_f(v1_e.size());
	print(v1_f);
	print(v2_f);
	std::cout << std::endl;

	//    ***Try anyone of these functors! Just uncomment the one you want. Only one can be uncommented at a time.
	std::greater<long> frelational; const char* ftype = "v3_f'after transform using std::greater";
	//std::less<long> frelational; const char* ftype = "v3_f'after transform using std::less";
	//std::greater_equal<long> frelational; const char* ftype = "v3_f'after transform using std::greater_equal";
	//std::less_equal<long> frelational; const char* ftype = "v3_f'after transform using std::less_equal";
	//std::equal_to<long> frelational; const char* ftype = "v3_f'after transform using std::equal_to";
	//std::not_equal_to<long> frelational; const char* ftype = "v3_f'after transform using std::not_equal_to";

	std::transform(v1_f.begin(), v1_f.end(), v2_f.begin(), v3_f.begin(), frelational);
	using namespace std::string_literals;
	print(v3_f, ftype, "bool", true);		
	print_note_sections("These relational functors can be used"
	" in all sorts of algorithsms!"
	" Below shows how they work with std::sort!");

//--------------------------------------------Relational Functors std::sort------------------
	print_sub_section("using sort");

	print(v1_f);
	print(v2_f);
	std::cout << std::endl;

	//    ***Try anyone of these functors! Just uncomment the one you want. Only one can be uncommented at a time.
	std::greater<long>		   frelational1;	const char* ftype1 = "v2_f sort std::greater";
	//std::less<long>		   frelational1;	const char* ftype1 = "v2_f sort std::less";
	//std::greater_equal<long> frelational1;    const char* ftype1 = "v2_f sort std::greater_equal";
	//std::less_equal<long>	   frelational1;	const char* ftype1 = "v2_f sort std::less_equal";
	//std::equal_to<long>      frelational1;	const char* ftype1 = "v2_f sort std::equal_to";
	//std::not_equal_to<long>  frelational1;    const char* ftype1 = "v2_f sort std::not_equal_to";

	std::sort(v2_f.begin(), v2_f.end(), frelational);
	using namespace std::string_literals;
	print(v2_f, ftype, "bool", true);


// 
//-----------------------------------------------------------------------------//
//--------------------------Logical  Functors----------------------------------//
//-----------------------------------------------------------------------------//
//

	print_new_section("Logical Functors");
	print_note_section("The logical operators are the and/or operators.");
	std::vector<int> v1_g = { 1, 0, 1, 0, 1, 0, 1, 0 };
	std::vector<int> v2_g = { 1, 1, 1, 1, 0, 0, 0, 0 };
	std::vector<int> v3_g(v1_g.size(), 0);
	print(v1_g, "v1_g", "int");
	print(v2_g, "v2_g", "int");
	std::cout << std::endl;

	std::logical_and<int> flogic;
	std::transform(v1_g.begin(), v1_g.end(), v2_g.begin(), v3_g.begin(), flogic);
	print_note_section("We are using the binary std::transform(5 parameters)");
	print_note_section("v3_f holds the values from the *logical_and<int>* comparisons of v1_g and v2_g");
	print(v3_g, "v3_g", "int");
	
	std::logical_or<int> flogicor;
	std::transform(v1_g.begin(), v1_g.end(), v2_g.begin(), v3_g.begin(), flogicor);
	print_note_section("v3_f holds the values from the *logical_or<int>* comparisons of v1_g and v2_g");
	print(v3_g, "v3_g", "int");

	//------------------------------------Bool--------------------------------------------------------------
	
	print_new_section("Logical Bool Functors");
	print_note_section("We can also perform the same transforms with std::vector<bool>");

	std::vector<bool> v1_gb= { 1, 0, 1, 0, 1, 0, 1, 0 };
	std::vector<bool> v2_gb = { 1, 1, 1, 1, 0, 0, 0, 0 };
	std::vector<bool> v3_gb(v1_gb.size(), 0);
	print(v1_gb, "v1_gb", "bool", true);
	print(v2_gb, "v2_gb", "bool", true);
	std::cout << std::endl;

	std::logical_and<bool> flogicb;
//	std::logical_or<bool> flogicb;
//	std::logical_not<bool> flogicb; // Returns opposite. if 1 then 0..

	std::transform(v1_gb.begin(), v1_gb.end(), v2_gb.begin(), v3_gb.begin(), flogicb);
	print(v3_gb, "v3_gb", "bool", true);

	print_note_sections("So, as you can see the logical operator functors work just the"
		"same as always. There are a  lot of aplications for these functors. Using the"
		"logical functors in conjuction with other objects and functors can be even more"
		"beneficial!");


// 
//-----------------------------------------------------------------------------//
//--------------------------Logical  Functors----------------------------------//
//-----------------------------------------------------------------------------//
//


	WAIT;
	return 0;
}
