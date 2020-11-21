#include <stdio.h>
#include <stdlib.h>
const size_t MAX_N = 1000;
void average(double* array,int len, double* mean_neg, double* mean_pos){
    int neg_count=0,pos_count=0;
    double neg_sum=0,pos_sum=0;
    for(int i=0;i<len;i++){
        if(*(array+i)<0){
            neg_count++;
            neg_sum+=*(array+i);
        }else if(*(array+i)>0){
            pos_count++;
            pos_sum+=*(array+i);
        }
    }
    *mean_neg = neg_count?neg_sum/neg_count:0;
    *mean_pos = pos_count?pos_sum/pos_count:0;
}
int main(){
    double a[MAX_N],mean_neg,mean_pos;
    unsigned int n;
    printf("N: ");
    scanf("%u",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    average(a,n,&mean_neg,&mean_pos);
    if(mean_pos)
        printf("Average positive number: %lf\r\n",mean_pos);
    else
        printf("No positive numbers\r\n");
    if (mean_neg)
        printf("Average negative number: %lf\r\n",mean_neg);
    else
        printf("No negative numbers\r\n");
    return 0;
}
