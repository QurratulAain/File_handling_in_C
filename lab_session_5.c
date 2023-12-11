// Question no.01: write a program to create a new text file and write some text into it.open the fie in append mode and add more text to  it.
//Read the contents of the file and display it on the console.
/*#include <stdio.h>
#include <stdlib.h>
int main(){
FILE *fptr;
fptr=fopen("lab5.txt","w");
if (fptr==NULL){
    printf("error opening file");
    return 1;}
fprintf(fptr, "It's Just Myself.\nTalking to myself, About myself.\n");
fclose(fptr);

fptr=fopen("lab5.txt","a");
if (fptr==NULL){
    printf("error opening file");
    return 1;
}
fprintf(fptr, "This line is appended to the file.\n");

fclose(fptr);
fptr=fopen("lab5.txt","r");
if (fptr==NULL){
    printf("error opening file");
    return 1;
}
char line[1000];
while(fgets(line,sizeof(line),fptr)!=NULL){
    printf("Read :%s",line);
}
fclose(fptr);

return 0;}*/
// Question no.02: Create a program that reads a text file and counts the number of words in it. Display the
// total number of words at the end.
/*int main(){
FILE *fptr;
fptr = fopen("lab5.txt", "r");
if (fptr == NULL) {
printf("Error opening file");
        return 1;
    }
    char lines[1000];
    int count = 0;
    while (fgets(lines, sizeof(lines), fptr) != NULL) {
        printf("Read: %s", lines);

        for (int i = 0; i < strlen(lines); i++) {
            if (lines[i] == ' ' ) {
                count += 1;}
        }count++;


    }
    fclose(fptr);
    printf("Word count: %d\n", count);
    return 0;
}*/
// Question no. 03: Implement a student database system using a file. Include features to add, delete, modify,
// and display student records.
/*#include <stdio.h>
#include <stdlib.h>
struct std{
    char name[100];
    int roll;
    float marks;
};
int main(){
    struct std*st=NULL;
    int count=0;
    int rollno;
    int rollnum;
FILE *fptr;
while(1){
    printf("\n***STUDENT DATABASE SYSTEM***\n");

    printf("\n1. ADD STUDENT\n");
    printf("\n2. VIEW STUDENT RECORDS \n");
    printf("\n3. DELETE STUDENT RECORDS \n");
    printf("\n4. MODIFY STUDENT RECORDS \n");
    printf("\n5. EXIT \n");
    printf("enter your choice");
    int choice;scanf("%d",&choice);
    switch(choice){
        case 1:
                count++;
                if (count == 1) {
                    st = (struct std*)malloc(count * sizeof(struct std));
                } else {
                    st = (struct std*)realloc(st, count * sizeof(struct std));
                }
                if (st == NULL) {
                    fprintf(stderr, "Memory allocation failed!\n");
                    return 1;
                }
                printf("Enter student details:\n");
                printf("Name: ");
                scanf("%s", st[count - 1].name);
                printf("Roll: ");
                scanf("%d", &st[count - 1].roll);
                printf("Marks: ");
                scanf("%f", &st[count - 1].marks);

                fptr = fopen("std.txt", "a");
                if (fptr == NULL) {
                    fprintf(stderr, "Error opening the file.\n");
                    return 1;
                }
                fprintf(fptr, "NAME: %s\n", st[count - 1].name);
                fprintf(fptr, "ROLL NO: %d\n", st[count - 1].roll);
                fprintf(fptr, "MARKS: %f\n", st[count - 1].marks);
                fclose(fptr);
                break;
            case 2:
                fptr = fopen("std.txt", "r");
                if (fptr == NULL) {
                    fprintf(stderr, "Error opening the file.\n");
                    return 1;
                }
                char line[1000];
                while (fgets(line, sizeof(line), fptr) != NULL) {
                    printf("%s", line);
                }
                fclose(fptr);
                break;
            case 3:
                printf("Enter the roll number of the student you want to delete: ");
                scanf("%d", &rollno);

                int index_ = -1;
                for (int i = 0; i < count; i++) {
                    if (st[i].roll == rollno) {
                        index_ = i;
                        break;
                    }
                }
                if (index_ != -1) {
                    for (int i = index_; i < count - 1; i++) {
                        strcpy(st[i].name, st[i + 1].name);
                        st[i].roll = st[i + 1].roll;
                        st[i].marks = st[i + 1].marks;
                    }
                    count--;
                    st = (struct std*)realloc(st, count * sizeof(struct std));
                    printf("Student with roll number %d deleted successfully!\n", rollno);

                    fptr = fopen("std.txt", "w");
                    if (fptr == NULL) {
                        fprintf(stderr, "Error opening the file.\n");
                        return 1;
                    }

                    for (int i = 0; i < count; i++) {
                        fprintf(fptr, "NAME: %s\n", st[i].name);
                        fprintf(fptr, "ROLL NO: %d\n", st[i].roll);
                        fprintf(fptr, "MARKS: %f\n", st[i].marks);
                    }

                    fclose(fptr);
                } else {
                    printf("Student with roll number %d not found.\n", rollno);
                }
                break;
            case 4:
                                printf("Enter the roll number of the student to modify: ");
                scanf("%d", &rollnum);

                int index = -1;
                for (int i = 0; i < count; i++) {
                    if (st[i].roll == rollnum) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    printf("Enter new details for the student:\n");
                    printf("Name: ");
                    scanf("%s", st[index].name);
                    printf("Roll: ");
                    scanf("%d", &st[index].roll);
                    printf("Marks: ");
                    scanf("%f", &st[index].marks);
                    printf("Student with roll number %d modified successfully!\n", rollnum);
                    fptr = fopen("std.txt", "w");
                    if (fptr == NULL) {
                        fprintf(stderr, "Error opening the file.\n");
                        return 1;
                    }
                    for (int i = 0; i < count; i++) {
                        fprintf(fptr, "NAME: %s\n", st[i].name);
                        fprintf(fptr, "ROLL NO: %d\n", st[i].roll);
                        fprintf(fptr, "MARKS: %f\n", st[i].marks);
                    }
                    fclose(fptr);
                } else {
                    printf("Student with roll number %d not found.\n", rollnum);
                }
                break;
            case 5:
                free(st);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}*/
