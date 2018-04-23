/*
author: Jorge Noro
date: 18/04/2018
purpose: pp2-tp1, part 1, static data structures
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "CreationFunctions.h"
#include "UtilityFunctions.h"

int main() {

	// seed for random numbers
	srand(time(NULL));   // should only be called once
	
	Matrix* matrix = createMatrix();  //creates and fills a card with random numbers
	
	// init program menu
	int option = 0;
	int exit = 1;

	while (exit) {

		printf("Matrix Card - Static Data Structures\n");
		printf("0. Exit\n");
		printf("1. View Matrix\n");
		printf("2. Generate a new Matrix\n");
		printf("3. Validate an operation\n");
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
			break;

			// 2 generates a new matrix
		case 2:

			matrix = createMatrix();
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

				break;
			}

			// 4 allows to check a digit in the given position (easter egg)
		case 4:
		{
			char string[50];
			int digit;

			printf("Input sequence, format: \"[A-Z][0-9][0-9]\"\n");

			scanf("%s", string);
			getchar();

			digit = fetchDigit(string, matrix);

			printf("Fetched digit: %i.\n", digit);

			break;
		}

		}

		printLine(10);

	}

	// cleanup
	freeMatrix(&matrix);

	return 0;

}