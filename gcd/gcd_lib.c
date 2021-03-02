#include "gcd_lib.h"

int gcd_naive(int a, int b){
    int gcd = 1;
    for(int i=2;i<=min(a,b);i++)
	if(a%i==0&&b%i==0)
	    gcd = i;
    return gcd;
}
int gcd_euclid(int a, int b){
    while(a>0&&b>0){
	if(a>=b) {
	    a = a%b;
	    
	}else {
	    int t = b;
        b = a;
        a =t;
	}
    }
    return b;
}
double test(int a,int b,int tests,int(*gcd)(int,int)){
    clock_t start = clock();
    for(int i=0;i<tests;i++)
        gcd(a,b);
    clock_t end = clock();
    return(end - start)/(double)tests/CLOCKS_PER_SEC;
}
void print_report(char* name,results_t results){
    printf("Report for %s:\r\n\tBest: %e (%d, %d)\r\n\tWorst: %e (%d, %d)\r\n\tAverage: %e\r\n",name,results.best.time,results.best.input[0],results.best.input[1],results.worst.time,results.worst.input[0],results.worst.input[1],results.average.time);
}