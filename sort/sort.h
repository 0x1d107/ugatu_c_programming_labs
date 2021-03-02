#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*sort_t)(int *,int);

int* generate_array(int len);
void shuffle(int*array,int len);
void reverse(int*array,int len);
double measure_time(sort_t sort,int iterations,int* array, int len);
void insertion_sort(int*,int);
void shell_sort(int*,int);
void quick_sort(int*,int);
