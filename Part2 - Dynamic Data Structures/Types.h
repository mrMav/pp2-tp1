/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 22/04/2018
desc: define all data types for part2 (dynamic data structures)
*/

#ifndef TYPES
#define TYPES

/*
Number of columns in the Matrix Card
*/
#define COLUMNS_NUMBER 8

/*
Number of rows in the Matrix Card
*/
#define ROWS_NUMBER 8

/*
Number of digits in a Node sequence
*/
#define SEQUENCE_SIZE 3

/*
Number of times the user will be asked for Matrix Card input
*/
#define SECURITY_LEVEL 3

/*
Represents a Node. A Node is where the Matrix Card numbers are stored.
*/
typedef struct Node {

	int sequence[SEQUENCE_SIZE];
	struct Node* next;

} Node;

#endif // !TYPES