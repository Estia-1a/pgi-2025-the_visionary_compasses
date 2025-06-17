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
 **/

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
   free(data); 
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
void color_red (char*source_path) {
    int width = 0, height = 0, channels = 0, x=0, y=0;
    unsigned char *data = NULL;
    struct pixelRGB *pixel = NULL;

if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);
                pixel->G=0;
                pixel->B=0;                
            }
        }
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}


void color_green (char*source_path) {
    int width = 0, height = 0, channels = 0, x=0, y=0;
    unsigned char *data = NULL;
    struct pixelRGB *pixel = NULL;

if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);
                pixel->R=0;
                pixel->B=0;                
            }
        }
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void color_blue (char*source_path) {
    int width = 0, height = 0, channels = 0, x=0, y=0;
    unsigned char *data = NULL;
    struct pixelRGB *pixel = NULL;

if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);
                pixel->R=0;
                pixel->G=0;                
            }
        }
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void rotate_cw(char* source_path) {
    int width = 0, height = 0;
    unsigned char *data = NULL;
    int largeur = 0, hauteur = 0, canaux = 0;
    unsigned char *image_originale = NULL;
    unsigned char *image_rotation = NULL;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &image_originale, &largeur, &hauteur, &canaux)) {
        int nouvelle_largeur = hauteur;
        int nouvelle_hauteur = largeur;

        // Allouer de la mémoire pour l'image tournée
        image_rotation = (unsigned char*)malloc(nouvelle_largeur * nouvelle_hauteur * canaux);
        if (image_rotation == NULL) {
            printf("Erreur : impossible d'allouer la mémoire pour l'image tournée.\n");
            free(image_originale);
            return;
        }

        
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
               
                int index_original = (i * largeur + j) * canaux;

                // Nouvelle position après rotation
                int x = nouvelle_hauteur - 1 - j;
                int y = j;

                // Calculer l'index du pixel dans l'image tournée
                int index_rotation = (y * nouvelle_largeur + x) * canaux;

                
                for (int c = 0; c < canaux; c++) {
                    image_rotation[index_rotation + c] = image_originale[index_original + c];
                }
            }
        }
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void rotate_acw(char* source_path) {
    int largeur = 0, hauteur = 0, canaux = 0;
    unsigned char *image_originale = NULL;
    unsigned char *image_rotation = NULL;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &image_originale, &largeur, &hauteur, &canaux)) {
        int nouvelle_largeur = hauteur;
        int nouvelle_hauteur = largeur;

        // Allouer de la mémoire pour l'image tournée
        image_rotation = (unsigned char*)malloc(nouvelle_largeur * nouvelle_hauteur * canaux);
        if (image_rotation == NULL) {
            printf("Erreur : impossible d'allouer la mémoire pour l'image tournée.\n");
            free(image_originale);
            return;
        }

        
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
               
                int index_original = (i * largeur + j) * canaux;


                // Calculer l'index du pixel dans l'image tournée
                int index_rotation = (y * nouvelle_largeur + x) * canaux;

                
                for (int c = 0; c < canaux; c++) {
                    image_rotation[index_rotation + c] = image_originale[index_original + c];
                }
            }
        }

        // Sauvegarder l'image tournée
        write_image_data("image_out.bmp", image_rotation, nouvelle_largeur, nouvelle_hauteur);

        // Libérer la mémoire
        free(image_originale);
        free(image_rotation);
    } else {
        printf("Erreur : Impossible de lire l'image.\n");
    }
}


void miror_horizontal(char* source_path) {
    int width = 0, height = 0;
    unsigned char *data = NULL;
    int largeur = 0, hauteur = 0, canaux = 0;
    unsigned char *image_originale = NULL;
    unsigned char *image_rotation = NULL;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &image_originale, &largeur, &hauteur, &canaux)) {
        int nouvelle_largeur = largeur;
        int nouvelle_hauteur = hauteur;

        // Allouer de la mémoire pour l'image tournée
        image_rotation = (unsigned char*)malloc(nouvelle_largeur * nouvelle_hauteur * canaux);
        if (image_rotation == NULL) {
            printf("Erreur : impossible d'allouer la mémoire pour l'image tournée.\n");
            free(image_originale);
            return;
        }

        
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
               
                int index_original = (i * largeur + j) * canaux;

                // Nouvelle position après rotation
                int x = i;
                int y = nouvelle_hauteur - 1 - i;

                // Calculer l'index du pixel dans l'image tournée
                int index_rotation = (y * nouvelle_largeur + x) * canaux;

                
                for (int c = 0; c < canaux; c++) {
                    image_rotation[index_rotation + c] = image_originale[index_original + c];
                }
            }
        }
        write_image_data ("image_out_gray.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void miror_vertical(char* source_path) {
    int largeur = 0, hauteur = 0, canaux = 0;
    unsigned char *image_originale = NULL;
    unsigned char *image_rotation = NULL;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &image_originale, &largeur, &hauteur, &canaux)) {
        int nouvelle_largeur = largeur;
        int nouvelle_hauteur = hauteur;

        // Allouer de la mémoire pour l'image tournée
        image_rotation = (unsigned char*)malloc(nouvelle_largeur * nouvelle_hauteur * canaux);
        if (image_rotation == NULL) {
            printf("Erreur : impossible d'allouer la mémoire pour l'image tournée.\n");
            free(image_originale);
            return;
        }

        
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
               
                int index_original = (i * largeur + j) * canaux;

                // Nouvelle position après rotation
                int x = nouvelle_largeur - 1 - j;
                int y = j;

                // Calculer l'index du pixel dans l'image tournée
                int index_rotation = (y * nouvelle_largeur + x) * canaux;

                
                for (int c = 0; c < canaux; c++) {
                    image_rotation[index_rotation + c] = image_originale[index_original + c];
                }
            }
        }

        // Sauvegarder l'image tournée
        write_image_data("image_out.bmp", image_rotation, nouvelle_largeur, nouvelle_hauteur);

        // Libérer la mémoire
        free(image_originale);
        free(image_rotation);
    } else {
        printf("Erreur : Impossible de lire l'image.\n");
    }
}

void color_invert (char*source_path) {
    int width = 0, height = 0, channels = 0, x=0, y=0;
    unsigned char *data = NULL;
    struct pixelRGB *pixel = NULL;

if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);
                pixel->R=255-pixel->R;
                pixel->G=255-pixel->G;
                pixel->B=255-pixel->B;           
            }
        }
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void miror_total(char* source_path) {
    int largeur = 0, hauteur = 0, canaux = 0;
    unsigned char *image_originale = NULL;
    unsigned char *image_rotation = NULL;

    // Lire l'image d'entrée
    if (read_image_data(source_path, &image_originale, &largeur, &hauteur, &canaux)) {
        int nouvelle_largeur = largeur;
        int nouvelle_hauteur = hauteur;

        // Allouer de la mémoire pour l'image tournée
        image_rotation = (unsigned char*)malloc(nouvelle_largeur * nouvelle_hauteur * canaux);
        if (image_rotation == NULL) {
            printf("Erreur : impossible d'allouer la mémoire pour l'image tournée.\n");
            free(image_originale);
            return;
        }

        
        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
               
                int index_original = (i * largeur + j) * canaux;

                // Nouvelle position après rotation
                int x = nouvelle_largeur - 1 - i;
                int y = nouvelle_hauteur -1 -j;

                // Calculer l'index du pixel dans l'image tournée
                int index_rotation = (y * nouvelle_largeur + x) * canaux;

                
                for (int c = 0; c < canaux; c++) {
                    image_rotation[index_rotation + c] = image_originale[index_original + c];
                }
            }
        }

        // Sauvegarder l'image tournée
        write_image_data("image_out.bmp", image_rotation, nouvelle_largeur, nouvelle_hauteur);

        // Libérer la mémoire
        free(image_originale);
        free(image_rotation);
    } else {
        printf("Erreur : Impossible de lire l'image.\n");
    }
}

void color_gray (char*source_path) {
int width = 0, height = 0, channels = 0, x=0, y=0, av=0;
unsigned char *data = NULL;
struct pixelRGB *pixel = NULL;


if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);
                av=(pixel->B+pixel->R+pixel->G)/3;
                pixel->B=av;
                pixel->R=av; 
                pixel->G=av;               
            }
        }
        write_image_data ("image_out_gray.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void color_gray_luminance (char*source_path) {
int width = 0, height = 0, channels = 0, x=0, y=0;
unsigned char *data = NULL;
struct pixelRGB *pixel = NULL;
unsigned char value = 0;


if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);
                value= 0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B;
                pixel->B=value;
                pixel->R=value; 
                pixel->G=value;               
            }
        }
        write_image_data ("image_out_gray.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
