/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: define all data types for part1 (static data structures)
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
typedef struct {

	int sequence[SEQUENCE_SIZE];

} Node;

/*
Represents a Row. A Row stores a staticly defined number of Nodes.
*/
typedef struct {

	Node* nodes[COLUMNS_NUMBER];

} Row;

/*
Represents a Matrix. A Matrix stores a staticly defined number of Rows.
*/
typedef struct {

	Row* rows[ROWS_NUMBER];

} Matrix;

#endif // !TYPES