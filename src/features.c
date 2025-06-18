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
 
                int new_x = y;
                int new_y = new_height - 1 - y;
 
               
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

                int new_x = new_height - 1 - x;
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
unsigned char value = 0;


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