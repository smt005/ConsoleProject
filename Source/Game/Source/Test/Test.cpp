#include "Test/Test.h"
#include <iostream>

int test() {
	std::cout << "START" << std::endl;
	std::cout << "Enter char:" << std::endl;
	char charVar;
	std::cin >> charVar;
	std::cout << "FINISH: " << charVar << std::endl;

	return 0;
}
