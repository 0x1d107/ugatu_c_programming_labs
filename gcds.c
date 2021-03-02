#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "gcd_lib.h"
int gcds [1000][1000];
int gcdn [1000][1000];
typedef struct {
    double time;
    int input[2];
} result_t;

result_t results[2][3];

int main(){
    for(int i=1000;i>0;i--)
        for(int j=i;j>0;j--){
            gcds[i-1][j-1]=gcd_euclid(i,j);
        
        }
    for(int i=1000;i>0;i--){
        for(int j=999;j>0;j--)
            printf("%3d ",gcds[(i>j?i:j)-1][(i>j?j:i)-1]);

        printf("\b\r\n");
    }
}