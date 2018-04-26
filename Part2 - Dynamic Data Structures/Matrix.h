/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: functions to manipulate the matrix (linked list)
*/

#ifndef MATRIX
#define MATRIX

#include "Types.h"

/*
Number of columns in the Matrix Card
*/
Node* buildMatrix();

/*
Resets the Matrix by populating the nodes with new random numbers
*/
void resetMatrix(Node* head);

/*
Print Matrix 1
*/
void printMatrix(Node* head);

/*
Asks user to input matrix card data and validates operation.
Returns 1 if sucessfull, 0 otherwise.
*/
int validateOperation(Node* head);

/*
Searches the matrix in search of the ans, at row, col and pos.
*/
int validatePosition(int ans, int row, int col, int pos, Node* head);

/*
/*
Release memory of the matrix
*/
void freeMatrix(Node** head);

#endif // !MATRIX