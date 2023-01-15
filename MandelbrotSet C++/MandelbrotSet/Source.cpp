//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <iostream>
//
//#include "ComplexNumber.hpp"
//#include "Mandelbrot.h"
//
////#include "BMPWriter.hpp"
////#include "ComplexNumber.hpp"
////
////typedef struct RgbColor
////{
////	unsigned char r;
////	unsigned char g;
////	unsigned char b;
////} RgbColor;
////
////typedef struct HsvColor
////{
////	unsigned char h;
////	unsigned char s;
////	unsigned char v;
////} HsvColor;
////
////RgbColor HsvToRgb(HsvColor hsv)
////{
////	RgbColor rgb;
////	unsigned char region, remainder, p, q, t;
////
////	if (hsv.s == 0)
////	{
////		rgb.r = hsv.v;
////		rgb.g = hsv.v;
////		rgb.b = hsv.v;
////		return rgb;
////	}
////
////	region = hsv.h / 43;
////	remainder = (hsv.h - (region * 43)) * 6;
////
////	p = (hsv.v * (255 - hsv.s)) >> 8;
////	q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
////	t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;
////
////	switch (region)
////	{
////	case 0:
////		rgb.r = hsv.v; rgb.g = t; rgb.b = p;
////		break;
////	case 1:
////		rgb.r = q; rgb.g = hsv.v; rgb.b = p;
////		break;
////	case 2:
////		rgb.r = p; rgb.g = hsv.v; rgb.b = t;
////		break;
////	case 3:
////		rgb.r = p; rgb.g = q; rgb.b = hsv.v;
////		break;
////	case 4:
////		rgb.r = t; rgb.g = p; rgb.b = hsv.v;
////		break;
////	default:
////		rgb.r = hsv.v; rgb.g = p; rgb.b = q;
////		break;
////	}
////
////	return rgb;
////}
////
////HsvColor RgbToHsv(RgbColor rgb)
////{
////	HsvColor hsv;
////	unsigned char rgbMin, rgbMax;
////
////	rgbMin = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
////	rgbMax = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);
////
////	hsv.v = rgbMax;
////	if (hsv.v == 0)
////	{
////		hsv.h = 0;
////		hsv.s = 0;
////		return hsv;
////	}
////
////	hsv.s = 255 * long(rgbMax - rgbMin) / hsv.v;
////	if (hsv.s == 0)
////	{
////		hsv.h = 0;
////		return hsv;
////	}
////
////	if (rgbMax == rgb.r)
////		hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
////	else if (rgbMax == rgb.g)
////		hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
////	else
////		hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);
////
////	return hsv;
////}
////
////
////
////ComplexNumber mapCoordsToComplex(int y, int x, int height, int width, ComplexNumber rangeMin, ComplexNumber rangeMax) {
////	ComplexNumber range
////	(
////		rangeMax.getR() - rangeMin.getR(),
////		rangeMax.getI() - rangeMin.getI()
////	);
////
////	return ComplexNumber
////	(
////		x * (range.getR() / width) + rangeMin.getR(),
////		y * (range.getI() / height) + rangeMin.getI()
////	);
////}
////
////double mapToReal(int x, int width, double minR, double maxR) {
////	double range = maxR - minR;
////
////	return x * (range / width) + minR;
////}
////
////double mapToImaginary(int y, int height, double minI, double maxI) {
////	double range = maxI - minI;
////
////	return y * (range / height) + minI;
////}
////
////int mandelbrot(double cr, double ci, int maxIteration) {
////	int n = 0;
////	double zr = 0, zi = 0;
////	//ci = 0.3, cr = -0.1;
////	while (n < maxIteration && zr * zr + zi * zi < 4.0)
////	{
////		double temp = zr * zr - zi * zi + cr;
////		zi = 2.0 * zr * zi + ci;
////		zr = temp;
////		++n;
////	}
////	return n;
////}
////
////int applyMandelbrot(ComplexNumber z, ComplexNumber c) {
////	int n = 255;
////	while (n >= 5 && z.mag() < 2) {
////		z = z.mult(z).add(c);
////		n -= 5;
////	}
////	return n;
////
////}
//
//int main(int argc, char **argv) {
//	if (argc != 6) {
//		printf("usage: %s <height> <width> <Complex C real> <Complex C imaginary> <outfilename>\n", argv[0]);
//		return 0;
//	}
//	int height = atoi(argv[1]);
//	int width = atoi(argv[2]);
//	
//
//	Mandelbrot julia(height, width);
//	
//	julia.setC
//	(
//		ComplexNumber
//		(
//			atof(argv[3]), atof(argv[4])
//		)
//	);
//	  
//
//	std::cout << "Generation: " << (julia.generateToFile(argv[5]) ? " Success." : "Failure") << std::endl;
//		
//	return 0;
//}