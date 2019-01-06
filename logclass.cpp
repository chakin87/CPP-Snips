//        The itty-Bitty Logging class

#include "functions.h"
#include "ChronoTimer.h"


class Log {
public:
	enum LEVEL {
		TRACE, INFO, WARN, ERROR
	};
public: // Constructors/Destructos

public: // Methods
	static void SetLevel(int level){
		m_logLevel = level;
	}
	static void Error(const char* message) {
		std::cout << "\n[ERROR]:{" << message << "}\n";
	}
	static void Warn(const char* message) {
		std::cout << "\n[WARN]:{" << message << "}\n";
	}
	static void Info(const char* message) {
		std::cout << "\n[INFO]:{" << message << "}\n";
	}
	static void Trace(const char* message) {
		std::cout << "\n[TRACE]:{" << message << "}\n";
	}
public: // Members
	static int m_logLevel;

};
int Log::m_logLevel;

int main(int argc, char** argv) {

	Log::Warn("This is a static test");

	Log::SetLevel(Log::ERROR);

	std::cin.get();
	return 0;
}