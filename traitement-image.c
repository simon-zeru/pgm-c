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

pgm_t_pixel *pgm_malloc(int width, int height) {
    size_t size = width * height * sizeof(pgm_t_pixel);
    pgm_t_pixel *vPixel = (pgm_t_pixel *)malloc(size);
    if (vPixel == NULL) {
        return NULL;
    } 
    return vPixel;
}

void pgm_solid(pgm_t_pixel *pixels, int width, int height, pgm_t_pixel color) {
    for (int i = 0; i < (width * height * sizeof(pgm_t_pixel)); i++) {
        pixels[i] = color;
    }
}

int main(void) {
    size_t largeur = 400;
    size_t hauteur = 534;

    // allocation mémoire du vecteur de pixels
    pgm_t_pixel* vecteurPixel = pgm_malloc(largeur, hauteur);

    pgm_t_pixel gray = "G";

    // initialisation du vecteur avec du gris
    pgm_solid(vecteurPixel, largeur, hauteur, gray);

    // écriture de l'image
    pgm_naivewrite("image-couleur-unie.pgm", vecteurPixel, 400, 534);

    // libération de la mémoire allouée par le vecteur
    free(vecteurPixel);

    // affichage de la mémoire
    pgm_show("image-couleur-unie.pgm");

    // vérification de fuite mémoire : valgrind --leak-check=full ./traitement-image
    

    // lecture de l'image format pgm
    // vecteurPixel = pgm_naiveread("guadalest.pgm", &largeur, &hauteur);

    // if (vecteurPixel == NULL) {
    //     return EXIT_FAILURE;
    // }

    // écriture de la copie
    // pgm_naivewrite("guadalest_copie.pgm", vecteurPixel, largeur, hauteur);

    // liberation de la memoire
    // free(vecteurPixel);

    // pgm_show("guadalest.pgm");

    return EXIT_SUCCESS;
}