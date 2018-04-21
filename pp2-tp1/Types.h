/*
author: Jorge Noro
email: a15705@alunos.ipca.pt
date: 18/04/2018
desc: define all data types for part1 (static data structures)
*/

#ifndef TYPES
#define TYPES

#define COLUMNS_NUMBER 8
#define ROWS_NUMBER 6

typedef struct {

	int sequence[3];

} Node;

typedef struct {

	Node* nodes[COLUMNS_NUMBER];

} Row;

typedef struct {

	Row* rows[ROWS_NUMBER];

} Matrix;

#endif // !TYPES