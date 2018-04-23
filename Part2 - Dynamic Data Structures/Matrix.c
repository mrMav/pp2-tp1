/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: functions to manipulate the matrix (linked list)
*/

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "Matrix.h"
#include "UtilityFunctions.h"
#include "CreationFunctions.h"

Node* buildMatrix() {

	Node* head = createNode();
	Node* tail = NULL;

	for (int i = 0; i < COLUMNS_NUMBER * ROWS_NUMBER; i++) {

		tail = addNode(head);

	}

	return head;

};

void resetMatrix(Node* head) {

	forEachNode(head, resetNode);

}

void printMatrix(Node* head) {

	// error handling
	if (head == NULL) {

		printf("head ptr was NULL.\n");

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

	Node* n = head;
	int i = 0, row = 0;
	int printRowLetter = 1;
	
	while (n->next != NULL) {
		
		if (printRowLetter) {

			printf("| %c |", 65 + row);
			printRowLetter = 0;
		}

		printf(" ");
		printNode(n);
		printf(" |");


		n = n->next;

		i++;

		if ((i % COLUMNS_NUMBER) == 0) {

			printf("\n");
			row++;
			printRowLetter = 1;

		}

	}

	printLine(5 + COLUMNS_NUMBER * (SEQUENCE_SIZE + 3));
	
};

int validatePosition(int ans, int row, int col, int pos, Node* head) {
	
	// current row and column being searched
	int cRow = 0, cCol = 0;
	int exit = 0, i = 0;

	Node* n = head;

	while (exit != 1) {

		cCol = i % COLUMNS_NUMBER;
		cRow = i / COLUMNS_NUMBER;

		if (cRow == row && cCol == col) {

			// check pos in node and return result (0 or 1)
			printf("Found your pretty node... here it is: ");
			printNode(n);
			printf("\n");

			exit = 1;

		}
		else {

			n = n->next;
			i++;

		}

		if (n == NULL) {

			exit = 1;

		}


	}

};