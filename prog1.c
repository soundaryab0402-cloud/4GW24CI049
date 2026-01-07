#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char dept[30];
    float salary;
};

struct Employee emp[100];
int count = 0;

void addEmployee() {
    printf("Enter ID: ");
    scanf("%d", &emp[count].id);
    printf("Enter Name: ");
    scanf("%s", emp[count].name);
    printf("Enter Department: ");
    scanf("%s", emp[count].dept);
    printf("Enter Salary: ");
    scanf("%f", &emp[count].salary);
    count++;
}

void displayEmployees() {
    for(int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nDept: %s\nSalary: %.2f\n",
        emp[i].id, emp[i].name, emp[i].dept, emp[i].salary);
    }
}

void searchEmployee() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++) {
        if(emp[i].id == id) {
            printf("Employee Found: %s\n", emp[i].name);
            found = 1;
        }
    }
    if(!found)
        printf("Employee not found!\n");
}

void deleteEmployee() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++) {
        if(emp[i].id == id) {
            emp[i] = emp[count - 1];
            count--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n1.Add Employee\n2.Display Employees\n3.Search Employee\n4.Delete Employee\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("Exiting..."); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}