#include <stdio.h>
#include <string.h>

typedef struct {
    char packagename[50];
    char destination[50];
    int duration;
    int numberofseats; 
    float cost;
} travel;

travel packages[100];
int packagecount = 0;

void addPackage() {
    if (packagecount >= 100) {
        printf("Cannot add more packages. Limit reached.\n");
        return;
    }
    printf("Enter package name: ");
    getchar(); 
    fgets(packages[packagecount].packagename, sizeof(packages[packagecount].packagename), stdin);
    packages[packagecount].packagename[strcspn(packages[packagecount].packagename, "\n")] = 0;

    printf("Enter destination: ");
    fgets(packages[packagecount].destination, sizeof(packages[packagecount].destination), stdin);
    packages[packagecount].destination[strcspn(packages[packagecount].destination, "\n")] = 0; 

    printf("Enter duration (days): ");
    scanf("%d", &packages[packagecount].duration);
    printf("Enter cost: ");
    scanf("%f", &packages[packagecount].cost);
    printf("Enter number of seats available: ");
    scanf("%d", &packages[packagecount].numberofseats);
    
    packagecount++;
    printf("Package added successfully!\n");
}

void displayPackages() {
    if (packagecount == 0) {
        printf("No travel packages available.\n");
        return;
    }
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < packagecount; i++) {
        printf("Package Name: %s\n", packages[i].packagename);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].numberofseats);
        printf("----------------------\n");
    }
}

void bookPackage() {
    char packageName[50];
    printf("Enter the package name to book: ");
    getchar();
    fgets(packageName, sizeof(packageName), stdin);
    packageName[strcspn(packageName, "\n")] = 0; // Remove newline
    
    for (int i = 0; i < packagecount; i++) {
        if (strcmp(packages[i].packagename, packageName) == 0) {
            if (packages[i].numberofseats > 0) {
                packages[i].numberofseats--;
                printf("Package '%s' booked successfully! Seats left: %d\n", packageName, packages[i].numberofseats);
                return;
            } else {
                printf("Sorry, no seats available for '%s'.\n", packageName);
                return;
            }
        }
    }
    printf("Package '%s' not found.\n", packageName);
}

int main() {
    int choice;
    do {
        printf("\nTravel Package Management System\n");
        printf("1. Add Travel Package\n");
        printf("2. Display Available Packages\n");
        printf("3. Book a Package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPackage();
                break;
            case 2:
                displayPackages();
                break;
            case 3:
                bookPackage();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
