/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: implementation of utility functions
*/

#include <stdio.h>

#include "Types.h"
#include "UtilityFunctions.h"

void printLine(int size) {

	for (int i = 0; i < size; i++) {
		printf("-");
	}

}

void printNode(Node* n) {

	for (int i = 0; i < SEQUENCE_SIZE; i++) {

		printf("%i", n->sequence[i]);

	}

};

void printRow(Row* r) {
	
	for (int i = 0; i < COLUMNS_NUMBER; i++) {

		printf(" ");
		printNode(r->nodes[i]);
		printf(" |");
	}
};

void printMatrix(Matrix* m) {

	//print a line
	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	printf("\n");

	//print column labels
	printf("| \\ |");
	for (int i = 1; i < COLUMNS_NUMBER * (SEQUENCE_SIZE + 3); i++) {
		
		if((i) % (SEQUENCE_SIZE + 3) == 0) {
		
			printf("|");
		
		}
		else if((i + 3) % (SEQUENCE_SIZE + 3) == 0 ) {

			printf("%i", (i + 3) / (SEQUENCE_SIZE + 3));

		}
		else {

			printf(" ");
		}

	}
	printf("|\n");

	//print a line
	//printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	//printf("\n");

	for (int i = 0; i < ROWS_NUMBER; i++) {

		printf("| %c |", 65 + i);
		printRow(m->rows[i]);
		printf("\n");
	}
	
	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	
	printf("\n");
	
};

int randomInt(int min, int max) {

	int r = (rand() % max) + min;

	return r;
}

int validateOperation(Matrix* matrix) {

	int isValid = 0;

	for (int i = 0; i < SECURITY_LEVEL; i++) {

		int row, col, digit;
		char rowChar;

		row   = randomInt(0, ROWS_NUMBER);
		col   = randomInt(0, COLUMNS_NUMBER);
		digit = randomInt(0, SEQUENCE_SIZE);
		
		rowChar = 65 + row;

		printf("Please input the corresponding digit in the cell %c%i, position %i:\n", rowChar, col, digit + 1);
		printf("> ");

		//isValid = validatePosition(row, col, digit, matrix);

		if (isValid == 0) {

			printf("Wrong input. Canceling the transaction.\n");

			break;
			
		}

	}

	return isValid;

}
