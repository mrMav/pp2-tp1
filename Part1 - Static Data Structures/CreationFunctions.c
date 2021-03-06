/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: implementation of utility functions
*/

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "UtilityFunctions.h"
#include "CreationFunctions.h"

Node* createNode() {

	Node* n = (Node*)malloc(sizeof(Node));

	// error handling
	if (n == NULL) {

		printf("Failed to allocate memory for Node.\n");
		return NULL;

	}

	for (int i = 0; i < SEQUENCE_SIZE; i++) {

		n->sequence[i] = randomInt(0, 10);

	}

	return n;

};

Row* createRow() {

	Row* r = (Row*)malloc(sizeof(Row));

	// error handling
	if (r == NULL) {

		printf("Failed to allocate memory for Row.\n");
		return NULL;

	}

	for (int i = 0; i < COLUMNS_NUMBER; i++) {

		r->nodes[i] = createNode();

	}

	return r;

};

Matrix* createMatrix() {

	Matrix* m = (Matrix*)malloc(sizeof(Matrix));

	// error handling
	if (m == NULL) {

		printf("Failed to allocate memory for Matrix.\n");
		return NULL;

	}

	for (int i = 0; i < ROWS_NUMBER; i++) {

		m->rows[i] = createRow();

	}

	return m;

};

void freeNode(Node** n) {

	free(*n);
	*n = NULL;

};

void freeRow(Row** r) {

	free(*r);
	*r = NULL;

};

void freeMatrix(Matrix** m) {

	free(*m);
	*m = NULL;
		
};