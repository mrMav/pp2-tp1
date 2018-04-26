/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
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

	n->next = NULL;
	
	return n;

};

Node* addNode(Node* head, Node* toAdd) {

	Node* n = head;

	while (n->next != NULL) {

		n = n->next;

	}
		
	//If n->next is NULL, we add a new node to the end of the list
	if (toAdd == NULL) {
		
		n->next = createNode();

	}
	else {

		n->next = toAdd;

	}

	return n->next;

}

void freeNode(Node** n) {
	
	free(*n);
	*n = NULL;

};