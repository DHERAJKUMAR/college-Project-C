#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
int id;
char name[50];
int age;
char disease[50];
struct Patient* prev;
struct Patient* next;
};

struct Patient* head = NULL;

// Check if ID already exists
int isIdUnique(int id) {
struct Patient* temp = head;
while (temp != NULL) {
if (temp->id == id)
return 0;
temp = temp->next;
}
return 1;
}

// Add patient at the end
void addPatient(int id, char name[], int age, char disease[]) {
if (!isIdUnique(id)) {
printf("Error: Patient ID %d already exists.\n", id);
return;
}

struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));  
newPatient->id = id;  
strcpy(newPatient->name, name);  
newPatient->age = age;  
strcpy(newPatient->disease, disease);  
newPatient->next = NULL;  
newPatient->prev = NULL;  

if (head == NULL) {  
    head = newPatient;  
} else {  
    struct Patient* temp = head;  
    while (temp->next != NULL)  
        temp = temp->next;  
    temp->next = newPatient;  
    newPatient->prev = temp;  
}  
printf("Patient added successfully.\n");

}

// Display forward
void displayForward() {
if (head == NULL) {
printf("No patients found.\n");
return;
}
struct Patient* temp = head;
printf("\n--- Patient List (Forward) ---\n");
while (temp != NULL) {
printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", temp->id, temp->name, temp->age, temp->disease);
temp = temp->next;
}
}

// Display backward
void displayBackward() {
if (head == NULL) {
printf("No patients found.\n");
return;
}
struct Patient* temp = head;
while (temp->next != NULL)
temp = temp->next;

printf("\n--- Patient List (Backward) ---\n");  
while (temp != NULL) {  
    printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", temp->id, temp->name, temp->age, temp->disease);  
    temp = temp->prev;  
}

}

// Search patient by ID
void searchPatient(int id) {
struct Patient* temp = head;
while (temp != NULL) {
if (temp->id == id) {
printf("\n--- Patient Found ---\n");
printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", temp->id, temp->name, temp->age, temp->disease);
return;
}
temp = temp->next;
}
printf("Patient with ID %d not found.\n", id);
}

// Delete patient by ID
void deletePatient(int id) {
struct Patient* temp = head;

while (temp != NULL) {  
    if (temp->id == id) {  
        if (temp->prev != NULL)  
            temp->prev->next = temp->next;  
        else  
            head = temp->next; // Deleting head  

        if (temp->next != NULL)  
            temp->next->prev = temp->prev;  

        free(temp);  
        printf("Patient with ID %d deleted successfully.\n", id);  
        return;  
    }  
    temp = temp->next;  
}  
printf("Patient with ID %d not found.\n", id);

}

int main() {
int choice, id, age;
char name[50], disease[50];

while (1) {  
    printf("\n--- Healthcare Record Menu ---\n");  
    printf("1. Add Patient\n");  
    printf("2. Display Patients (Forward)\n");  
    printf("3. Display Patients (Backward)\n");  
    printf("4. Search Patient by ID\n");  
    printf("5. Delete Patient by ID\n");  
    printf("6. Exit\n");  
    printf("Enter your choice: ");  
    scanf("%d", &choice);  

    switch (choice) {  
    case 1:  
        printf("Enter ID: ");  
        scanf("%d", &id);  
        printf("Enter Name: ");  
        scanf(" %[^\n]", name);  
        printf("Enter Age: ");  
        scanf("%d", &age);  
        printf("Enter Disease: ");  
        scanf(" %[^\n]", disease);  
        addPatient(id, name, age, disease);  
        break;  
    case 2:  
        displayForward();  
        break;  
    case 3:  
        displayBackward();  
        break;  
    case 4:  
        printf("Enter ID to search: ");  
        scanf("%d", &id);  
        searchPatient(id);  
        break;  
    case 5:  
        printf("Enter ID to delete: ");  
        scanf("%d", &id);  
        deletePatient(id);  
        break;  
    case 6:  
        printf("Exiting...\n");  
        exit(0);  
    default:  
        printf("Invalid choice. Try again.\n");  
    }  
}  
return 0;

}
