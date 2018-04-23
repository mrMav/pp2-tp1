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
Checks if given digit is correct
*/
int validatePosition(int ans, int row, int col, int pos, Node* head);


#endif // !MATRIX