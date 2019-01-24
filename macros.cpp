//				Macros
//    Macros are preprocesser definitions that we can use to replace code
// that might be really long. 
// **#defines SHOULD_BE_CAPS and use _ for spaces.**




#include "functions.h"

// A macro will replace the code inline and at compile time. They
// can be extremely useful, but they need to be used responsibly.

//    Macros can also be used to create a way to make sure certain 
// things only run in debug and not in release.
// So if this IS_DEBUG is set to 0, it will ignore any of the 
// #ifdef IS_DEBUG defines
#define IS_DEBUG 1


#if IS_DEBUG == 1
//    Macros can be defined anywhere, but I will define it here.
// Below is a simple example, but this WAIT macro is not really good
// practice. The LOG macro is a reasonable macro that you might see
// in a Log class.
#define WAIT std::cin.get()
#define LOG(x) std::cout << x << "\n"
#else
#define LOG(x)
#define WAIT
#endif // IS_DEBUG

//    You can set up #defines in MSVC to automatically define certain
// defines for debug or release automatically. Very useful for debugging.

//    Entire functions can be created with macros (use \ at end of line)
// The \ escapes the new line. *NOTE: Makes sure there isn't a space after \
// Else it will escape the space and no the new line.*
#define MACRO_FUNCTION(string) {\
	for (auto ch : string){\
		std::cout << ch << " ";\
	}\
} 


int main(int argc, char** argv) {

	MACRO_FUNCTION("This is a test");

	LOG("DEBUG IS CURRENTLY RUNNING!");
	WAIT;
	return 0;
}