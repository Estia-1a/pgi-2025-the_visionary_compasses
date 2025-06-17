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

}



 