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
	
	// error handling
	if (head == NULL) {

		printf("head node was null.\n");

		return -1;

	}

	if (ans > 9 || ans < 0) {

		printf("Ans out of range: %i (0-9)\n", ans);

		return -1;

	}

	if (row > ROWS_NUMBER - 1 || row < 0) {

		printf("Row out of range: %i (0-%i)\n", row, ROWS_NUMBER - 1);
		
		return -1;

	}

	if (col > COLUMNS_NUMBER - 1 || col < 0) {

		printf("Column out of range: %i (0-%i)\n", col, COLUMNS_NUMBER - 1);

		return -1;

	}

	if (pos > SEQUENCE_SIZE - 1 || row < 0) {

		printf("Position out of range: %i (0-%i)\n", row, SEQUENCE_SIZE - 1);

		return -1;

	}
	// end of error handling, assume all args are valid


	// current row being searched
	int cRow = 0;
	
	// current col being searched
	int cCol = 0;

	// count of searched nodes
	int i = 0;

	// loop exit flag
	int exit = 0;

	// current node
	Node* n = head;

	while (exit != 1) {

		// get the col and row arithmetically
		cCol = i % COLUMNS_NUMBER;
		cRow = i / COLUMNS_NUMBER;

		// if we reached the col and row of the args
		// it means we found the node were to search
		// the ans
		if (cRow == row && cCol == col) {

			// check pos in node and return result (0 or 1)
			if (n->sequence[pos] == ans) {

				return 1;

			}
			else {

				return 0;

			}

		}
		else {

			n = n->next;
			i++;

		}

		// break case.
		// if we reached this far, something went wrong
		// we searched all the nodes and the col and row
		// never matched the ones from the args.
		if (n == NULL) {

			exit = 1;

		}

	}

};