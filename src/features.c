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
        printf("dimension: %d, %d\n", width, height);

    }
    else {
        printf("Erreur : Impossible de lire l'image");
        read_image_data(source_path, &data, &width, &height, &channels);
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
                int x = nouvelle_hauteur - 1 - i;
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
    int width = 0, height = 0, channels = 0;
    unsigned char *data = NULL;
    unsigned char *rotated_data = NULL;

    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int new_width = height;
        int new_height = width;

        
        rotated_data = (unsigned char *)malloc(new_width * new_height * channels);
        if (!rotated_data) {
            printf("Erreur : échec d'allocation mémoire.\n");
            free(data);
            return;
        }

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                
                struct pixelRGB *src_pixel = get_pixel(data, width, height, channels, x, y);

                int new_x = y;
                int new_y = new_height - 1 - x;

                
                struct pixelRGB *dst_pixel = get_pixel(rotated_data, new_width, new_height, channels, new_x, new_y);

                
                dst_pixel->R = src_pixel->R;
                dst_pixel->G = src_pixel->G;
                dst_pixel->B = src_pixel->B;
            }
        }

        write_image_data("image_out.bmp", rotated_data, new_width, new_height);

        
        free(data);
        free(rotated_data);
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}


void miror_horizontal(char* source_path) {
    int width = 0, height = 0, channels = 0;
    unsigned char *data = NULL;
    unsigned char *rotated_data = NULL;
 
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int new_width = width;
        int new_height = height;
 
       
        rotated_data = (unsigned char *)malloc(new_width * new_height * channels);
        if (!rotated_data) {
            printf("Erreur : échec d'allocation mémoire.\n");
            free(data);
            return;
        }
 
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
               
                struct pixelRGB *src_pixel = get_pixel(data, width, height, channels, x, y);
 
                int new_x = width - 1 - x;
                int new_y = y;

 
               
                struct pixelRGB *dst_pixel = get_pixel(rotated_data, new_width, new_height, channels, new_x, new_y);
 
               
                dst_pixel->R = src_pixel->R;
                dst_pixel->G = src_pixel->G;
                dst_pixel->B = src_pixel->B;
            }
        }
 
        write_image_data("image_out.bmp", rotated_data, new_width, new_height);
 
       
        free(data);
        free(rotated_data);
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void min_pixel(char *source_path) {
    int width, height, channels;
    unsigned char *data;
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        // Variables pour stocker le pixel minimum
        int min_sum = 999999; // Initialiser avec une valeur très grande
        int min_x = 0, min_y = 0;
        unsigned char min_R, min_G, min_B;
        
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
                
                // Vérifier si c'est le minimum (premier rencontré en cas d'égalité)
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    min_x = x;
                    min_y = y;
                    min_R = R;
                    min_G = G;
                    min_B = B;
                }
            }
        }
        printf("min_pixel (%d, %d): %d, %d, %d\n", min_x, min_y, min_R, min_G, min_B);
        
        free(data); 
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

void miror_vertical(char* source_path) {
    int width = 0, height = 0, channels = 0;
    unsigned char *data = NULL;
    unsigned char *rotated_data = NULL;

    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int new_width = width;
        int new_height = height;

        
        rotated_data = (unsigned char *)malloc(new_width * new_height * channels);
        if (!rotated_data) {
            printf("Erreur : échec d'allocation mémoire.\n");
            free(data);
            return;
        }

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                
                struct pixelRGB *src_pixel = get_pixel(data, width, height, channels, x, y);

                int new_x =  x;
                int new_y = height -1- y;

                
                struct pixelRGB *dst_pixel = get_pixel(rotated_data, new_width, new_height, channels, new_x, new_y);

                
                dst_pixel->R = src_pixel->R;
                dst_pixel->G = src_pixel->G;
                dst_pixel->B = src_pixel->B;
            }
        }

        write_image_data("image_out.bmp", rotated_data, new_width, new_height);

        
        free(data);
        free(rotated_data);
    } else {
        printf("Erreur : Impossible de lire l'image\n");
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
                int x = nouvelle_largeur - 1 - j;
                int y = nouvelle_hauteur -1 - i;

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
        write_image_data ("image_out.bmp", data, width, height);
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
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
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
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculer l'index dans le tableau data
            int index = (y * width + x) * channels;
            
            // Obtenir la valeur du composant choisi
            unsigned char current_component = data[index + component_offset];
            
            
            if (current_component < min_value) {
                min_value = current_component;
                min_x = x;
                min_y = y;
            }
        }
    }
    
    
    printf("min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
    
    free(data); 

    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}

void color_desaturate (char*source_path) {
int width = 0, height = 0, channels = 0, x=0, y=0;
unsigned char *data = NULL;
struct pixelRGB *pixel = NULL;


if (read_image_data(source_path, &data, &width, &height, &channels)) {
       for (x=0; x<width; x++){
            for (y=0; y<height; y++){
                pixel = get_pixel(data, width, height, channels, x, y);

                unsigned char R = pixel->R;
                unsigned char G = pixel->G;
                unsigned char B = pixel->B;

                unsigned char max_val = R;
                if (G > max_val) max_val = G;
                if (B > max_val) max_val = B;

                unsigned char min_val = R;
                if (G < min_val) min_val = G;
                if (B < min_val) min_val = B;

                unsigned char value = (max_val + min_val) / 2;

                pixel->B=value;
                pixel->R=value; 
                pixel->G=value;               
            }
        }
        write_image_data ("image_out.bmp", data, width, height);
        free(data); // Libère la mémoire après usage
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    }
}
void max_component(char *source_path, char component) {
    int width, height, channels;
    unsigned char *data;
     if (component != 'R' && component != 'G' && component != 'B') {
        printf("Erreur : Composant invalide. Utilisez R, G ou B\n");
        return;
    }
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
       
        int max_value = -1; 
        int max_x = 0, max_y = 0;
        
        // Déterminer l'offset selon le composant choisi
        int component_offset;
        switch (component) {
            case 'R': component_offset = 0; break;
            case 'G': component_offset = 1; break;
            case 'B': component_offset = 2; break;
        }
        // Parcourir tous les pixels de l'image
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // Calculer l'index dans le tableau data
                int index = (y * width + x) * channels;
                
                // Obtenir la valeur du composant choisi
                unsigned char current_component = data[index + component_offset];
                
                // Vérifier si c'est le maximum (premier rencontré en cas d'égalité)
                if (current_component > max_value) {
                    max_value = current_component;
                    max_x = x;
                    max_y = y;
                }
            }
        }
        
        printf("max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
        free(data);
    } else {
        printf("Erreur : Impossible de lire l'image\n");
    } 
}

void calculate_max_pixel(char *source_path, int *x, int *y, int *r, int *g, int *b) {
    int width, height, channels;
    unsigned char *data;
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int max_sum = -1;
        *x = 0; *y = 0;
        
        for (int py = 0; py < height; py++) {
            for (int px = 0; px < width; px++) {
                int index = (py * width + px) * channels;
                unsigned char R = data[index];
                unsigned char G = data[index + 1];
                unsigned char B = data[index + 2];
                int current_sum = R + G + B;
                
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    *x = px; *y = py;
                    *r = R; *g = G; *b = B;
                }
            }
        }
        free(data);
    }
}
void calculate_min_pixel(char *source_path, int *x, int *y, int *r, int *g, int *b) {
    int width, height, channels;
    unsigned char *data;
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int min_sum = 999999;
        *x = 0; *y = 0;
        
        for (int py = 0; py < height; py++) {
            for (int px = 0; px < width; px++) {
                int index = (py * width + px) * channels;
                unsigned char R = data[index];
                unsigned char G = data[index + 1];
                unsigned char B = data[index + 2];
                int current_sum = R + G + B;
                
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                    *x = px; *y = py;
                    *r = R; *g = G; *b = B;
                }
            }
        }
        free(data);
    }
}
void calculate_max_component(char *source_path, char component, int *x, int *y, int *value) {
    int width, height, channels;
    unsigned char *data;
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int max_value = -1;
        *x = 0; *y = 0;
        
        int component_offset;
        switch (component) {
            case 'R': component_offset = 0; break;
            case 'G': component_offset = 1; break;
            case 'B': component_offset = 2; break;
        }
        
        for (int py = 0; py < height; py++) {
            for (int px = 0; px < width; px++) {
                int index = (py * width + px) * channels;
                unsigned char current_component = data[index + component_offset];
                
                if (current_component > max_value) {
                    max_value = current_component;
                    *x = px; *y = py;
                }
            }
        }
        *value = max_value;
        free(data);
    }
}
void calculate_min_component(char *source_path, char component, int *x, int *y, int *value) {
    int width, height, channels;
    unsigned char *data;
    
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        int min_value = 256;
        *x = 0; *y = 0;
        
        int component_offset;
        switch (component) {
            case 'R': component_offset = 0; break;
            case 'G': component_offset = 1; break;
            case 'B': component_offset = 2; break;
        }
        
        for (int py = 0; py < height; py++) {
            for (int px = 0; px < width; px++) {
                int index = (py * width + px) * channels;
                unsigned char current_component = data[index + component_offset];
                
                if (current_component < min_value) {
                    min_value = current_component;
                    *x = px; *y = py;
                }
            }
        }
        *value = min_value;
        free(data);
    }
}
void stat_report(char *source_path) {
    // Créer le nom du fichier de sortie
    FILE *file = fopen("stat_report.txt", "w");
    if (!file) {
        printf("Erreur : Impossible de créer le fichier stat_report.txt\n");
        return;
    }
    
    // Variables pour stocker les résultats
    int x, y, r, g, b, value;
    
    // Calculer max_pixel
    calculate_max_pixel(source_path, &x, &y, &r, &g, &b);
    fprintf(file, "max_pixel (%d, %d): %d, %d, %d\n\n", x, y, r, g, b);
    
    // Calculer min_pixel
    calculate_min_pixel(source_path, &x, &y, &r, &g, &b);
    fprintf(file, "min_pixel (%d, %d): %d, %d, %d\n\n", x, y, r, g, b);
    
    // Calculer max_component R
    calculate_max_component(source_path, 'R', &x, &y, &value);
    fprintf(file, "max_component R (%d, %d): %d\n\n", x, y, value);
    
    // Calculer max_component G
    calculate_max_component(source_path, 'G', &x, &y, &value);
    fprintf(file, "max_component G (%d, %d): %d\n\n", x, y, value);
    
    // Calculer max_component B
    calculate_max_component(source_path, 'B', &x, &y, &value);
    fprintf(file, "max_component B (%d, %d): %d\n\n", x, y, value);
    
    // Calculer min_component R
    calculate_min_component(source_path, 'R', &x, &y, &value);
    fprintf(file, "min_component R (%d, %d): %d\n\n", x, y, value);
    
    // Calculer min_component G
    calculate_min_component(source_path, 'G', &x, &y, &value);
    fprintf(file, "min_component G (%d, %d): %d\n\n", x, y, value);
    
    // Calculer min_component B
    calculate_min_component(source_path, 'B', &x, &y, &value);
    fprintf(file, "min_component B (%d, %d): %d\n", x, y, value);
    
    fclose(file);
    printf("Rapport statistique généré dans 'stat_report.txt'\n");
}


// Fonction utilitaire pour l'interpolation bilinéaire d'un pixel
static struct pixelRGB interpolate_bilinear_pixel(unsigned char* data, int width, int height, int channels, double x, double y) {
    struct pixelRGB result = {0, 0, 0};
    
    // Gérer les cas de bord
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= width - 1) x = width - 1;
    if (y >= height - 1) y = height - 1;
    
    // Coordonnées des pixels voisins
    int x1 = (int)x;
    int y1 = (int)y;
    int x2 = x1 + 1;
    int y2 = y1 + 1;
    
    // S'assurer qu'on reste dans les limites
    if (x2 >= width) x2 = width - 1;
    if (y2 >= height) y2 = height - 1;
    
    // Facteurs d'interpolation
    double dx = x - x1;
    double dy = y - y1;
    
    // Obtenir les pixels aux quatre coins
    struct pixelRGB *p11 = get_pixel(data, width, height, channels, x1, y1);
    struct pixelRGB *p12 = get_pixel(data, width, height, channels, x1, y2);
    struct pixelRGB *p21 = get_pixel(data, width, height, channels, x2, y1);
    struct pixelRGB *p22 = get_pixel(data, width, height, channels, x2, y2);
    
    // Vérifier que tous les pixels sont valides
    if (p11 && p12 && p21 && p22) {
        // Interpolation bilinéaire pour chaque canal
        result.R = (unsigned char)(
            p11->R * (1 - dx) * (1 - dy) +
            p21->R * dx * (1 - dy) +
            p12->R * (1 - dx) * dy +
            p22->R * dx * dy + 0.5
        );
        
        result.G = (unsigned char)(
            p11->G * (1 - dx) * (1 - dy) +
            p21->G * dx * (1 - dy) +
            p12->G * (1 - dx) * dy +
            p22->G * dx * dy + 0.5
        );
        
        result.B = (unsigned char)(
            p11->B * (1 - dx) * (1 - dy) +
            p21->B * dx * (1 - dy) +
            p12->B * (1 - dx) * dy +
            p22->B * dx * dy + 0.5
        );
    } else {
        // Si on ne peut pas accéder aux pixels, utiliser le pixel le plus proche
        struct pixelRGB *nearest = get_pixel(data, width, height, channels, (int)(x + 0.5), (int)(y + 0.5));
        if (nearest) {
            result = *nearest;
        }
    }
    
    return result;
}

void scale_bilinear(const char* source_path, float scale) {
    int width = 0, height = 0, channels = 0;
    unsigned char *data = NULL;
    unsigned char *output_data = NULL;

    // Charger l'image d'entrée
    if (read_image_data(source_path, &data, &width, &height, &channels)) {
        // Calculer les nouvelles dimensions
        int new_width = (int)(width * scale);
        int new_height = (int)(height * scale);
        
        printf("Image originale : %d x %d\n", width, height);
        printf("Image redimensionnée : %d x %d (facteur: %.2f)\n", new_width, new_height, scale);

        // Allouer la mémoire pour l'image de sortie
        output_data = (unsigned char*)malloc(new_width * new_height * channels);
        if (!output_data) {
            printf("Erreur : échec d'allocation mémoire pour l'image de sortie.\n");
            free(data);
            return;
        }

        // Appliquer l'interpolation bilinéaire
        for (int y = 0; y < new_height; y++) {
            for (int x = 0; x < new_width; x++) {
                // Mapper les coordonnées vers l'image originale
                double src_x = (double)x / scale;
                double src_y = (double)y / scale;
                
                // Obtenir le pixel interpolé
                struct pixelRGB interpolated = interpolate_bilinear_pixel(data, width, height, channels, src_x, src_y);
                
                // Stocker le pixel dans l'image de sortie
                struct pixelRGB *dst_pixel = get_pixel(output_data, new_width, new_height, channels, x, y);
                if (dst_pixel) {
                    dst_pixel->R = interpolated.R;
                    dst_pixel->G = interpolated.G;
                    dst_pixel->B = interpolated.B;
                }
            }
        }

        // Sauvegarder l'image redimensionnée
        write_image_data("image_out.bmp", output_data, new_width, new_height);
        
        printf("Redimensionnement bilinéaire terminé. Image sauvegardée : image_out.bmp\n");

        // Libérer la mémoire
        free(data);
        free(output_data);
    } else {
        printf("Erreur : Impossible de lire l'image %s\n", source_path);
    }
}

void scale_crop(const char* source_path, int center_x, int center_y, int crop_width, int crop_height) {
    int width = 0, height = 0, channels = 0;
    unsigned char *data = NULL;
    unsigned char *output_data = NULL;

    printf("=== DEBUG scale_crop ===\n");
    printf("Paramètres reçus: center=(%d,%d), taille=%dx%d\n", center_x, center_y, crop_width, crop_height);

    if (!read_image_data(source_path, &data, &width, &height, &channels)) {
        printf("Erreur : Impossible de lire l'image %s\n", source_path);
        return;
    }

    printf("Image originale : %d x %d, channels=%d\n", width, height, channels);
    if (crop_width <= 0 || crop_height <= 0) {
        printf("Erreur: Dimensions invalides: %dx%d\n", crop_width, crop_height);
        free(data);
        return;
    }

    int output_size = crop_width * crop_height * channels;
    output_data = (unsigned char*)calloc(output_size, sizeof(unsigned char));
    if (!output_data) {
        printf("Erreur : échec d'allocation mémoire (%d bytes)\n", output_size);
        free(data);
        return;
    }
    int start_x = center_x - crop_width / 2;
    int start_y = center_y - crop_height / 2;

    printf("Coin supérieur gauche du crop : (%d, %d)\n", start_x, start_y);
    printf("Coin inférieur droit du crop : (%d, %d)\n", start_x + crop_width - 1, start_y + crop_height - 1);

    
    for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
          
            int src_x = start_x + x;
            int src_y = start_y + y;
            
            
            int dst_index = (y * crop_width + x) * channels;
            
            
            if (src_x >= 0 && src_x < width && src_y >= 0 && src_y < height) {
                
                int src_index = (src_y * width + src_x) * channels;
                
                output_data[dst_index] = data[src_index];         // R
                output_data[dst_index + 1] = data[src_index + 1]; // G
                output_data[dst_index + 2] = data[src_index + 2]; // B
            } else {
               
                output_data[dst_index] = 0;     // R
                output_data[dst_index + 1] = 0; // G  
                output_data[dst_index + 2] = 0; // B
            }
        }
    }
    if (write_image_data("image_out.bmp", output_data, crop_width, crop_height)) {
        printf("Crop terminé. Image sauvegardée : image_out.bmp (%d x %d)\n", crop_width, crop_height);
    } else {
        printf("Erreur lors de la sauvegarde de l'image\n");
    }

    free(data);
    free(output_data);
}



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char* data;
} Image;

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // "BM"
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

// Charger une image BMP 24 bits non compressée
Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Erreur : impossible d'ouvrir %s\n", filename);
        return NULL;
    }

    BITMAPFILEHEADER file_header;
    fread(&file_header, sizeof(BITMAPFILEHEADER), 1, file);

    if (file_header.bfType != 0x4D42) {
        printf("Erreur : ce fichier n'est pas un BMP valide.\n");
        fclose(file);
        return NULL;
    }

    BITMAPINFOHEADER info_header;
    fread(&info_header, sizeof(BITMAPINFOHEADER), 1, file);

    if (info_header.biBitCount != 24 || info_header.biCompression != 0) {
        printf("Erreur : seul le BMP 24 bits non compressé est supporté.\n");
        fclose(file);
        return NULL;
    }

    int width = info_header.biWidth;
    int height = info_header.biHeight;
    int channels = 3;

    // Calcul du padding par ligne (BMP : lignes alignées sur 4 octets)
    int padding = (4 - (width * channels) % 4) % 4;

    unsigned char* data = malloc(width * height * channels);
    if (!data) {
        fclose(file);
        return NULL;
    }

    fseek(file, file_header.bfOffBits, SEEK_SET);

    // Lecture ligne par ligne (de bas en haut)
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channels;
            fread(&data[index], 1, channels, file); // BGR
        }
        fseek(file, padding, SEEK_CUR); // saut du padding
    }

    fclose(file);

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = data;

    return img;
}

// Sauvegarder une image au format BMP 24 bits
void save_image_bmp(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Erreur : impossible de créer %s\n", filename);
        return;
    }

    int width = img->width;
    int height = img->height;
    int channels = img->channels;
    int padding = (4 - (width * channels) % 4) % 4;
    int row_size = width * channels + padding;

    BITMAPFILEHEADER file_header = {
        .bfType = 0x4D42,
        .bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + row_size * height,
        .bfReserved1 = 0,
        .bfReserved2 = 0,
        .bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
    };

    BITMAPINFOHEADER info_header = {
        .biSize = sizeof(BITMAPINFOHEADER),
        .biWidth = width,
        .biHeight = height,
        .biPlanes = 1,
        .biBitCount = 24,
        .biCompression = 0,
        .biSizeImage = row_size * height,
        .biXPelsPerMeter = 0,
        .biYPelsPerMeter = 0,
        .biClrUsed = 0,
        .biClrImportant = 0
    };

    fwrite(&file_header, sizeof(file_header), 1, file);
    fwrite(&info_header, sizeof(info_header), 1, file);

    unsigned char padding_bytes[3] = {0, 0, 0};

    // Écriture ligne par ligne (de bas en haut)
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channels;
            fwrite(&img->data[index], 1, channels, file); // BGR
        }
        fwrite(padding_bytes, 1, padding, file);
    }

    fclose(file);
}

// Libérer une image
void free_image(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}


void scale_nearest(const char* filename, float scale) {     // Charger l'image d'entrée
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char* data;
} Image;

    Image* input_img = load_image(filename);
    if (input_img == NULL) {    
    printf("Erreur : impossible de charger l'image %s\n", filename);
    return; 
    }     // Calculer les nouvelles dimensions
    int new_width = (int)(input_img->width * scale);
    int new_height = (int)(input_img->height * scale);
    printf("Redimensionnement de %dx%d vers %dx%d (facteur: %.2f)\n",
    input_img->width, input_img->height, new_width, new_height, scale);     // Créer l'image de sortie
    Image* output_img = malloc(sizeof(Image));
    output_img->width = new_width;
    output_img->height = new_height;
    output_img->channels = input_img->channels;
    output_img->data = malloc(new_width * new_height * output_img->channels);    // Algorithme du plus proche voisin
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {             // Calculer les coordonnées correspondantes dans l'image source
            int src_x = (int)(x / scale);
            int src_y = (int)(y / scale);             // S'assurer que les coordonnées sont dans les limites
            if (src_x >= input_img->width) src_x = input_img->width - 1;
                if (src_y >= input_img->height) src_y = input_img->height - 1;             // Copier les valeurs des pixels
                    for (int c = 0; c < output_img->channels; c++) {
                        int src_index = (src_y * input_img->width + src_x) * input_img->channels + c;
                        int dst_index = (y * new_width + x) * output_img->channels + c;
                        output_img->data[dst_index] = input_img->data[src_index];
                        }
                        }
                        }     // Sauvegarder l'image de sortie
    save_image_bmp("image_out.bmp", output_img);
    printf("Image sauvegardée sous : image_out.bmp\n");     // Libérer la mémoire
    free_image(input_img);
    free_image(output_img);
    } // Fonction pour charger une image (format basique)