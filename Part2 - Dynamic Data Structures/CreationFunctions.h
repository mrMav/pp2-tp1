/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: prototypes for objects creation functions
*/

#ifndef CREATIONFUNCTIONS
#define CREATIONFUNCTIONS

#include "Types.h"

/*
Creates and returns a pointer to a Node Struct
*/
Node* createNode();

/*
Adds a Node to the end of the list starting in the given Node.
*/
Node* addNode(Node* head);

/*
Free Node Struct memory
*/
void freeNode(Node** n);

#endif // !CREATIONFUNCTIONS
