// TODO: move into unit tests

#include "basegenerator.h"

#include <iostream>

int main() {
	BaseGenerator bg;

	std::cout << bg.stringify(1.5) << std::endl;
	std::cout << bg.stringify(5) << std::endl;
	std::cout << bg.stringify('c') << std::endl;

	return 0;
}
