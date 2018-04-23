/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
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
Resets a Node by populating it with a new sequence
*/
void resetNode(Node* n);

/*
Allows to perform a function in each node.
It works by cycling through the linked list
and calling the function given as a parameter.
*/
void forEachNode(Node* head, void(*callback)(Node* n));

/*
Returns number between min and max-1
*/
int randomInt(int min, int max);

/*
Fetchs a digit by string input in the form 'a1-2'
Only supported in matrixs up to 9 columns, rows up to z, sequence_size up to 9
*/
int fetchDigit(char* string, Node* matrix);

#endif // !UTILITYFUNCTIONS

