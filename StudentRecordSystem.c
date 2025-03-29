/* student_record.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *count) {
    if (*count >= 50) {
        printf("Database full!\n");
        return;
    }
    
    printf("Enter Roll No: ");
    scanf("%d", &students[*count].roll_no);
    printf("Enter Name: ");
    scanf("%s", students[*count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);
    
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", 
               students[i].roll_no, 
               students[i].name, 
               students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {
    int roll, found = 0;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);
    
    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n",
                   students[i].roll_no,
                   students[i].name,
                   students[i].marks);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student not found!\n");
    }
}

int main() {
    struct Student students[50];
    int count = 0, choice;
    
    printf("Student Record System\n");
    printf("----------------------\n");
    
    while (1) {
        printf("\n1. Add Student\n2. View All Students\n3. Search Student\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: searchStudent(students, count); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    
    return 0;
}