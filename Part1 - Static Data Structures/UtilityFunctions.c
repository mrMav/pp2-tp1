/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: implementation of utility functions
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#include "Types.h"
#include "UtilityFunctions.h"

void printLine(int size) {

	for (int i = 0; i < size; i++) {
		printf("-");
	}
	printf("\n");

};

void printNode(Node* n) {

	// error handling
	if (n == NULL) {
		
		printf("Node ptr was NULL.\n");

		return;

	}

	for (int i = 0; i < SEQUENCE_SIZE; i++) {

		printf("%i", n->sequence[i]);

	}

};

void printRow(Row* r) {

	// error handling
	if (r == NULL) {

		printf("Row ptr was NULL.\n");

		return;

	}

	for (int i = 0; i < COLUMNS_NUMBER; i++) {

		printf(" ");
		printNode(r->nodes[i]);
		printf(" |");
	}
};

void printMatrix(Matrix* m) {

	// error handling
	if (m == NULL) {

		printf("Matrix ptr was NULL.\n");

		return;

	}

	//print a line
	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));

	//print column labels
	printf("| \\ |");
	for (int i = 1; i < COLUMNS_NUMBER * (SEQUENCE_SIZE + 3); i++) {

		if ((i) % (SEQUENCE_SIZE + 3) == 0) {

			printf("|");

		}
		else if ((i + SEQUENCE_SIZE) % (SEQUENCE_SIZE + 3) == 0) {

			printf("%i", (i + SEQUENCE_SIZE) / (SEQUENCE_SIZE + 3));

		}
		else {

			printf(" ");
		}

	}
	printf("|\n");

	for (int i = 0; i < ROWS_NUMBER; i++) {

		printf("| %c |", 65 + i);
		printRow(m->rows[i]);
		printf("\n");
	}

	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));

};

int randomInt(int min, int max) {

	return rand() % (max - min) + min;
};

int validateOperation(Matrix* matrix) {

	// error handling
	if (matrix == NULL) {

		printf("Matrix ptr was NULL.\n");

		return -1;

	}

	int isValid = 0;

	printf("Please validate the operation using your Matrix Card.\n");

	for (int i = 0; i < SECURITY_LEVEL; i++) {

		int row, col, digit, ans;
		char rowChar;

		row = randomInt(0, ROWS_NUMBER - 1);
		col = randomInt(0, COLUMNS_NUMBER - 1);
		digit = randomInt(0, SEQUENCE_SIZE - 1);

		rowChar = 65 + row;

		printf("Check %i out of %i.\n", i + 1, SECURITY_LEVEL);
		printf("Please input the corresponding digit in the cell %c%i, position %i:\n", rowChar, col + 1, digit + 1);
		printf("> ");

		scanf("%i", &ans);
		getchar();

		isValid = validatePosition(ans, row, col, digit, matrix);

		// break after one failed attempt
		if (isValid == 0)
			break;

	}

	return isValid;
};

int validatePosition(int ans, int row, int col, int pos, Matrix* matrix) {

	if (matrix == NULL) {

		printf("Matrix ptr was NULL.\n");
		return 0;
	}

	if (ans > 9 || ans < 0) {

		printf("'ans' is out of the range 0-9.\n");
		return 0;

	}

	if (pos > 9 || pos < 0) {

		printf("'digit' is out of the range 0-9.\n");
		return 0;

	}

	if (row > ROWS_NUMBER || row < 0) {

		printf("'row' is out of the range 0-ROWS_NUMBER.\n");
		return 0;

	}

	if (col > COLUMNS_NUMBER || col < 0) {

		printf("'col' is out of the range 0-COLUMNS_NUMBER.\n");
		return 0;

	}

	// get the matrix digit in the given position
	int matrixDigit = matrix->rows[row]->nodes[col]->sequence[pos];

	if (matrixDigit == ans) {

		return 1;

	}
	else {

		return 0;

	}

};

int fetchDigit(char* string, Matrix* matrix) {

	if (strlen(string) > 3) {

		printf("String size not allowed. Format: \"[A-Z][1-9][1-9]\".\n");

		return -1;
	}

	int row, col, pos;
	char rowChar;

	col = string[1] - '0';
	pos = string[2] - '0';

	//printf("%i-%i\n", col, pos);

	if (toupper(string[0]) > 'Z') {

		printf("Row out of range. Format: \"[A-Z][0-9][0-9]\".\n");

		return -1;
	}

	if (col > 9 || col < 1) {

		printf("Column out of range. Format: \"[A-Z][0-9][0-9]\".\n");

		return -1;
	}

	if (pos > 9 || pos < 1) {

		printf("Position out of range. Format: \"[A-Z][0-9][0-9]\".\n");

		return -1;
	}
	
	printLine(2);
	
	rowChar = toupper(string[0]);
	row = rowChar - 65;

	if (row >= ROWS_NUMBER) {

		printf("Row out of range.\n");

		return -1;

	}

	printf("Fetching digit in %c%i-%i...\n", rowChar, col, pos);

	printLine(2);

	return matrix->rows[row]->nodes[col-1]->sequence[pos-1];

};