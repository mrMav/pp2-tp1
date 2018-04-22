/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: prototypes for objecty creation functions
*/

#ifndef CREATIONFUNCTIONS
#define CREATIONFUNCTIONS

#include "Types.h"

/*
Creates and returns a pointer to a Node Struct
*/
Node* createNode();

/*
Creates and returns a pointer to a Row Struct
*/
Row* createRow();

/*
Creates and returns a pointer to a Matrix Struct
*/
Matrix* createMatrix();

/*
Free Node Struct memory
*/
void freeNode(Node** n);

/*
Free Row Struct memory
*/
void freeRow(Row** r);

/*
Free Matrix Struct memory
*/
void freeMatrix(Matrix** m);

#endif // !CREATIONFUNCTIONS
