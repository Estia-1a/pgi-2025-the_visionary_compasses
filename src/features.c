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



void tenth_pixel(char *source_path){
    int width, height, channels;
    unsigned char *data;
    
if (read_image_data(source_path, &data, &width, &height, &channels)) {
     if (width * height < 10) {
        printf("Erreur : L'image contient moins de 10 pixels.\n");
        free(data);
        
     }

 
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        
        int index = 27;  // 9 car commence le compte à 0
 
        unsigned char R = data[index];
        unsigned char G = data[index + 1];
        unsigned char B = data[index + 2];
 
        printf("tenth_pixel: %d, %d, %d\n", R, G, B);
   free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
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

        printf("first_pixel: %d, %d, %d\n", R, G, B);

        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
void second_line(char *source_path) {
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channels)) {
       
        int index = 3 * width + 3;  
        int R = data[index];
        int G = data[index + 1];
        int B = data[index + 2];

        printf("second_line: %d, %d, %d\n", R, G, B);

        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
void max_pixel(char *source_path) {
    int width, height, channels;
    unsigned char *data;
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        // Variables pour stocker le pixel maximum
        int max_sum = -1;
        int max_x = 0, max_y = 0;
        unsigned char max_R, max_G, max_B;
        
        // Parcourir tous les pixels de l'image
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // Calculer l'index dans le tableau data
                int index = (y * width + x) * channels;
                
                // Obtenir les valeurs RGB du pixel actuel
                unsigned char R = data[index];
                unsigned char G = data[index + 1];
                unsigned char B = data[index + 2];
                
                // Calculer la somme RGB
                int current_sum = R + G + B;
                
                // Vérifier si c'est le maximum (premier rencontré en cas d'égalité)
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    max_x = x;
                    max_y = y;
                    max_R = R;
                    max_G = G;
                    max_B = B;
                }
            }
        }
        
        // Afficher le résultat dans le format requis
        printf("max_pixel (%d, %d): %d, %d, %d\n", max_x, max_y, max_R, max_G, max_B);
        
        free(data); // Libérer la mémoire
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
void min_component(char *source_path, char component) {
    int width, height, channels;
    unsigned char *data;
    
    // Vérifier que le composant est valide
    if (component != 'R' && component != 'G' && component != 'B') {
        printf("Erreur : Composant invalide. Utilisez R, G ou B\n");
        return;
    }
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int min_value = 256; 
        int min_x = 0, min_y = 0;
        
        int component_offset;
        switch (component) {
            case 'R': component_offset = 0; break;
            case 'G': component_offset = 1; break;
            case 'B': component_offset = 2; break;
        }
    }
        