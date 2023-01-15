#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <iostream>

#include "ComplexNumber.hpp"
#include "Mandelbrot.h"


int main(int argc, char **argv) {
	if (argc != 4) {
		printf("usage: %s <height> <width> <outfilename>\n", argv[0]);
		return 0;
	}
	int height = atoi(argv[1]);
	int width = atoi(argv[2]);


	Mandelbrot julia(height, width);


	std::cout << "Generation: " << (julia.generateToFile(argv[3]) ? " Success." : "Failure") << std::endl;

	return 0;
}