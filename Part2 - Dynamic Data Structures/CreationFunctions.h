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
toAdd is the element to add. If NULL, a node will be created and inserted.
*/
Node* addNode(Node* head, Node* toAdd);

/*
Free Node Struct memory
*/
void freeNode(Node** n);

#endif // !CREATIONFUNCTIONS
