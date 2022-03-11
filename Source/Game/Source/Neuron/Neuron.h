#pragma once

#include <vector>

class Net {
	typedef float TypeValue;

public:
	std::vector<std::vector<std::vector<TypeValue>>> netWeight;
	std::vector<std::vector<TypeValue>> netNeurons;

};

int Neuron();
