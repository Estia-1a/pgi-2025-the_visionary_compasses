#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


 struct pixelRGB * get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y){
    if (data==NULL){
       return NULL; 
    } 
    if (x>= width ){
        return NULL;
    }
    if (y>= height){
        return NULL;
    }
      return (struct pixelRGB *) &data[(y*width + x)*n] ;
}

void print_pixel(char *filename, int x, int y) {
    unsigned char *data;
    int width, height, channel_count;
    struct pixelRGB *pixel = NULL;
    

    if (read_image_data(filename, &data, &width, &height, &channel_count)){
        pixel = get_pixel(data, width, height, channel_count, x, y);
        
        
    }
    else{
            printf("Erreur lors de la lecture de l'image\n");
    }

   
    
    if (pixel == NULL){
        printf("Erreur : pixel hors limites %p de longueur: %d et de hauteur: %d\n", pixel,width,height);
    } else {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    }
    return;
    free(data);
}
   

