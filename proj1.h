//Robert Koenig

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>

//student structure
typedef struct student {
	char *lastName;
	char *firstName;
	long idNum;
	char *grade;
	int gradYear;
	struct student *next;
	struct student *prev;
} student_t;

//creates new student structure
student_t *createStudent();

//adds student to linked list
void addStudent(student_t **first, student_t *newStudent);

//prints list from first to last
void printTopDown(student_t *first);

//prints list from last to first
void printBottomUp(student_t *last);

//removes target student
void removeStudent(student_t **first, char *name);

//deletes and deallocates starget student
void deallStudent(student_t *student);

//deletes and deallocates all students from linked list
void deallList(student_t **first);


#endif

