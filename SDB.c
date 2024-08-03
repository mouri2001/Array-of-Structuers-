
/*  the used includes */

#include <stdio.h>
#include <stdlib.h> /* to use exit command */
#include "SDB.h"

/* define array to full the data in */
student array[SIZE];

/* 
**  the function that scans the input then sends the address of the choise to the next function using super loop preventing the ending of the code until the 
    user wants to
** i/p --> takes input ( choise ) from user
** o/p --> sends the address of the choise
*/

void SDB_App(){
    uint8 choise = 0;
    printf("Hello to our progam\n");
    while(1){
        printf("Please choose number from 0 to 7 \n");
        printf("0 --> exit the program , 1--> add entry , 2 --> get used size\n"
        "3 --> read data , 4 --> get list of IDs , 5 --> check if ID exists \n"
        "6 --> delete student , 7 --> check if the array is full\n");
        fflush(stdin);
        scanf("%d", &choise);
        clear_screen();
        if(choise >= 0 && choise <= 7){
            SDB_Action(&choise);
        }
        else{
            printf("Invalid choice\n");
            continue;
        }
        
    } 
}

/* 
** the function takes the choise and make switch case on the choises to call specific function 
** i/p --> the address of the choise 
** o/p --> calling the specific funtion I want
*/

void SDB_Action(uint8 *choise){
    uint32 ID = 0 , list [SIZE] = {0};
    uint8 index = 0 , count = 0;
    if ( *choise != 0 && *choise != 2 && *choise != 4 && *choise != 7 ){
        printf("Enter The ID you will use\n");
        while (scanf("%d", &ID) != 1 || ID == 0 ){
            printf("Invalid input, please enter your ID again\t");
            fflush(stdin);
        }
    }
    switch(*choise){
        case 0:
            printf("Exiting the program\n");
            exit(0);
        case 1:
            SDB_AddEntry(&ID)? printf("The data has been added successfully\n") : printf("The data hasn't been added ... Try again\n");
            break;
        case 2:
            SDB_GetUsedSize(&count);
            printf("Used size is %d\n", count );
            break;
        case 3:
            SDB_ReadEntry(&ID)? printf("The ID exists and the data has been printed\n") : printf("The ID isn't exist\n");
            break;
        case 4:
            SDB_GetList(&count , list );
            break;
        case 5:
            SDB_IsExist(&ID , &index) ? printf("The ID exists at Index = %d \n", index) : printf("The ID isn't exist\n");
            break;
        case 6:
            SDB_DeleteEntry(&ID);
            break;
        case 7:
            SDB_IsFull(&index) ? printf("The array is full\n") : printf("There is palce empty in the array at index = %d\n",index);
            break;
    }
}

/* 
** the function checks if the array is full or not 
** i/p --> the address of the index 
** o/p --> if it is full it returns true but, if it isn't full it returns false and the address of first empty place in the array 
*/

boolean SDB_IsFull ( uint8*index ){
    for ( int i = 0 ; i< SIZE ; i++){
        if ( array[i].student_ID == 0 ){
            *index = i ;
            return False;
        }
    }
    return True;
}

/* 
** the function checks on used size of the array 
** i/p --> no inputs 
** o/p --> returns the count of places used in the array
*/

void SDB_GetUsedSize(uint8 *count){
    for ( int i = 0 ; i< SIZE ; i++){
        if ( array[i].student_ID != 0 ){
            (*count)++;
        }
    }
}

/* 
** the function used to add new student if it found any place free in the array or the ID is = 0 
** i/p -->  no inputs
** o/p --> returns true if it was added successfully or false it wasn't added
*/

boolean SDB_AddEntry(uint32 *ID){
    uint8 index_A = 0 ;
    
    if ( SDB_IsFull(&index_A)){
        printf("The array is full\n");
        return False;
    }
    else if(SDB_IsExist(ID ,&index_A)){
        printf("The ID exists before at index = %d\n",index_A);
        return False;
    }
    array[index_A].student_ID = *ID ;
    
    printf("Please enter your studing year\t");
    while(scanf("%d", &array[index_A].student_year) != 1 ){
        printf("Please enter your studing year again\t");
        fflush(stdin);
    }

    printf("Please enter your course 1 ID\t");
    while(scanf("%d", &array[index_A].course1_ID) != 1){
        printf("Please enter your course 1 ID again\t");
        fflush(stdin);
    }

    printf("Please enter your course 1 grade\t");
    while(scanf("%d", &array[index_A].course1_grade) != 1){
        printf("Please enter your course 1 grade again\t");
        fflush(stdin);
    }

    printf("Please enter your course 2 ID\t");
    while(scanf("%d", &array[index_A].course2_ID) != 1){
        printf("Please enter your course 2 ID again\t");
        fflush(stdin);
    }

    printf("Please enter your course 2 grade\t");
    while(scanf("%d", &array[index_A].course2_grade) != 1){
        printf("Please enter your course 2 grade again\t");
        fflush(stdin);
    }
        
    printf("Please enter your course 3 ID\t");
    while(scanf("%d", &array[index_A].course3_ID) != 1){
        printf("Please enter your course 3 ID again\t");
        fflush(stdin);
    }

    printf("Please enter your course 3 grade\t");
    while(scanf("%d", &array[index_A].course3_grade) != 1){
        printf("Please enter your course 3 grade again\t");
        fflush(stdin);
    }
    
    return True ;
}

/* 
** the function deletes the data of specific student by making its address = 0 
** i/p -->  ID from user 
** o/p --> no outputs just print if it was deleted or not 
*/

void SDB_DeleteEntry(uint32 *ID){  
    uint8 index_D ;  
    if (SDB_IsExist(ID , &index_D)){
        array[index_D].student_ID = 0 ;
        printf("The Entry has been deleted successfully\n");
    }
    else printf("The Entry hasn't been found to delete\n");

}

/* 
** the function checks if the student exists in the array or not by checking the his ID 
** i/p -->  the address of the ID and index  
** o/p --> if its found return true and change the value of the index by puting the place (i) of the ID in the index , OR if not return false
*/

boolean SDB_IsExist(uint32 *ID , uint8 *index){
    for ( int i = 0 ; i < SIZE ; i++){
        if ( array[i].student_ID == *ID ){
            *index = i ;
            return True ;
        }
    }
    return False;
}

/* 
** the function reads specific data of any student using his ID
** i/p -->  the address of the ID
** o/p --> prints inside the function the data of the student then return true , if not found return false  
*/

boolean SDB_ReadEntry(uint32 *ID){
    uint8 index_R = 0 ;
    if(SDB_IsExist(ID , &index_R)){
        printf("Student ID = %d\n" , array[index_R].student_ID);
        printf("Student Year = %d\n" , array[index_R].student_year);
        printf("Course 1 ID = %d\n" , array[index_R].course1_ID);
        printf("Course 1 Grade = %d\n" , array[index_R].course1_grade);
        printf("Course 2 ID = %d\n" , array[index_R].course2_ID);
        printf("Course 2 Grade = %d\n" , array[index_R].course2_grade);
        printf("Course 3 ID = %d\n" , array[index_R].course3_ID);
        printf("Course 3 Grade = %d\n" , array[index_R].course3_grade);
        return True;
    }
    return False;

}

/* 
** the function get the count of how many IDs in the array and put the IDs in another array to print them
** i/p -->  address of the count and list 
** o/p --> just prints the count of the IDs and the IDs too 
*/

void SDB_GetList (uint8 *count , uint32 *list){

    for(int i = 0 ; i < SIZE ; i++){ 
        if (array[i].student_ID != 0){
            list[*count] = array[i].student_ID ;
            (*count)++ ;
        }
    }
    printf("There are %d IDs in The array\n",*count);
    for(int i = 0 ; i < SIZE ; i++){
        if(list[i] != 0){
            printf("The ID number %d = %d\n",i,list[i]);
        }
    }
}

/*
** It is onlu function to clera the terminal after any order from user 
*/

void clear_screen() {
    #ifdef _WIN32
        system("cls");  /* clear the terminal on Windows */
    #else
        system("clear"); /* clear the terminal on Unix-based systems (if your operating system isn't windows 🥰 ) */ 
    #endif
}