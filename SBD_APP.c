#include "SBD_APP.h"
#include "SBD.h"
#include <stdio.h>

void SDB_action(uint8 choice) {
    uint32 id, year, c1_id, c1_grade, c2_id, c2_grade, c3_id, c3_grade;
    uint8 count;
    uint32 list[MAX_STUDENTS];

    switch (choice) {
        case 1:
        if (SDB_IsFull()) {
                printf("Error: Cannot add more students. The database is full.\n");
                return;  
            }
            printf("Enter ID: ");
            scanf("%u",&id);
            if (SDB_IsIdExist(id)) {
                printf("Error: This ID has already been entered.\n");
                break;
            }
            printf("Year: ");
            scanf("%u",&year);
            printf("Course1 ID: ");
            scanf("%u",&c1_id);
            printf("Course1 Grade: ");
            scanf("%u",&c1_grade);
            printf("Course2 ID: ");
            scanf("%u",&c2_id);
            printf("Course2 Grade: ");
            scanf("%u",&c2_grade);
            printf("Course3 ID: ");
            scanf("%u",&c3_id);
            printf("Course3 Grade: ");
            scanf("%u",&c3_grade);
            if (SDB_AddEntry(id, year, c1_id, c1_grade, c2_id, c2_grade, c3_id, c3_grade)) {
                printf("Student added successfully.\n");
            } else {
                printf("Failed to add student.\n");
            }
            break;
        case 2:
            printf("Used Size: %u\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter ID:\n");
            scanf("%u", &id);
            if (!SDB_ReadEntry(id)) {
                printf("Student not found.\n");
            }
            break;
        case 4:
            SDB_GetList(&count, list);
            printf("Student IDs:\n");
            for (uint8 i = 0; i < count; i++) {
                printf("%u\n", list[i]);
            }
            break;
        case 5:
            printf("Enter ID:\n");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("ID exists.\n");
            } else {
                printf("ID does not exist.\n");
            }
            break;
        case 6:
            printf("Enter ID:\n");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 7:
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void SDB_APP(void) {
    uint8 choice;
    do {
        printf("Choose an option:\n1. Add Entry\n2. Get Used Size\n3. Read Student Data\n4. Get List of IDs\n5. Check ID Existence\n6. Delete Entry\n7. Check if Database is Full\n0. Exit\n");
        scanf("%hhu", &choice);
        SDB_action(choice);
    } while (choice != 0);
}