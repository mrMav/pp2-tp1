/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: prototypes for utility functions
*/

#ifndef UTILITYFUNCTIONS
#define UTILITYFUNCTIONS

#include "Types.h"

/*
Prints a line
*/
void printLine(int size);

/*
Prints information about the given node
*/
void printNode(Node* n);

/*
Prints information about the given row
*/
void printRow(Row* r);

/*
Prints information about the given matrix
*/
void printMatrix(Matrix* m);

/*
Returns number between min and max-1
*/
int randomInt(int min, int max);

/*
Asks user to input matrix card data and validates operation.
Returns 1 if sucessfull, 0 otherwise.
*/
int validateOperation(Matrix* matrix);

/*
Checks if given digit is correct
*/
int validatePosition(int ans, int row, int col, int pos, Matrix* matrix);

/*
Fetchs a digit by string input in the form 'a1-2'
Only supported in matrixs up to 9 columns, rows up to z, sequence_size up to 9
*/
int fetchDigit(char* string, Matrix* matrix);

#endif // !UTILITYFUNCTIONS
