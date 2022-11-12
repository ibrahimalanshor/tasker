#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct Task {
   char name[20];
   bool done;
};
struct Task tasks[5];
int tasks_length;

int select_id() {
   int selected_id;

   printf("Select Id = ");
   scanf("%d", &selected_id);

   if (selected_id < 1 || selected_id > tasks_length) {
      printf("Out of length\n");
      exit(1);
   }

   return selected_id;
}

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

void display_task() {
   system("clear");

   if (tasks_length < 1) {
      printf("Empty Tasks\n");
   } else {
      for (int i = 0; i < tasks_length; i++) {
         printf("%d. [%c] %s\n", i + 1, tasks[i].done ? 'x' : ' ', tasks[i].name);
      }
   }
}

void new_task() {
   system("clear");

   strcpy(tasks[tasks_length].name, input_name());
   tasks[tasks_length].done = false;

   tasks_length++;

   printf("Task created succesfully\n");
}

void toggle_task() {
   system("clear");

   int selected_id = select_id();

   tasks[selected_id - 1].done = !tasks[selected_id - 1].done;

   printf("Task updated successfully\n");
}

void edit_task() {
   system("clear");

   int selected_id = select_id();
   strcpy(tasks[selected_id - 1].name, input_name());

   printf("Task updated successfully\n");
}

void delete_task() {
   system("clear");

   int selected_id = select_id();

   for (int i = selected_id - 1; i < tasks_length - 1; i++) {
      tasks[i] = tasks[i + 1];
   }

   tasks_length--;

   printf("Task deleted successfully\n");
}

int main() {
   system("clear");

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
