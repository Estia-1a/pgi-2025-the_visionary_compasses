#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
  /*
   * TO COMPLETE
   */
  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "tenth_pixel", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    tenth_pixel( configuration.filenames[0] );
}

if (strncmp(configuration.command, "print_pixel", 11) == 0) {
    if (configuration.arguments[0] || configuration.arguments[1]) {
        printf("Usage: freud.exe -f <image> -c print_pixel <x> <y>\n");
        return 1;
    }
    
    // Convertir les arguments en entiers
    int x = atoi(configuration.arguments[0]);  // Premier argument = x
    int y = atoi(configuration.arguments[1]);  // Deuxième argument = y
    
    // Appeler votre fonction
    print_pixel(configuration.filenames[0], x, y);
}

 if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    second_line(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "color_red", 9 ) == 0 ) {
    /* color_red() function is defined in feature.h and implemented in feature.c */
    color_red(configuration.filenames[0]);
}


if ( strncmp( configuration.command, "color_green", 13 ) == 0 ) {
    /* color_green() function is defined in feature.h and implemented in feature.c */
    color_green(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "color_blue", 14 ) == 0 ) {
    /* color_blue() function is defined in feature.h and implemented in feature.c */
    color_blue(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "color_gray", 14 ) == 0 ) {
    /* color_gray() function is defined in feature.h and implemented in feature.c */
    color_gray(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "color_gray_luminance", 14 ) == 0 ) {
    /* color_gray() function is defined in feature.h and implemented in feature.c */
    color_gray_luminance(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "color_invert", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    color_invert( configuration.filenames[0] );
}

if ( strncmp( configuration.command, "miror_total", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    miror_total( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "rotate_cw", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    rotate_cw( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "rotate_acw", 9 ) == 0 ) {
    rotate_acw( configuration.filenames[0] );
}

if ( strncmp( configuration.command, "miror_horizontal", 9 ) == 0 ) {
    miror_horizontal( configuration.filenames[0] );
}

if ( strncmp( configuration.command, "miror_vertical", 9 ) == 0 ) {
    miror_vertical( configuration.filenames[0] );
}
if ( strncmp( configuration.command, "color_desaturate", 9 ) == 0 ) {
   
    color_desaturate( configuration.filenames[0] );
}
if (strncmp(configuration.command, "min_component", 13) == 0) {
    if (configuration.arguments[0] == NULL) {
        printf("Usage: freud.exe -f <image> -c min_component <R|G|B>\n");
        printf("Exemple: freud.exe -f image.jpeg -c min_component R\n");
        return 1;
    }
    
    char component = configuration.arguments[0][0]; // Premier caractère
    if (component != 'R' && component != 'G' && component != 'B') {
        printf("Erreur: Composant invalide '%s'. Utilisez R, G ou B\n", configuration.arguments[0]);
        return 1;
    }
    min_component(configuration.filenames[0], component);
}
if (strncmp(configuration.command, "max_component", 13) == 0) {
    if (configuration.arguments[0] == NULL) {
        printf("Usage: freud.exe -f <image> -c max_component <R|G|B>\n");
        printf("Exemple: freud.exe -f image.jpeg -c max_component R\n");
        return 1;
    }
    

    char component = configuration.arguments[0][0]; 
    if (component != 'R' && component != 'G' && component != 'B') {
        printf("Erreur: Composant invalide '%s'. Utilisez R, G ou B\n", configuration.arguments[0]);
        return 1;
    }
    
 
    max_component(configuration.filenames[0], component);
}

if ( strncmp( configuration.command, "stat_report", 11 ) == 0 ) {
    stat_report(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    print_pixel(configuration.filenames[0], configuration.filenames[0], configuration.filenames[0]);
}

if ( strncmp( configuration.command, "max_pixel", 11 ) == 0 ) {
    max_pixel(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    
    dimension( configuration.filenames[0] );
}

if ( strncmp( configuration.command, "min_pixel", 9 ) == 0 ) {
    min_pixel(configuration.filenames[0]);
}

if ( strncmp( configuration.command, "scale_nearest", 9 ) == 0 ) {
    scale_nearest(configuration.filenames[0], 3.0f);
}

if (strncmp(configuration.command, "scale_bilinear", 14) == 0) {
    if (configuration.arguments[0] == NULL) {
        printf("Usage: freud.exe -f <image> -c scale_bilinear <scale_factor>\n");
        printf("Exemple: freud.exe -f image.jpeg -c scale_bilinear 3\n");
        return 1;
    }
    

    float scale_factor = atof(configuration.arguments[0]);
    
    if (scale_factor <= 0) {
        printf("Erreur: Le facteur d'échelle doit être positif (reçu: %f)\n", scale_factor);
        return 1;
    }
    
 
    scale_bilinear(configuration.filenames[0], scale_factor);
}
if (strncmp(configuration.command, "scale_crop", 10) == 0) {

    printf("Debug: Nombre d'arguments disponibles:\n");
    for (int i = 0; i < 10 && configuration.arguments[i] != NULL; i++) {
        printf("  args[%d] = '%s'\n", i, configuration.arguments[i]);
    }
    
    if (configuration.arguments[0] == NULL || configuration.arguments[1] == NULL || 
        configuration.arguments[2] == NULL || configuration.arguments[3] == NULL) {
        printf("Usage: freud.exe -f <image> -c scale_crop <center_x> <center_y> <width> <height>\n");
        printf("Exemple: freud.exe -f image.jpeg -c scale_crop 500 600 300 400\n");
        return 1;
    }
    
    int center_x = atoi(configuration.arguments[0]);
    int center_y = atoi(configuration.arguments[1]);
    int crop_width = atoi(configuration.arguments[2]);
    int crop_height = atoi(configuration.arguments[3]);
    
    
    if (crop_width <= 0 || crop_height <= 0) {
        printf("Erreur: La largeur et la hauteur doivent être positives\n");
        printf("Reçu: largeur=%d, hauteur=%d\n", crop_width, crop_height);
        return 1;
    }
    
    scale_crop(configuration.filenames[0], center_x, center_y, crop_width, crop_height);
}
}



 
