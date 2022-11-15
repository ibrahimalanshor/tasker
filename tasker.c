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
FILE *ftasks;
struct Task *tasks;
int tasks_length;

void sync_mem() {
   tasks = realloc(tasks, (tasks_length + 1) * sizeof(struct Task));

   if (tasks == NULL) {
      printf("Out of memoryn\n");
      exit(1);
   }
}

void sync_file() {
   clear_file("tasks.txt");
   ftasks = safe_fopen("tasks.txt", "a");

   for (int i = 0; i < tasks_length; i++) {
      fprintf(ftasks, "%d %s\n", !!(tasks + i)->done, (tasks + i)->name);
   }

   fclose(ftasks);
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
   ftasks = safe_fopen("tasks.txt", "r");

   int done;
   char name[20];

   while (fscanf(ftasks, "%d%s", &done, name) != EOF) {
      sync_mem();

      strcpy((tasks + tasks_length)->name, name);
      (tasks + tasks_length)->done = !!done;

      tasks_length++;
   }

   fclose(ftasks);
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

   tasks_length++;

   sync_file();

   printf("Task created succesfully\n");
}

void toggle_task() {
   system("clear");

   int selected_id = select_id();

   (tasks + (selected_id - 1))->done = !(tasks + (selected_id - 1))->done;
   
   sync_file();

   printf("Task updated successfully\n");
}

void edit_task() {
   system("clear");

   int selected_id = select_id();
   strcpy((tasks + (selected_id - 1))->name, input_name());

   sync_file();

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

   sync_file();

   printf("Task deleted successfully\n");
}
