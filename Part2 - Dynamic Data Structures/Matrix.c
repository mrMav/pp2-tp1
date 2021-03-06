/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: functions to manipulate the matrix (linked list)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "Matrix.h"
#include "UtilityFunctions.h"
#include "CreationFunctions.h"

Node* buildMatrix() {

	Node* head = createNode();
	Node* tail = NULL;

	for (int i = 0; i < COLUMNS_NUMBER * ROWS_NUMBER - 1; i++) {

		tail = addNode(head, NULL);

	}

	return head;

};

void resetMatrix(Node* head) {

	if (head == NULL) {

		printf("head ptr was NULL.\n");
		return;

	}

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
	int i = 1, row = 0;
	int printRowLetter = 1;
	int exit = 0;

	while (exit == 0) {
		
		if (printRowLetter) {

			printf("| %c |", 65 + row);
			printRowLetter = 0;
		}

		printf(" ");
		printNode(n);
		printf(" |");

		if ((i % COLUMNS_NUMBER) == 0) {

			printf("\n");
			row++;
			printRowLetter = 1;

		}

		n = n->next;
		i++;

		if (n == NULL) {
			exit = 1;
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

	return -1;

};

int validateOperation(Node* head) {

	// error handling
	if (head == NULL) {

		printf("Head ptr was NULL.\n");
		return -1;

	}

	int isValid = 0;

	printf("Please validate the operation using your Matrix Card.\n");

	for (int i = 0; i < SECURITY_LEVEL; i++) {

		int row, col, digit, ans;
		char rowChar;

		row = randomInt(0, ROWS_NUMBER);
		col = randomInt(0, COLUMNS_NUMBER);
		digit = randomInt(0, SEQUENCE_SIZE);

		rowChar = 65 + row;

		printf("Check %i out of %i.\n", i + 1, SECURITY_LEVEL);
		printf("Please input the corresponding digit in the cell %c%i, position %i:\n", rowChar, col + 1, digit + 1);
		printf("> ");

		scanf("%i", &ans);
		getchar();

		isValid = validatePosition(ans, row, col, digit, head);

		// break after one failed attempt
		if (isValid != 1) {

			break;

		}

	}

	return isValid;

};

void freeMatrix(Node** head) {
	
	if (*head == NULL) {

		return;

	}

	Node* current = *head;
	Node* next = NULL;

	int exit = 0;

	while (exit == 0) {
		
		next = current->next;
		
		free(current);
		
		current = next;

		if (current == NULL) {

			exit = 1;

		}

	}

	*head = NULL;

};

int saveMatrix(Node* head) {

	if (head == NULL) {

		printf("head ptr was NULL.\n");
		return -1;

	}

	FILE* f;
	f = fopen("matrix.bin", "wb");

	if (f == NULL) {

		printf("Unable to open file.\n");
		return -2;

	}

	Node* current = head;
	Node* next = NULL;
	int exit = 0;

	while (exit == 0) {

		next = current->next;

		//null the next pointer so it doesnt get saved (break link)
		current->next = NULL;

		//positioning in file
		fseek(f, 0, SEEK_END);

		//write
		fwrite(current, sizeof(Node), 1, f);

		// restore link
		current->next = next;
		current = current->next;
		next = NULL;

		if (current == NULL) {

			exit = 1;

		}

	}

	fclose(f);
	f = NULL;

	printf("Save successful.\n");

	return 1;

}

Node* loadMatrix() {

	FILE* f;
	f = fopen("matrix.bin", "rb");

	if (f == NULL) {

		printf("Unable to load file.\n");
		return NULL;

	}

	Node* head = NULL;
	Node* aux = createNode();

	while (fread(aux, sizeof(Node), 1, f) != 0) {

		// ensure that next is null
		aux->next = NULL;

		if (head == NULL) {

			// this will only run once (for the first node)
			head = aux;

		}
		else {

			// add aux to the end of the list
			addNode(head, aux);

		}

		// get a new, fresh, out-of-the-hoven memory block
		aux = createNode();

	}

	fclose(f);
	f = NULL;

	printf("Load successful.\n");

	return head;

};