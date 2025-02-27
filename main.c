//Robert Koenig

#include <string.h>
#include "proj1.h"

#define BUFFERSIZE 128

/**
 * main() function:
 * input: none
 * output: 1 integer
 * description: main function
 * special: none
 */
int main(){
    student_t *first = NULL;
    char buffer[BUFFERSIZE];
    int choice;
    int length;

    while (1){
        printf("1: Add   2: Delete   3: Print  4: Reverse Print  5:Exit\n");
        printf("Enter action: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            //creates student
            case 1:
                addStudent(&first, createStudent());
                break;
            //removes student
            case 2:
                printf("Enter name to be removed: ");
                char name[BUFFERSIZE];
                if (fgets(buffer, BUFFERSIZE , stdin) != NULL){
                    length = (int) strlen(buffer);
                    buffer[length - 1] = '\0';
                    strcpy(name, buffer);
                }
                removeStudent(&first, name);
                break;
            //prints top down
            case 3:
                printTopDown(first);
                break;
            //prints bottom up
            case 4:
                printBottomUp(first);
                break;
            //deletes list on exit
            case 5:
                deallList(&first);
                return 0;
            //default for invalid commands
            default:
                printf("Invalid Command\n");
		break;
        }
    }
    return 1;
}
