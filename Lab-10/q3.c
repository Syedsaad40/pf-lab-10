#include <stdio.h>
#include <string.h>

#define MAX_CARS 100
#define MAX_STRING_LENGTH 50

typedef struct {
    char make[MAX_STRING_LENGTH];
    char model[MAX_STRING_LENGTH];
    int year;
    float price;
    float mileage;
} Car;

Car dealership[MAX_CARS];
int carCount = 0;

void addCar() {
    if (carCount < MAX_CARS) {
        scanf("%s %s %d %f %f", dealership[carCount].make, dealership[carCount].model, &dealership[carCount].year, &dealership[carCount].price, &dealership[carCount].mileage);
        carCount++;
    }
}

void displayCars() {
    for (int i = 0; i < carCount; i++) {
        printf("%s %s %d %.2f %.2f\n", dealership[i].make, dealership[i].model, dealership[i].year, dealership[i].price, dealership[i].mileage);
    }
}

void searchCar() {
    char searchTerm[MAX_STRING_LENGTH];
    scanf("%s", searchTerm);
    for (int i = 0; i < carCount; i++) {
        if (strcmp(dealership[i].make, searchTerm) == 0 || strcmp(dealership[i].model, searchTerm) == 0) {
            printf("%s %s %d %.2f %.2f\n", dealership[i].make, dealership[i].model, dealership[i].year, dealership[i].price, dealership[i].mileage);
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add New Car\n2. Display Cars\n3. Search Car\n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) addCar();
        else if (choice == 2) displayCars();
        else if (choice == 3) searchCar();
    } while (choice != 4);
    return 0;
}
