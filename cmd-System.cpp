//Testing Stage
int main(int argc, char** argv) {
	std::string pingAdr = "ping ";

	for (int i = 1; i < argc; ++i) {
		pingAdr = "ping ";
		pingAdr += argv[i];
		const char* pingAdrCh = pingAdr.c_str();
		system(pingAdrCh);

		///std::cout << argv[i] << std::endl;
		//std::cout << pingAdr + *argv[i] << std::endl;
		///std::cout << pingAdrCh << std::endl;

	}
