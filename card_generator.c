#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo.h>
#include <cairo-ft.h>
#include <ft2build.h>

#include FT_FREETYPE_H

#define BACKGROUND_IMG_PATH "card-background.png"
#define FONT_PATH "arial.ttf"
#define OUTPUT_DIR_PATH "output"
#define NAMES_FILE_PATH "names.txt"
#define FONT_SIZE 130
#define TEXT_COLOR_R 0.0
#define TEXT_COLOR_G 0.45
#define TEXT_COLOR_B 0.37

void ReadNames(char ***names, int *count) {
    FILE *file = fopen(NAMES_FILE_PATH, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    *count = 0;
    *names = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        for (char *p = buffer; *p; ++p) {
            if (*p == '\t') *p = ' ';
        }

        *names = realloc(*names, (*count + 1) * sizeof(char *));
        (*names)[*count] = strdup(buffer);
        (*count)++;
    }
    fclose(file);
}

void CardFileName(char *name, char *output_filename) {
    sprintf(output_filename, "%s/card-%s.png", OUTPUT_DIR_PATH, name);

    for (int i = 0; output_filename[i]; i++) {
        if (output_filename[i] == ' ') {
            output_filename[i] = '-';
        }
    }
}

void DesignCard(char *name) {
    cairo_surface_t *surface = cairo_image_surface_create_from_png(BACKGROUND_IMG_PATH);
    cairo_t *cr = cairo_create(surface);

    cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, FONT_SIZE);

    cairo_text_extents_t extents;
    cairo_text_extents(cr, name, &extents);
    double x = (cairo_image_surface_get_width(surface) - extents.width) / 2;
    double y = 840;

    cairo_set_source_rgb(cr, TEXT_COLOR_R, TEXT_COLOR_G, TEXT_COLOR_B);
    cairo_move_to(cr, x, y);
    cairo_show_text(cr, name);

    char output_filename[256];
    CardFileName(name, output_filename);
    cairo_surface_write_to_png(surface, output_filename);

    printf("%s generated\n", output_filename);

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}

void CreateCards(char **names, int count) {
    struct stat st = {0};
    if (stat(OUTPUT_DIR_PATH, &st) == -1) {
        mkdir(OUTPUT_DIR_PATH, 0700);
    }

    for (int i = 0; i < count; i++) {
        DesignCard(names[i]);
        free(names[i]);
    }

    free(names);
}

int main() {
    char **names;
    int name_count;

    ReadNames(&names, &name_count);

    CreateCards(names, name_count);

    return 0;
}