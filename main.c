#include <stdio.h>
#define COMMAND_AMOUNT 6
#define ARRAY_AMOUNT 3
#include "array_output.h"
#include "array_functionalities.h"
#include "array_input.h"


int main() {
    setbuf(stdout, NULL);
	char command;
    char str_command[50];
	int lengths[ARRAY_AMOUNT], arrayNumber, index, element, lowerBound, highBound;
	int *arrays[ARRAY_AMOUNT];

    for (int i = 0; i < ARRAY_AMOUNT; ++i) {
        arrays[i] = NULL;
        lengths[i] = -1;
    }
    printCommandMessage();
	while (1) { // main loop
        if (inputCommand(str_command)) {
            freeArrays(arrays);
            return 1;
        }
        command = str_command[0];
		switch (command) {
			case 'h':
				printCommandMessage();
                break;
            case 'i':
                if (arrayNumberInput(&arrayNumber)) break; // array num input, check

                if (arrays[arrayNumber] != NULL) {
                    free(arrays[arrayNumber]); // reinitialise array
                }
                if (lengthInput(lengths + arrayNumber)) break; // &length[0] - input len
                arrays[arrayNumber] = input(lengths[arrayNumber]);
                if (arrays[arrayNumber] == NULL && lengths[arrayNumber]) {
                    freeArrays(arrays);
                    return 1;
                }
				break;
            case 'r':
                if (arrayNumberInput(&arrayNumber)) break; // array num input, check

                if (arrays[arrayNumber] != NULL) {
                    free(arrays[arrayNumber]); // reinitialise array
                }
                if (randDataInput(lengths + arrayNumber, &lowerBound, &highBound)) break; // &length[0] - input len
                arrays[arrayNumber] = generateRandomArray(lengths[arrayNumber], lowerBound, highBound);
                if (arrays[arrayNumber] == NULL) {
                    freeArrays(arrays);
                    return 1;
                }
                break;
			case 'p': // print array
                if (arrayNumberInput(&arrayNumber)) break; // array num input, check
                if (arrays[arrayNumber] == NULL) {
                    if (!lengths[arrayNumber]) {
                        printf("array #%d is empty\n", arrayNumber);
                    }
                    else
                        printf("array #%d not defined\n", arrayNumber);
                    break;
                }
				printArr(arrays[arrayNumber], lengths[arrayNumber]);
				break;
            case 'c':
                if (arrayNumberInput(&arrayNumber)) break; // array num input, check
                if (arrays[arrayNumber] == NULL) {
                    printf("array #%d not defined\n", arrayNumber);
                    break;
                }
                if (indexInputForInsert(&index, lengths[arrayNumber])) break;
                puts("Input element: ");
                if (check_int(&element)) break;
                arrays[arrayNumber] = insertElementById(index, element, arrays[arrayNumber], lengths+arrayNumber);
                if (arrays[arrayNumber] == NULL) {
                    freeArrays(arrays);
                    return 1;
                }
				break;
            case 'd': // delite element by ID
                if (arrayNumberInput(&arrayNumber)) break; // array num input, check
                if (arrays[arrayNumber] == NULL) {
                    if (!lengths[arrayNumber]) {
                        printf("array #%d is empty\n", arrayNumber);
                    }
                    else {
                        printf("array #%d not defined\n", arrayNumber);
                    }
                    break;
                }
                if (indexInput(&index, lengths[arrayNumber])) break;
                arrays[arrayNumber] = deleteElementById(index, arrays[arrayNumber], lengths+arrayNumber);
                if (arrays[arrayNumber] == NULL && lengths[arrayNumber]) {
                    freeArrays(arrays);
                    return 1;
                }
                break;
            case 'w': // data processing
                ;
                int arrayNumber1, arrayNumber2, arrayNumberRes;
                if (arrayNumberInput(&arrayNumber1)) break; // array 1 num input, check
                if (arrayNumberInput(&arrayNumber2)) break; // array 2 num input, check
                if (arrayNumberInput(&arrayNumberRes)) break; // res array num input, check
                free(arrays[arrayNumberRes]);
                arrays[arrayNumberRes] = dataProcessing(arrays + arrayNumber1, arrays + arrayNumber2, lengths + arrayNumber1, lengths + arrayNumber2, lengths + arrayNumberRes);
                if (arrays[arrayNumberRes] == NULL && lengths[arrayNumberRes]) {
                    freeArrays(arrays);
                    return 1;
                }
                break;
			case 'q': // quit
                freeArrays(arrays);
				return 0;
			default:
				printf("Incorrect command.\n");
		}
	}
    freeArrays(arrays);
	return 0;
}
