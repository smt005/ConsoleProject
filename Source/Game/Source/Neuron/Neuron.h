#pragma once

#include "main/Config.h"
#if MAIN_FUNCTION == credit

#include <vector>

class Net {
	typedef float TypeValue;

public:
	std::vector<std::vector<std::vector<TypeValue>>> netWeight;
	std::vector<std::vector<TypeValue>> netNeurons;

};

int Neuron();

#endif
