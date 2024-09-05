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
    size_t size = width * height;
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

void pgm_negative(pgm_t_pixel *pixels, int width, int height) {
    for (int i = 0; i < (width * height); i++) {
        pixels[i] = 255 - pixels[i];
    }
}

void pgm_threshold(pgm_t_pixel *pixels, int width, int height, pgm_t_pixel pgm_threshold) {
    if ( pgm_threshold < 0 || pgm_threshold > 255 ) {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < (width * height); i++) {
        pixels[i] = pixels[i] < pgm_threshold ? 0 : 255;
    }
}

int main(void) {
    size_t largeur = 400;
    size_t hauteur = 534;

    // allocation mémoire du vecteur de pixels
    pgm_t_pixel* vecteurPixel;

    // lecture de l'image format pgm
    vecteurPixel = pgm_naiveread("guadalest.pgm", &largeur, &hauteur);

    if (vecteurPixel == NULL) {
        return EXIT_FAILURE;
    }
    pgm_negative(vecteurPixel, largeur, hauteur);
    pgm_naivewrite("guadalest-negative.pgm", vecteurPixel, largeur, hauteur);
    pgm_threshold(vecteurPixel, largeur, hauteur, 200);
    pgm_naivewrite("guadalest-negative-threshold.pgm", vecteurPixel, largeur, hauteur);
    free(vecteurPixel);
    pgm_show("guadalest-negative.pgm");
    pgm_show("guadalest-negative-threshold.pgm");
    pgm_show("guadalest.pgm");

    // vérification de fuite mémoire : valgrind --leak-check=full ./traitement-image

    return EXIT_SUCCESS;
}