//				Auto is like var in C# or Java, but wait there's more!
//    auto is great for getting those long nasty c/c++ return types that
// have like 4 different templates in the type. Or they can find iterator
// types as well which is what I really like them for as well. Auto should 
// not be abused. It can make code hard to read if used too heavily.
// NOTE: auto will not automatically return a ref so you will need 
// auto& in those situations.


#include <vector>
#include <unordered_map>
#include "functions.h"

class Item {
	std::string m_UPC;
public:
	std::string get_upc() { return m_UPC; }
	void set_upc(const std::string& upc) { m_UPC = upc; }
};

class ItemManager {
	std::unordered_map<std::string, std::vector<Item*>> m_items;
public:
	const std::unordered_map<std::string, std::vector<Item*>>& get_items() const {
		return m_items;
	}
};

//    auto will deduce the return type from what ever was passed into the function.
template<typename lT, typename rT>
auto add_concat(const lT& lhs, const rT& rhs) {
	return lhs + rhs;
}

int main(int argc, char** argv) {
	//    These are examples and are NOT good use cases.
	auto a = 24;
	auto b = "Chris";
	auto c = 3.1459f;
	auto d = 12312313231L;
	auto e = 'e';

	//    Lambdas are a great place to use auto and I see that a lot.
	auto f = [&](auto in) {in += 2; return in; };
	auto g = f(a);
	LOG(g); // Prints 26

	//    Heres another good use case;
	std::vector<std::string> v;
	v.reserve(5);
	v.emplace_back("Apple");
	v.emplace_back("Orange");
	v.emplace_back("Banana");
	v.emplace_back("Grape");
	v.emplace_back("Corn-Dog"); // :)

	//    To loop through the vector using the appropriate iterator
	// would look like this...
	for (std::vector<std::string>::iterator it = v.begin();
		it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	//    Below is the exact same as the above code...
	for (auto it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	//    Most of the time, now days, we use a rang based loop to do this.
	// It is more convenient, but it also utilizes the auto keyword for simplicity.
	for (auto items : v) {
		std::cout << items << " ";
	}

	//    Here is another good use-case example for auto.
	ItemManager m;
	const auto& items = m.get_items(); // Use ref so you don't make a copy
	//    Above using auto is the same as the below asignment.
	const std::unordered_map<std::string, std::vector<Item*>>& items1 = m.get_items();
	//    You could use 'typedef' or 'using' to help simplify this, but auto does
	// the same work, without code like below. NOTE
	using ItemMap = std::unordered_map<std::string, std::vector<Item*>>;

	ItemMap imap = m.get_items(); //		 Makes a copy or
	const ItemMap& imap1 = m.get_items(); // won't make copy.
	//    - or -
	typedef std::unordered_map<std::string, std::vector<Item*>> tdItemMap;

	const tdItemMap& tdiMap = m.get_items(); // Won't make a copy or
	tdItemMap tdiMap1 = m.get_items(); //		makes a copy.

	std::cin.get();
	return 0;
}