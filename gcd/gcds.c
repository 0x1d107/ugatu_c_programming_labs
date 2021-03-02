#include "gcd_lib.h"


int main(){
    results_t euclid = {0};
    results_t naive = {0};
    double euclid_total_time = 0;
    double naive_total_time = 0;
    int count =0;
    int gcds[1000][1000]={0};
    for(int i=1000;i>0;i--)
        for(int j=i;j>0;j--){
            printf("testing euclid(%d,%d)\r\n",i,j);
            double time = test(i,j,2000,gcd_euclid);
            if(time<euclid.best.time||!euclid.best.input[0]){
                euclid.best.time = time;
                euclid.best.input[0] = i;
                euclid.best.input[1] = j;
            }
            if(time>euclid.worst.time||!euclid.worst.input[0]){
                euclid.worst.time = time;
                euclid.worst.input[0] = i;
                euclid.worst.input[1] = j;
            }
            euclid_total_time+=time;
            printf("testing naive(%d,%d)\r\n",i,j);
            time = test(i,j,2000,gcd_naive);
            if(time<naive.best.time||!naive.best.input[0]){
                naive.best.time = time;
                naive.best.input[0] = i;
                naive.best.input[1] = j;
            }
            if(time>naive.worst.time||!naive.worst.input[0]){
                naive.worst.time = time;
                naive.worst.input[0] = i;
                naive.worst.input[1] = j;
            }
            naive_total_time+=time;
            
    
            

            gcds[i-1][j-1]=gcd_euclid(i,j);
            count++;
        
        }
        euclid.average.time = euclid_total_time/count;
        naive.average.time = naive_total_time/count;
        print_report("euclid",euclid);
        print_report("naive",naive);

  
}