#include <stdio.h>
#include "task3_lib.h"
int main(){
    int k;
    scanf("%d",&k);
   
    printf("iterative: %lf\n", iterative_sum(k));
    printf("recursive: %lf\n",recursive_sum(k));
    return 0;
}