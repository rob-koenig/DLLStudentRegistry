//Robert Koenig

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proj1.h"

#define BUFFERSIZE 128

/**
 * createStudent() function:
 * input: none
 * output: 1 student_t sruct
 * description: creates a student_t struct and prompts user for component values
 * special: this function allocates memory
 */
student_t *createStudent(){
	char buffer[BUFFERSIZE]; 
	int length;
	char *end;

	student_t *newStudent = (student_t *)malloc(sizeof(student_t));

	//asks user for student last name and allocates required memory
	printf("Enter student's last name: ");
	if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
        length = (int)strlen(buffer);
        buffer[length - 1] = '\0';
        newStudent->lastName = (char *)malloc(length);
        strcpy(newStudent->lastName, buffer);
    }

	//asks user for student first name and allocates required memory
	printf("Enter student's first name: ");
	if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
		length = (int)strlen(buffer);
		buffer[length - 1] = '\0'; 
		newStudent->firstName = (char *)malloc(length);
		strcpy(newStudent->firstName, buffer);
	}

	//asks user for student id number and checks that its an integer
	printf("Enter student's id number: ");
	while (1){
		if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
			length = (int)strtol(buffer, &end, 10);
			if (end == buffer || *end != '\n') {
            	printf("Please enter valid number: ");
        	} else {
            	newStudent->idNum = length;
				break;
        	}
		}
	}

	//asks user for student grade and allocates required memory
	printf("Enter student's graduation year (freshman, sophmore, junior, senior, grad student): ");
	if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
		length = (int)strlen(buffer);
		buffer[length - 1] = '\0'; 
		newStudent->grade = (char *)malloc(length);
		strcpy(newStudent->grade, buffer);
	}

	//asks user for student graduation year and checks that its an integer
	printf("Enter expected graduation year: ");
	while (1){
		if (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
			length = (int)strtol(buffer, &end, 10);
			if (end == buffer || *end != '\n') {
            	printf("Please enter valid number: ");
        	} else {
            	newStudent->gradYear = length;
				break;
        	}
		}
	}
	
	//assigns next and previous pointers to null
	newStudent->next = newStudent->prev = NULL;
    return newStudent;
}

/**
 * addStudent() function:
 * input: 1 pointer to first student pointer, 1 pointer to new student
 * output: none
 * description: adds the new student to the end of th list and assigns associated pointers
 * special: none
 */
void addStudent(student_t **first, student_t *newStudent){
	student_t *temp = *first;

	if (*first == NULL){
		*first = newStudent;
		return;
	}

	while (temp->next){
		temp = temp->next;
	}

	temp->next = newStudent;
	newStudent->prev = temp;
}

/**
 * printTopDown() function:
 * input: 1 pointer to first student
 * output: none
 * description: starts at the beginning of the list and prints through to the end
 * special: none
 */
void printTopDown(student_t *first){
	student_t *temp = first;

	while (temp){
		printf("%s, %s    ID %ld  %s  Graduating in %d\n", temp->lastName, temp->firstName, temp->idNum, temp->grade, temp->gradYear);
		temp = temp->next;
	}
}

/**
 * printBottomUp() function:
 * input: 1 pointer to first student
 * output: none
 * description: iterate to the end of the list, then print back up to the beginning
 * special: none
 */
void printBottomUp(student_t *first){
	student_t *temp = first;

	while (temp && temp->next){
		temp = temp->next;
	}

	while (temp){
		printf("%s, %s    ID %ld  %s  Graduating in %d\n", temp->lastName, temp->firstName, temp->idNum, temp->grade, temp->gradYear);
		temp = temp->prev;
	}
}

/**
 * removeStudent() function:
 * input: 1 pointer to first student pointer, 1 char pointer
 * output: none
 * description: iterate through list to target student, calls function to remove student if found
 * special: none
 */
void removeStudent(student_t **first, char *name){
	student_t *temp = *first;

	while(temp){
		if (strcmp(temp->lastName, name) == 0){
			if (!temp->prev){
				*first = temp->next;
				if (temp->next){
					temp->next->prev = NULL;
				}
			} else if (!temp->next){
				temp->prev->next = NULL;
			} else {
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
			}
			deallStudent(temp);
			return;
		}
		temp = temp->next;
	}
	printf("Student not found\n");
}

/**
 * deallStudent() function:
 * input: 1 pointer to student
 * output: none
 * description: deletes and deallocates memory of input student
 * special: this function deallocates memory
 */
void deallStudent(student_t *student){
	free(student->lastName);
	free(student->firstName);
	free(student->grade);
	student->next = NULL;
	student->prev = NULL;
	free(student);
}

/**
 * deallList() function:
 * input: 1 pointer to first studet pointer
 * output: none
 * description: deletes and deallocates memory of all students in list via deallStudent()
 * special: none
 */
void deallList(student_t **first){
	student_t *temp = *first;

	while (temp){
		*first = temp->next;
		deallStudent(temp);
		temp = *first;
	}

	*first = NULL;
}





