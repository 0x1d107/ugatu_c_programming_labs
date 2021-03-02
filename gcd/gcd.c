#include <stdio.h>
#include <time.h>
#include <assert.h>
#define min(a,b) (((b)<(a))?(b):(a))
#define max(a,b) (((b)>(a))?(b):(a))
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

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    const float TESTS=1000000;
    clock_t start_e = clock();
    for (int i =0;i<TESTS;i++){
        gcd_euclid(a,b); 

    }
    clock_t end_e = clock();
    clock_t start_naive = clock();
    for (int i =0;i<TESTS;i++){
        gcd_naive(a,b); 

    }
    clock_t end_naive = clock();
    double naive = (end_naive - start_naive)/TESTS/CLOCKS_PER_SEC;

    double euclid = (end_e - start_e)/TESTS/CLOCKS_PER_SEC;
    printf("Time for euclid: %lf\r\nTime for brute force: %lf\r\n",euclid,naive);


    return 0;
}
