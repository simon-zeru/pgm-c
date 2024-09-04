#include <naivepgmio.h>
#include <stdlib.h>
#include <stdio.h>

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
    pgm_naivewrite("guadalest_copie.pgm", vecteurPixel, largeur, hauteur);

    // liberation de la memoire
    free(vecteurPixel);

    return EXIT_SUCCESS;
}