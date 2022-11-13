#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input_name() {
   char *str;
   char buff[20];

   printf("Enter name = ");
   while ((getchar()) != '\n');
   
   if (fgets(buff, sizeof(buff), stdin) == NULL) {
      printf("Out of stream\n");
      exit(1);
   }

   str = malloc(sizeof(buff));

   if (str == NULL) {
      printf("Out of memory\n");
      exit(1);
   } else {
      buff[strlen(buff) - 1] = '\0';
   }

   strcpy(str, buff);
   
   return str;
}

void clear_screen() {
   printf("Press any key to continue ");
   while ((getchar()) != '\n');
   getchar();
   system("clear");
}
