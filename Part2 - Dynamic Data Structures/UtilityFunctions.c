/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: implementation of utility functions
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

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

void resetNode(Node* n) {

	for (int i = 0; i < SEQUENCE_SIZE; i++) {

		n->sequence[i] = randomInt(0, 10);

	}

};

void printListOfNodes(Node* head) {

	Node* n = head;

	printNode(n);

	while (n->next != NULL) {
		
		n = n->next;

		printNode(n);

	}

}

void forEachNode(Node* head, void(*f)(Node* n)) {

	Node* n = head;

	(*f)(n);

	while (n->next != NULL) {

		n = n->next;

		(*f)(n);

	}

};

//void printRow(Row* r) {
//
//	// error handling
//	if (r == NULL) {
//
//		printf("Row ptr was NULL.\n");
//
//		return;
//
//	}
//
//	for (int i = 0; i < COLUMNS_NUMBER; i++) {
//
//		printf(" ");
//		printNode(r->nodes[i]);
//		printf(" |");
//	}
//};
//
//void printMatrix(Matrix* m) {
//
//	// error handling
//	if (m == NULL) {
//
//		printf("Matrix ptr was NULL.\n");
//
//		return;
//
//	}
//
//	//print a line
//	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
//	printf("\n");
//
//	//print column labels
//	printf("| \\ |");
//	for (int i = 1; i < COLUMNS_NUMBER * (SEQUENCE_SIZE + 3); i++) {
//
//		if ((i) % (SEQUENCE_SIZE + 3) == 0) {
//
//			printf("|");
//
//		}
//		else if ((i + SEQUENCE_SIZE) % (SEQUENCE_SIZE + 3) == 0) {
//
//			printf("%i", (i + SEQUENCE_SIZE) / (SEQUENCE_SIZE + 3));
//
//		}
//		else {
//
//			printf(" ");
//		}
//
//	}
//	printf("|\n");
//
//	for (int i = 0; i < ROWS_NUMBER; i++) {
//
//		printf("| %c |", 65 + i);
//		printRow(m->rows[i]);
//		printf("\n");
//	}
//
//	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
//
//	printf("\n");
//
//};

int randomInt(int min, int max) {

	return rand() % (max - min) + min;
};

//int validateOperation(Matrix* matrix) {
//
//	// error handling
//	if (matrix == NULL) {
//
//		printf("Matrix ptr was NULL.\n");
//
//		return -1;
//
//	}
//
//	int isValid = 0;
//
//	printf("Please validate the operation using your Matrix Card.\n");
//
//	for (int i = 0; i < SECURITY_LEVEL; i++) {
//
//		int row, col, digit, ans;
//		char rowChar;
//
//		row = randomInt(0, ROWS_NUMBER - 1);
//		col = randomInt(0, COLUMNS_NUMBER - 1);
//		digit = randomInt(0, SEQUENCE_SIZE - 1);
//
//		rowChar = 65 + row;
//
//		printf("Check %i out of %i.\n", i + 1, SECURITY_LEVEL);
//		printf("Please input the corresponding digit in the cell %c%i, position %i:\n", rowChar, col + 1, digit + 1);
//		printf("> ");
//
//		scanf("%i", &ans);
//		getchar();
//
//		isValid = validatePosition(ans, row, col, digit, matrix);
//
//		// break after one failed attempt
//		if (isValid == 0)
//			break;
//
//	}
//
//	return isValid;
//};
//
//int validatePosition(int ans, int row, int col, int digit, Matrix* matrix) {
//
//	if (matrix == NULL) {
//
//		printf("Matrix ptr was NULL.\n");
//		return 0;
//	}
//
//	if (ans > 9 || ans < 0) {
//
//		printf("'ans' is out of the range 0-9.\n");
//		return 0;
//
//	}
//
//	if (digit > 9 || digit < 0) {
//
//		printf("'digit' is out of the range 0-9.\n");
//		return 0;
//
//	}
//
//	if (row > ROWS_NUMBER || row < 0) {
//
//		printf("'row' is out of the range 0-ROWS_NUMBER.\n");
//		return 0;
//
//	}
//
//	if (col > COLUMNS_NUMBER || col < 0) {
//
//		printf("'col' is out of the range 0-COLUMNS_NUMBER.\n");
//		return 0;
//
//	}
//
//	// get the matrix digit in the given position
//	int matrixDigit = matrix->rows[row]->nodes[col]->sequence[digit];
//
//	if (matrixDigit == ans) {
//
//		return 1;
//
//	}
//	else {
//
//		return 0;
//
//	}
//
//};