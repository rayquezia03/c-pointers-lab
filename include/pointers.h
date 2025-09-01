#ifndef POINTERS_H
#define POINTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// basic_pointers.c
void demo_basic_pointers();

// array_pointers.c
void demo_array_pointers();
void demo_char_pointers();

// swap.c
void swap(int *a, int *b);
void demo_swap();

// dynamic_allocation.c
int** allocate_int_matrix(int rows, int cols);
void free_int_matrix(int **matrix, int rows);
void demo_dynamic_allocation();

// function_pointers.c
void demo_qsort();

// common_pitfalls.c
void demo_common_pitfalls();

#endif // POINTERS_H
