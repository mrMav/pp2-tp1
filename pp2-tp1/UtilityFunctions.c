/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: implementation of utility functions
*/

#include <stdio.h>
#include "Types.h"

// Prints information about the given node
void printNode(Node* n) {

	printf("{ %i %i %i }", n->sequence[0], n->sequence[1], n->sequence[2]);

};

// Prints information about the given row
void printRow(Row* r) {

	printf("[ ");

	for (int i = 0; i < COLUMNS_NUMBER; i++) {

		printNode(r->nodes[i]);
		printf(" ");
	}

	printf("]");

};

// Prints information about the given matrix
void printMatrix(Matrix* m) {

	printf("[\n");

	for (int i = 0; i < ROWS_NUMBER; i++) {

		printf("\t");
		printRow(m->rows[i]);
		printf("\n");
	}
	
	printf("]\n");

};
