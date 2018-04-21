/*
author: Jorge Noro
date: 18/04/2018
purpose: pp2-tp1, part 1, static data structures
*/

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "CreationFunctions.h"
#include "UtilityFunctions.h"

int main() {

	// seed for random numbers
	//srand(time(NULL));   // should only be called once
	srand(10);

	Matrix* matrix = createMatrix();
	printMatrix(matrix);

	getchar();

	return 0;

}