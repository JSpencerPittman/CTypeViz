#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for Address
typedef struct {
    char street[50];
    char city[30];
    char state[3];  // e.g., "CA"
    int zip;
} Address;

// Forward declare struct Employee for use in Company
struct Employee;

// Define a struct for Company
typedef struct {
    char name[50];
    struct Employee* employees;
    int num_employees;
} Company;

// Define a struct for Employee
typedef struct Employee {
    char name[50];
    int id;
    Address* address;   // Pointer to Address
    Company* company;   // Pointer back to Company
} Employee;

int main() {
    // Allocate a company
    Company myCompany;
    strcpy(myCompany.name, "TechCorp");
    myCompany.num_employees = 2;
    myCompany.employees = malloc(myCompany.num_employees * sizeof(Employee));

    // Create shared addresses
    Address hq = { "123 Tech St", "Silicon Valley", "CA", 94043 };

    // Fill in employee data
    for (int i = 0; i < myCompany.num_employees; i++) {
        snprintf(myCompany.employees[i].name, 50, "Employee %d", i + 1);
        myCompany.employees[i].id = 1000 + i;
        myCompany.employees[i].address = &hq;              // Shared address
        myCompany.employees[i].company = &myCompany;        // Back-pointer
    }

    // Print company and employee info
    printf("Company: %s\n", myCompany.name);
    for (int i = 0; i < myCompany.num_employees; i++) {
        Employee* e = &myCompany.employees[i];
        printf("Employee: %s, ID: %d, City: %s\n", e->name, e->id, e->address->city);
    }

    // Free memory
    free(myCompany.employees);

    return 0;
}
