
#include <stdio.h>
#include"SBD.h"

static student database[MAX_STUDENTS];
static uint8 used_size = 0;

bool SDB_IsFull(void) {
    return (used_size >= MAX_STUDENTS);
}

uint8 SDB_GetUsedSize(void) {
    return used_size;
}

bool SDB_AddEntry(uint32 id, uint32 year, uint32 c1_id, uint32 c1_grade, uint32 c2_id, uint32 c2_grade, uint32 c3_id, uint32 c3_grade) {
    if (SDB_IsFull()) {
        return false;
    }
    database[used_size].Student_ID = id;
    database[used_size].Student_year = year;
    database[used_size].Course1_ID = c1_id;
    database[used_size].Course1_grade = c1_grade;
    database[used_size].Course2_ID = c2_id;
    database[used_size].Course2_grade = c2_grade;
    database[used_size].Course3_ID = c3_id;
    database[used_size].Course3_grade = c3_grade;
    used_size++;
    return true;
}

void SDB_DeleteEntry(uint32 id) {
    if (used_size <= 3) {
        printf("Cannot delete: Minimum 3 students required in the database.\n");
        return;
    }
    else { 
        printf("Student deleted (if ID was found).\n");  
    }
    
    for (uint8 i = 0; i < used_size; i++) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < used_size - 1; j++) {
                database[j] = database[j + 1];
            }
            used_size--;
            break;
        }
    }
}

bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < used_size; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return true;
        }
    }
    return false;
}

void SDB_GetList(uint8* count, uint32* list) {
    *count = used_size;
    for (uint8 i = 0; i < used_size; i++) {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < used_size; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}