
#include "main/Execution.h"
#include <iostream>

void Execution::run() {
	std::cout << "START" << std::endl;
	std::cout << "Enter char:" << std::endl;

	char charVar;
	std::cin >> charVar;

	std::cout << "FINISH: " << charVar << std::endl;
}
