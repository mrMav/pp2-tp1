/*
author: Jorge Noro
date: 22/04/2018
purpose: pp2-tp1, part 2, dynamic data structures
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "CreationFunctions.h"
#include "UtilityFunctions.h"
#include "Matrix.h"

int main() {

	// seed for random numbers
	srand(time(NULL));   // should only be called once	

	Node* matrix = buildMatrix();
	
	// init program menu
	int option = -1;
	int exit = 1;

	while (exit) {

		printf("Matrix Card - Dynamic Data Structures\n");
		printf("0. Exit\n");
		printf("1. View Matrix\n");
		printf("2. Reset the Matrix\n");
		printf("3. Validate an operation\n");
		printf("4. Save matrix to file\n");
		printf("5. Load matrix from file\n");

		printLine(10);

		printf("> ");

		scanf("%i", &option);
		getchar();
		
		switch (option) {

			// 0 exits the program
		case 0:

			exit = 0;
			break;

			// 1 prints the matrix
		case 1:

			printMatrix(matrix);

			option = -1;
			break;

			// 2 generates a new matrix
		case 2:

			if (matrix == NULL) {

				matrix = buildMatrix();

			}
			else {

				resetMatrix(matrix);

			}

			option = -1;
			break;

			// 3 makes the user validate an operation
		case 3:
		{
			int isValid = validateOperation(matrix);

			if (isValid == 1) {

				printf("Operation is valid.\n");

			}
			else {

				printf("Wrong input, operation is cancelled!\n");

			}

			option = -1;
			break;
		}
			// allows to save matrix to file
		case 4:

			saveMatrix(matrix);

			option = -1;
			break;

			// allows to load matrix from file
		case 5:

			freeMatrix(&matrix);
			matrix = loadMatrix();

			option = -1;
			break;

			// 6 allows to check a digit in the given position (easter egg)
		case 6:
		{
			printLine(2);
			printf("Easter Egg Function! - Fetch Digit\n");
			printLine(2);

			char string[50];
			int digit;

			printf("Input sequence, format: \"[A-Z][0-9][0-9]\"\n");

			scanf("%s", string);
			getchar();

			digit = fetchDigit(string, matrix);

			printf("Fetched digit: %i.\n", digit);

			option = -1;
			break;
		}

		default:

			printf("Invalid selection. No action performed.\n");

		}

		printLine(10);

	}

	// cleanup
	freeMatrix(&matrix);

	return 0;
	
}