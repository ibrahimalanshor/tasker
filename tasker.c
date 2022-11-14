#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tasker.h"
#include "util.h"

struct Task {
   char name[20];
   bool done;
};
FILE *ftask;
struct Task *tasks;
int tasks_length;

void sync_mem() {
   tasks = realloc(tasks, (tasks_length + 1) * sizeof(struct Task));

   if (tasks == NULL) {
      printf("Out of memoryn\n");
      exit(1);
   }
}

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

void load_task() {
   ftask = fopen("tasks.txt", "a+");

   if (ftask == NULL) {
      printf("Error reading file\n");
      exit(1);
   }

   int done;
   char name[20];

   while (fscanf(ftask, "%d%s", &done, name) != EOF) {
      sync_mem();

      strcpy((tasks + tasks_length)->name, name);
      (tasks + tasks_length)->done = !!done;

      tasks_length++;
   }
}

void display_task() {
   system("clear");

   if (tasks_length < 1) {
      printf("Empty Tasks\n");
   } else {
      for (int i = 0; i < tasks_length; i++) {
         printf("%d. [%c] %s\n", i + 1, (tasks + i)->done ? 'x' : ' ', (tasks + i)->name);
      }
   }
}

void new_task() {
   system("clear");
   sync_mem();

   strcpy((tasks + tasks_length)->name, input_name());
   (tasks + tasks_length)->done = false;

   fprintf(ftask, "%d %s\n", (tasks + tasks_length)->done ? 1 : 0, (tasks + tasks_length)->name);

   tasks_length++;

   printf("Task created succesfully\n");
}

void toggle_task() {
   system("clear");

   int selected_id = select_id();

   (tasks + (selected_id - 1))->done = !(tasks + (selected_id - 1))->done;

   printf("Task updated successfully\n");
}

void edit_task() {
   system("clear");

   int selected_id = select_id();
   strcpy((tasks + (selected_id - 1))->name, input_name());

   printf("Task updated successfully\n");
}

void delete_task() {
   system("clear");

   int selected_id = select_id();

   for (int i = selected_id - 1; i < tasks_length - 1; i++) {
      strcpy((tasks + i)->name, (tasks + i + 1)->name);
      (tasks + i)->done = (tasks + i + 1)->done;
   }

   tasks_length--;

   printf("Task deleted successfully\n");
}
