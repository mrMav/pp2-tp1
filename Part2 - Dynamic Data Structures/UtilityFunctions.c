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

	if (n == NULL) {

		return;

	}

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

void forEachNode(Node* head, void(*callback)(Node* n)) {

	Node* n = head;

	int exit = 0;
	
	while (exit == 0) {

		(*callback)(n);
		
		n = n->next;

		if (n == NULL) {

			exit = 1;

		}

	}

};

int randomInt(int min, int max) {

	return rand() % (max - min) + min;
};

int fetchDigit(char* string, Node* head) {

	if (strlen(string) > 3) {

		printf("String size not allowed. Format: \"[A-Z][1-9][1-9]\".\n");
		return -1;
	}

	int row, col, pos;
	char rowChar;

	col = string[1] - '0';
	pos = string[2] - '0';
	
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

	int cRow = 0;
	int cCol = 0;
	int i = 0;
	int exit = 0;

	Node* n = head;

	while (exit != 1) {

		cCol = (i % COLUMNS_NUMBER) + 1;
		cRow = (i / COLUMNS_NUMBER);

		//printf("Row: %i, Col: %i (looking for %i, %i)\n", cRow, cCol, row, col);

		if (cRow == row && cCol == col) {

			return n->sequence[pos-1];

		}
		else {

			n = n->next;
			i++;

		}

		if (n == NULL) {

			exit = 1;

		}

	}

	return -1;

};