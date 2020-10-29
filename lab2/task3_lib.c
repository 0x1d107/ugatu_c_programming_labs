#include "task3_lib.h"
double recursive_sum(int k){
    if(k==1)
        return (2*k+3)/(3*k-2);
    return recursive_sum(k-1)+(2*k+3.0)/(3*k-2.0);
}
double iterative_sum(int n){
    double sum = 0;
    for(int k = 1;k<=n;k++){
        sum+=(2*k+3.0)/(3*k-2.0);
    }
    return sum;
}