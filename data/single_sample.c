typedef struct Employee {
    char name[50];
    int id;
    Address* address;   // Pointer to Address
    Company* company;   // Pointer back to Company
} Employee;