#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

struct sinfo {
    char fname[50];
    char lname[50];
    long int roll;
    float cgpa;
    int cid[5];  // Array to store up to 5 course IDs
} st[55];

// Function to add a student
void add_student() {
    printf("Add the Students Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of student: ");
    scanf("%s", st[i].fname);
    printf("Enter the last name of student: ");
    scanf("%s", st[i].lname);
    printf("Enter the Roll Number: ");
    scanf("%ld", &st[i].roll);
    printf("Enter the CGPA you obtained: ");
    scanf("%f", &st[i].cgpa);
    printf("Enter up to 5 course IDs: ");
    for (int j = 0; j < 5; j++) {
        printf("Course ID %d: ", j + 1);
        scanf("%d", &st[i].cid[j]);
    }
    i++;
}

// Function to print student details
void print_student_details(int index) {
    printf("The Students Details are:\n");
    printf("The First name is %s\n", st[index].fname);
    printf("The Last name is %s\n", st[index].lname);
    printf("The Roll Number is %ld\n", st[index].roll);
    printf("The CGPA is %f\n", st[index].cgpa);
    printf("The course IDs are:\n");
    for (int k = 0; k < 5; k++) {
        printf("%d\n", st[index].cid[k]);
    }
}

// Function to find a student by roll number
void find_rl() {
    int x;
    printf("Enter the Roll Number of the student: ");
    scanf("%d", &x);
    int flag = 0;
    for (int j = 0; j < i; j++) {
        if (x == st[j].roll) {
            print_student_details(j);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("The Roll Number is Not Found\n");
    }
}

// Function to find a student by first name
void find_fn() {
    char a[50];
    printf("Enter the First Name of the student: ");
    scanf("%s", a);
    int c = 0;
    for (int j = 0; j < i; j++) {
        if (!strcmp(st[j].fname, a)) {
            print_student_details(j);
            c = 1;
        }
    }
    if (c == 0) {
        printf("The First Name not Found\n");
    }
}

// Function to find students by course ID
void find_c() {
    int id;
    printf("Enter the course ID: ");
    scanf("%d", &id);
    int c = 0;
    for (int j = 0; j < i; j++) {
        for (int d = 0; d < 5; d++) {
            if (id == st[j].cid[d]) {
                print_student_details(j);
                c = 1;
            }
        }
    }
    if (c == 0) {
        printf("No students found for the given course ID\n");
    }
}

// Function to print the total number of students
void tot_s() {
    printf("The total number of Students is %d\n", i);
    printf("You can have a max of 50 students\n");
    printf("You can add %d more students\n", 50 - i);
}

// Function to delete a student by roll number
void del_s() {
    int a;
    printf("Enter the Roll Number which you want to delete: ");
    scanf("%d", &a);
    int flag = 0;
    for (int j = 0; j < i; j++) {
        if (a == st[j].roll) {
            for (int k = j; k < i - 1; k++) {
                st[k] = st[k + 1];
            }
            i--;
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        printf("The Roll Number is removed Successfully\n");
    } else {
        printf("The Roll Number is Not Found\n");
    }
}

// Function to update a student's data
void up_s() {
    printf("Enter the roll number to update the entry: ");
    int x;
    scanf("%d", &x);
    int flag = 0;
    for (int j = 0; j < i; j++) {
        if (st[j].roll == x) {
            printf("1. First name\n"
                   "2. Last name\n"
                   "3. Roll number\n"
                   "4. CGPA\n"
                   "5. Courses\n");
            int z;
            scanf("%d", &z);
            switch (z) {
                case 1:
                    printf("Enter the new first name: \n");
                    scanf("%s", st[j].fname);
                    break;
                case 2:
                    printf("Enter the new last name: \n");
                    scanf("%s", st[j].lname);
                    break;
                case 3:
                    printf("Enter the new roll number: \n");
                    scanf("%ld", &st[j].roll);
                    break;
                case 4:
                    printf("Enter the new CGPA: \n");
                    scanf("%f", &st[j].cgpa);
                    break;
                case 5:
                    printf("Enter the new courses \n");
                    for (int k = 0; k < 5; k++) {
                        scanf("%d", &st[j].cid[k]);
                    }
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            printf("UPDATED SUCCESSFULLY.\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("The Roll Number is Not Found\n");
    }
}

// Driver code
int main() {
    int choice;
    while (1) {
        printf("\nThe Task that you want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by Roll Number\n");
        printf("3. Find the Student Details by First Name\n");
        printf("4. Find the Student Details by Course Id\n");
        printf("5. Find the Total number of Students\n");
        printf("6. Delete the Students Details by Roll Number\n");
        printf("7. Update the Students Details by Roll Number\n");
        printf("8. To Exit\n");
        printf("Enter your choice to find the task: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_rl();
                break;
            case 3:
                find_fn();
                break;
            case 4:
                find_c();
                break;
            case 5:
                tot_s();
                break;
            case 6:
                del_s();
                break;
            case 7:
                up_s();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
