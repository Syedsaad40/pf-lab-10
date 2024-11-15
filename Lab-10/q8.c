#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    char department[50];
    float salary;
} Employee;

void inputEmployeeDetails(Employee *emp) {
    printf("Enter employee name: ");
    getchar(); 
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = 0;

    printf("Enter employee age: ");
    scanf("%d", &emp->age);

    printf("Enter employee department: ");
    getchar(); // consume newline character
    fgets(emp->department, sizeof(emp->department), stdin);
    emp->department[strcspn(emp->department, "\n")] = 0;

    printf("Enter employee salary: ");
    scanf("%f", &emp->salary);
}

void displayEmployeeDetails(Employee emp) {
    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        inputEmployeeDetails(&employees[i]);
    }

    printf("\n--- Employee Records ---\n");
    for (int i = 0; i < n; i++) {
        displayEmployeeDetails(employees[i]);
    }

    return 0;
}
