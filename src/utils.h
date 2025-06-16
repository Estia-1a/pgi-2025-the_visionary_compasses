#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

struct pixelRGB *get_pixel(unsigned char *data, unsigned int width, unsigned int height, unsigned int n, unsigned int x, unsigned int y);

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
*/
void print_pixel(char *filename, int x, int y);

#endif
