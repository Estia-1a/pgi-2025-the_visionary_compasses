#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}
void dimension (char *source_path){
    int width, height, channels;

    unsigned char *data; 
    if (read_image_data(source_path,&data,&width,&height,&channels)){
        printf("dismensions : %d, %d \n", width, height);

    }
    else {
        printf("Erreur : Impossible de lire l'image");
    }

}



void tenth_pixel(char *source_path){
    int width, height, channels;
    unsigned char *data;
    
if (read_image_data(source_path, &data, &width, &height, &channels)) {
     if (width * height < 10) {
        printf("Erreur : L'image contient moins de 10 pixels.\n");
        free(data);
        return 0;
     }

 
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        
        int index = 9;  // 9 car commence le compte à 0
 
        unsigned char R = data[index];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 2];
 
        printf("tenth_pixel: R=%d, G=%d, B=%d\n", R, G, B);
 
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
}


