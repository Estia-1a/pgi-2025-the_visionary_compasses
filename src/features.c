#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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
    if (read_image_data(source_path, &data, &width, &height, &channels)){
        printf("dimensions : %d, %d \n", width, height);

    }
    else {
        printf("Erreur : Impossible de lire l'image");
    }

}

void first_pixel(char *source_path) {
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        // Coordonnées du premier pixel : x = 0, y = 0
        // Position dans le tableau : (y * width + x) * channels
        int index = 0;  // (0 * width + 0) * channels = 0

        int R = data[index];
        int G = data[index + 1];
        int B = data[index + 2];

        printf("first_pixel: R=%d, G=%d, B=%d\n", R, G, B);

        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
