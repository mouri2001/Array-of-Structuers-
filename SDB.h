#ifndef _SDB_h_ /* Guard File to avoid linker error*/
#define _SDB_h_

/* the includes */

#include <stdio.h>
#include "STD.h"

typedef struct{
    uint32 student_ID ;
    uint32 student_year;
    uint32 course1_ID;
    uint32 course1_grade;
    uint32 course2_ID;
    uint32 course2_grade;
    uint32 course3_ID;
    uint32 course3_grade;
}student;

/* Functions Delarations */

boolean SDB_IsFull (uint8*index); /* check if the array is full or not*/
void SDB_GetUsedSize(uint8 *count); /* get the used size in array */
boolean SDB_AddEntry(uint32 *ID); /* used to add new student in array*/
void SDB_DeleteEntry(uint32 *ID); /* used to delete a student from array*/
boolean SDB_ReadEntry(uint32 *ID); /* used to print specific data of any student*/
void SDB_GetList (uint8 *count , uint32 *list); /* counts how many students in array then print the IDs*/
boolean SDB_IsExist(uint32 *ID , uint8 *index); /* checks if the student is exist in array*/

void SDB_App(); /* makes the program running until user exit and scans the order of the user*/
void SDB_Action(uint8 *choise); /* takes the order and calls the function*/

void clear_screen(); /* to clear the terminal after any order  from user */

#endif