#include "Test/Test.h"
#include "Common/Console.h"
#include "Common/Help.h"

#if MAIN_FUNCTION == test

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

	mapFunction["load"] = [](const std::vector<std::string>& words) {
		Json::Value value;
		help::loadJson("test.txt", value);
		std::string jsonText = help::stringFroJson(value);

		if (jsonText.empty()) {
			std::cout << "jsonText: empty" << std::endl;
		}
		else {
			std::cout << "jsonText: ---" << std::endl;
			std::cout << jsonText << std::endl;
			std::cout << "-------------" << std::endl;
		}
	};

	runCommand(mapFunction);

	enterText("FINISH, ENTER to close.");
	return 0;
}

#endif
