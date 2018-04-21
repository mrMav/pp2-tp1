/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: implementation of utility functions
*/

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"

// Creates and returns a pointer to a Node Struct
Node* createNode() {

	Node* n = (Node*)malloc(sizeof(Node));

	n->sequence[0] = rand() % 10;  //random number in the range of 0-9 inclusive
	n->sequence[1] = rand() % 10;  
	n->sequence[2] = rand() % 10;  
	
	return n;

};

// Creates and returns a pointer to a Row Struct
Row* createRow() {

	Row* r = (Row*)malloc(sizeof(Row));

	for (int i = 0; i < COLUMNS_NUMBER; i++) {

		r->nodes[i] = createNode();

	}

	return r;

};

// Creates and returns a pointer to a Matrix Struct
Matrix* createMatrix() {

	Matrix* m = (Matrix*)malloc(sizeof(Matrix));

	for(int i = 0; i < ROWS_NUMBER; i++) {
	
		m->rows[i] = createRow();
	
	}

	return m;

};