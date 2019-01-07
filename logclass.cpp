//        The itty-Bitty Logging class

#include "functions.h"
#include "ChronoTimer.h"


class Log {
public:
	enum LEVEL : char{
		LOG_LEVEL_TRACE, LOG_LEVEL_INFO, LOG_LEVEL_WARN, LOG_LEVEL_ERROR
	};
public: // Constructors/Destructos
	Log() = delete;
public: // Methods
	static void SetLevel(LEVEL level){
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
//	friend
public: // Members
	static LEVEL m_logLevel;

};
Log::LEVEL Log::m_logLevel;

int main(int argc, char** argv) {

	Log::Warn("This is a static test");
	


	Log::SetLevel(Log::LOG_LEVEL_ERROR);

	std::cin.get();
	return 0;
}