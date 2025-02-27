# DLL Student Roster Program
### Overview
This program allows users to manage a roster of students using a doubly linked list. The program supports adding student entries, 
deleting students by last name, and displaying the list of students in both forward and reverse order. It is implemented in C, utilizing 
structures (structs) and pointers to store and manipulate student data. Memory management is also handled using dynamic memory allocation 
and deallocation to ensure there are no memory leaks.

### Program Features
- Add Student: Prompt the user to input information about a student, including last name, first name, ID number, year, and expected
  graduation year. This information is stored in a dynamically allocated student struct, which is then added to the end of the doubly
  linked list.
- Delete Student by Last Name: The program allows the user to remove all students with a specific last name from the list. It properly
  handles cases where the first or last student in the list is deleted.
- Print List Forward: Print the list of students from the beginning to the end (head to tail of the doubly linked list).
- Print List Backward: Print the list of students from the end to the beginning (tail to head of the doubly linked list).
- Exit Program: The program will free all allocated memory before exiting to prevent memory leaks.

### Structure of the Program
Files in the Project:
- proj1.h: Header file declaring the student struct, function prototypes, and necessary includes.
- proj1.c: Contains the implementation of functions for managing the student list, including adding, deleting, and printing students.
- main.c: Contains the exicution of the code
- Makefile: Contains rules for compiling and linking the project. The target executable is named slist.

### User Interface
The program provides a simple text-based menu, which allows the user to select one of the following actions:
- Add Student: Add a new student to the list by providing the required information (last name, first name, student ID, year, expected graduation year).
- Delete Student(s): Remove all students with a specific last name from the list.
- Print List Forward: Display the student list from start to end (head to tail).
- Print List Backward: Display the student list from end to start (tail to head).
- Exit: Exit the program and ensure that all memory is freed before termination.

### Compilation and Execution
Once code is downloaded on eviorment set up for gcc, simple run the `make` command and then the exicutable `./slist`

### Acknowledgements
This project is part of the CISC361 course at the University of Delaware. The structure and approach used in this assignment are based on common
practices for handling linked lists in C.
