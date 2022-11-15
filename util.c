#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_screen() {
   printf("Press any key to continue ");
   while ((getchar()) != '\n');
   getchar();
   system("clear");
}

void clear_file(char *filename) {
   FILE *file;
   file = fopen(filename, "w");
   fclose(file);
}

FILE *safe_fopen(char *filename, char modes[2]) {
   FILE *file;
   file = fopen(filename, modes);

   if (file == NULL) {
      printf("Error opening file\n");
      exit(1);
   }

   return file;
}
