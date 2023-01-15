#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "BMPWriter.hpp"

int **BMPWriter::makeMatrix (int h, int w)
{
    int **matrix;
    matrix = new int *[h];
    int i;
    for (i = 0; i < h; ++i) {
        matrix[i] = new int[w];
    }
    return matrix;
}

void BMPWriter::deleteMatrix (int **m, int h, int w)
{
    for (int i = 0; i < h; ++i) {
        delete [] m[i];
    }
    delete [] m;
}



int BMPWriter::WriteBMP (char *_filename, int **_red, int **_grn, int **_blu, int _height, int _width)
{
    FILE *fptr;
    fptr = fopen(_filename, "wb");
    if (fptr == NULL) return 0;
    
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    WORD word;
    
    // -- bmp file rows are padded to multiples of 4 bytes
    int pad = (((_width * 3) % 4) == 0) ? 0 : 4 - ((_width * 3) % 4);
    
    bih.biSize = sizeof(BITMAPINFOHEADER);
    bih.biWidth = _width;
    bih.biHeight = _height;
    bih.biPlanes = 1;
    bih.biBitCount = 24;
    bih.biCompression = 0;
    bih.biSizeImage = (_width + pad) * 3 * _height;
    bih.biXPelsPerMeter = 2834;
    bih.biYPelsPerMeter = 2834;
    bih.biClrUsed = 0;
    bih.biClrImportant = 0;
    int x = sizeof(BITMAPFILEHEADER);
    int y = sizeof(BITMAPINFOHEADER);
    
    bfh.bfType = 19778;
    bfh.bfSize = bih.biSizeImage + 14 + 40;//sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bfh.bfReserved1 = 0;
    bfh.bfReserved2 = 0;
    bfh.bfOffBits = 14 + 40;//sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // -- write bitmap file and info headers
    fwrite(&bfh.bfType, sizeof(WORD), 1, fptr);
    fwrite(&bfh.bfSize, sizeof(DWORD), 1, fptr);
    fwrite(&bfh.bfReserved1, sizeof(WORD), 1, fptr);
    fwrite(&bfh.bfReserved2, sizeof(WORD), 1, fptr);
    fwrite(&bfh.bfOffBits, sizeof(DWORD), 1, fptr);
    
    fwrite(&bih.biSize, sizeof(DWORD), 1, fptr);
    fwrite(&bih.biWidth, sizeof(LONG), 1, fptr);
    fwrite(&bih.biHeight, sizeof(LONG), 1, fptr);
    fwrite(&bih.biPlanes, sizeof(WORD), 1, fptr);
    fwrite(&bih.biBitCount, sizeof(WORD), 1, fptr);
    fwrite(&bih.biCompression, sizeof(DWORD), 1, fptr);
    fwrite(&bih.biSizeImage, sizeof(DWORD), 1, fptr);
    fwrite(&bih.biXPelsPerMeter, sizeof(LONG), 1, fptr);
    fwrite(&bih.biYPelsPerMeter, sizeof(LONG), 1, fptr);
    fwrite(&bih.biClrUsed, sizeof(DWORD), 1, fptr);
    fwrite(&bih.biClrImportant, sizeof(DWORD), 1, fptr);
    
    int i, j;
    
    // -- write pixels, bmp files are BGR ordering with padding at end,
    //    and are stored upside down in the file (unless height is negative,
    //    in which case this read will be incorrect)
    for (i = bih.biHeight - 1; i >= 0 ; --i) {
        
        // -- write row of pixels
        for (j = 0; j < bih.biWidth; ++j) {
            unsigned char pix;
            pix = (unsigned char)_blu[i][j];
            fwrite(&pix, 1, 1, fptr);
            pix = (unsigned char)_grn[i][j];
            fwrite(&pix, 1, 1, fptr);
            pix = (unsigned char)_red[i][j];
            fwrite(&pix, 1, 1, fptr);
        }
        
        // -- write row end padding
        unsigned char temp;
        for (j = 0; j < pad; ++j) {
            fwrite(&temp, 1, 1, fptr);
        }
    }
    
    fclose(fptr);
    
    return 1;
}



