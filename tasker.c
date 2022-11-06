#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Task {
   char name[10];
   bool done;
};
struct Task tasks[5];
int tasks_length;

void display_task() {
   if (tasks_length < 1) {
      printf("Empty Tasks\n");
   } else {
      for (int i = 0; i < tasks_length; i++) {
         printf("%d. [%c] %s\n", i + 1, tasks[i].done ? 'x' : ' ', tasks[i].name);
      }
   }
}

void new_task() {
   char name[10];

   printf("Enter Name = ");
   scanf("%s", name);

   strcpy(tasks[tasks_length].name, name);
   tasks[tasks_length].done = false;

   tasks_length++;
}

int select_id() {
   int selected_id;

   printf("Select Id = ");
   scanf("%d", &selected_id);

   return selected_id;
}

void toggle_task() {
   int selected_id = select_id();

   tasks[selected_id - 1].done = !tasks[selected_id - 1].done;
}

void edit_task() {
   int selected_id = select_id();
   char name[10];

   printf("Enter Name = ");
   scanf("%s", name);

   strcpy(tasks[selected_id - 1].name, name);
}

void delete_task() {
   int selected_id = select_id();

   for (int i = selected_id - 1; i < tasks_length - 1; i++) {
      tasks[i] = tasks[i + 1];
   }

   tasks_length--;
}

int main() {
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
            break;
         case 2:
            new_task();
            break;
         case 3:
            toggle_task();
            break;
         case 4:
            edit_task();
            break;
         case 5:
            delete_task();
            break;
         default:
            printf("Invalid Menu\n");
            break;
      }
   }


   return 0;
}
