#include "Test/Test.h"
#include "Common/Console.h"

int test() {
	using namespace engine;
	std::cout << "START" << std::endl;

	std::map<std::string, CommanFunction> mapFunction;

	mapFunction["run"] = [](const std::vector<std::string>& words) {
		if (words.size() == 1) {
			line();
		}
		else if (words.size() == 2) {
			std::string str = words[1];
			line(20, str[0]);
		}
	};

	mapFunction["run2"] = [](const std::vector<std::string>& words) {
		line(10, '+');
	};

	runCommand(mapFunction);

	enterText("FINISH, ENTER to close.");
	return 0;
}
