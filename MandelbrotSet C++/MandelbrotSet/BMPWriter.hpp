#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define DWORD uint32_t
#define LONG int32_t
#define WORD uint16_t

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;


typedef struct tagBITMAPFILEHEADER {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

class BMPWriter {
public:
    
    static int WriteBMP (char *_filename, int **_red, int **_grn, int **_blu, int _height, int _width);
    static int **makeMatrix (int h, int w);
    static void deleteMatrix (int **m, int h, int w);
    
};
