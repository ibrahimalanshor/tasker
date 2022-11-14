#include <stdio.h>
#include <stdlib.h>
#include "tasker.h"
#include "util.h"

int main() {
   system("clear");

   load_task();

   while (1) {  
      int selected_menu;

      printf("Menu List:\n1. Display Tasks\n2. New Task\n3. Toggle Done\n4. Edit Task\n5. Delete Task\n6. Exit\n");
      printf("Select Menu = ");

      scanf("%d", &selected_menu);

      if (selected_menu == 6) {
         break;
      }

      switch (selected_menu) {
         case 1:
            display_task();
            clear_screen();

            break;
         case 2:
            new_task();
            clear_screen();

            break;
         case 3:
            toggle_task();
            clear_screen();

            break;
         case 4:
            edit_task();
            clear_screen();

            break;
         case 5:
            delete_task();
            clear_screen();

            break;
         default:
            system("clear");
            printf("Invalid Menu\n");
            clear_screen();

            break;
      }
   }


   return 0;
}
