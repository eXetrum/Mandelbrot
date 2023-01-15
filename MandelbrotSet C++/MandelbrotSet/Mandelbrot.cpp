#include "Mandelbrot.h"



Mandelbrot::Mandelbrot(int height, int width)
	: height(height), width(width) {

	r = BMPWriter::makeMatrix(height, width);
	g = BMPWriter::makeMatrix(height, width);
	b = BMPWriter::makeMatrix(height, width);
}


Mandelbrot::~Mandelbrot()
{
	BMPWriter::deleteMatrix(r, height, width);
	BMPWriter::deleteMatrix(g, height, width);
	BMPWriter::deleteMatrix(b, height, width);
}

bool Mandelbrot::generateToFile(const char *filename)
{
	// Min/max range on complex plane
	ComplexNumber rangeMin(-2.0, -2.0);
	ComplexNumber rangeMax(2.0, 2.0);
	// Incremental values for Real, Imaginary parts
	double dr = (rangeMax.getR() - rangeMin.getR()) / width;
	double di = -(rangeMax.getI() - rangeMin.getI()) / height;
	// Loop over image pixels
	for (int y = 0; y < height; ++y) {

		for (int x = 0; x < width; ++x) {
			ComplexNumber c
			(
				x * dr + rangeMin.getR(),
				y * di + rangeMax.getI()
			);
			ComplexNumber z(0, 0);
			// Mandelbrot set calculation
			int n = 255;
			while (n >= 5 && z.mag() < 2) {
				z = z.mult(z).add(c);
				n -= 5;
			}
			// Set output pixel value
			r[y][x] = n;
			g[y][x] = n;
			b[y][x] = n;
		}
	}
	return BMPWriter::WriteBMP(const_cast<char*>(filename), r, g, b, height, width);
}
