#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"file.h"
int main() {
   printf("1. Read From File\n");
   printf("2. Write To File\n");
   printf("Enter your choice: ");
   int choice;
   scanf("%d", &choice);
   char filename1[1000];
char filename[1000];
   switch (choice) {
      case 1:
         printf("Enter a file name to read from it: ");
         scanf("%s", filename);
         printf("Read from file: %s\n", filename);
         int c = CheckingFile(filename);
         if (c) {
            ReadFromFile(filename);
         }
         break;
      case 2:
         printf("Enter a file name to write to it: ");
         scanf("%s", filename1);
         printf("Write to file: %s\n", filename1);
         int ch = CheckingFile(filename1);

         char content[1000];
         if (ch) {
            printf("Enter the content to write to the file: ");
            getchar(); // Consume the newline character left by the previous scanf
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = '\0'; // Remove the trailing newline character
            WriteToFile(filename1, content);
         }
         break;
      default:
         printf("Option not found.\n");
         return 1;
   }

   return 0;
}