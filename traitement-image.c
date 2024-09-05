#include <naivepgmio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pgm_show(char *filename) {
    size_t size = strlen(filename) + strlen("eog") + 2;
    char *ptr = (char*)malloc(size);
    snprintf(ptr, size, "eog %s", filename);
    if (ptr == NULL) {
        return;
    }
    system(ptr);
    free(ptr);
}

int main(void) {
    size_t largeur = 400;
    size_t hauteur = 534;
    pgm_t_pixel vecteurPixel;

    // lecture de l'image format pgm
    vecteurPixel = pgm_naiveread("guadalest.pgm", &largeur, &hauteur);

    if (vecteurPixel == NULL) {
        return EXIT_FAILURE;
    }

    // écriture de la copie
    // pgm_naivewrite("guadalest_copie.pgm", vecteurPixel, largeur, hauteur);

    // liberation de la memoire
    // free(vecteurPixel);

    pgm_show("guadalest.pgm");

    return EXIT_SUCCESS;
}