/*
author: Jorge Noro
date: 22/04/2018
purpose: pp2-tp1, part 2, dynamic data structures
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "CreationFunctions.h"
#include "UtilityFunctions.h"
#include "Matrix.h"

int main() {

	// seed for random numbers
	//srand(time(NULL));   // should only be called once
	srand(1);

	Node* matrix = buildMatrix();
	
	printListOfNodes(matrix);

	printf("\n");

	getchar();

	return 0;

}