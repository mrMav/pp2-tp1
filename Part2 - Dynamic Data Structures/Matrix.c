/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: functions to manipulate the matrix (linked list)
*/

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "Matrix.h"
#include "UtilityFunctions.h"
#include "CreationFunctions.h"

/*
Number of columns in the Matrix Card
*/
Node* buildMatrix() {

	Node* head = createNode();
	Node* tail = NULL;

	for (int i = 0; i < COLUMNS_NUMBER * ROWS_NUMBER - 1; i++) {

		tail = addNode(head);

	}

	return head;

};
