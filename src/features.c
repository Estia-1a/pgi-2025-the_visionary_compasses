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
    int width, height, chanel_count;
    unsigned char *data;
    if(read_image_data(source_path, &data, &width, &height, &chanel_count)){
        printf ("dimension: %d, %d", width, height);
    }
    else{
        printf("Impossible de lire le fichier");

    }  
}
