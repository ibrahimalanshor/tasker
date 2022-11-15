#include <stdio.h>

char *input_name();
void clear_screen();
void clear_file(char *filename);
FILE *safe_fopen(char *filename, char modes[2]);