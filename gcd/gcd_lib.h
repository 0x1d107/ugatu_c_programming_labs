#pragma once
#define min(a,b) (((b)<(a))?(b):(a))
#define max(a,b) (((b)>(a))?(b):(a))
#include <time.h>
#include <assert.h>
#include <stdio.h>
int gcd_naive(int,int);
int gcd_euclid(int,int);
typedef struct {
    double time;
    int input[2];
} result_t;
typedef struct {
    result_t best;
    result_t worst;
    result_t average;
} results_t;
double test(int a,int b,int tests,int(*gcd)(int,int));
void print_report(char * name,results_t results);

