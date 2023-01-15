#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "BMPWriter.hpp"
#include "ComplexNumber.hpp"

class Mandelbrot
{
private:
	// Height & width of result image
	int height;
	int width;
	// Pixel components
	int **r;
	int **g;
	int **b;
public:
	// Ctor
	Mandelbrot(int height, int width);
	// Dtor
	virtual ~Mandelbrot();
	// Generate set and save to file
	bool generateToFile(const char *filename);
};

