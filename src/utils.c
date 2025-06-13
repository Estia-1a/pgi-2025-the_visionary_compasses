#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


 pixelRGB * get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y){
    if (data==NULL){
       return NULL; 
    } 
    if (x>= width ){
        return NULL;
    }
    if (y>= height){
        return NULL;
    }
      return (pixelRGB *) &data[(y*width + x)*n] ;
}

void print_pixel(char *filename, int x, int y) {
    unsigned char *data;
    int width, height, channel_count;
    pixelRGB *pixel = NULL;
    

    if (read_image_data(filename, &data, &width, &height, &channel_count)){
        pixel = get_pixel(data, width, height, channel_count, x, y);
        
        
    }
    else{
            printf("Erreur lors de la lecture de l'image\n");
    }

   
    
    if (pixel == NULL){
        printf("Erreur : pixel hors limites %d de longueur: %d et de hauteur: %d\n", pixel,width,height);
    } else {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    }
    return;
    free(data);
}
   
void color_invert(char *filename_in, char *filename_out) {
    unsigned char *data;
    int width, height, channel_count;

    if (read_image_data(filename_in, &data, &width, &height, &channel_count)) {
        printf("Erreur lors de la lecture de l'image : %s\n", filename_in);
        return;
    }

    if (channel_count < 3) {
        printf("Erreur : le nombre de canaux est insuffisant (%d)\n", channel_count);
        free(data);
        return;
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char *pixel = &data[(y * width + x) * channel_count];

            // Inverser les composantes RGB
            pixel[0] = 255 - pixel[0]; // R
            pixel[1] = 255 - pixel[1]; // G
            pixel[2] = 255 - pixel[2]; // B
        }
    }

    if (write_image_data(filename_out, &data, &width, &height)) {
        printf("Erreur lors de l'écriture de l'image : %s\n", filename_out);
    } else {
        printf("Image enregistrée avec couleurs inversées : %s\n", filename_out);
    }

    free(data);
}