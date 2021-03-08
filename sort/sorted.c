#include <stdio.h>
#include "sort.h"
const int N = 100;
const int M = 2000;
int main(){
    
    

    for (int n=N;n<=M;n+=100){
        int* array = generate_array(n);
        printf("For n = %d,",n);
        double sorted_time_ins = measure_time(insertion_sort,10,array,n);
        double sorted_time_q = measure_time(quick_sort,10,array,n);
        double sorted_time_shell = measure_time(shell_sort,10,array,n);
        double sorted_time_qsort = measure_time(qsort_sort,10,array,n);
        printf("[sorted]\r\n\tinsertion sort:%e,quicksort:%e\r\n\tshell:%e\r\n\tqsort:%e\r\n",sorted_time_ins,sorted_time_q,sorted_time_shell,sorted_time_qsort);
        reverse(array,N);
        double reverse_time_ins = measure_time(insertion_sort,10,array,n);
        double reverse_time_q = measure_time(quick_sort,10,array,n);
        double reverse_time_shell = measure_time(shell_sort,10,array,n);
        double reverse_time_qsort = measure_time(qsort_sort,10,array,n);
        printf("[reverse]\r\n\tinsertion sort:%e\r\n\tquicksort:%e\r\n\tshell:%e\r\n\tqsort:%e\r\n",reverse_time_ins,reverse_time_q,reverse_time_shell,reverse_time_qsort);
        shuffle(array,N);
        double shuffled_time_ins = measure_time(insertion_sort,10,array,n);
        double shuffled_time_q = measure_time(quick_sort,10,array,n);
        double shuffled_time_shell = measure_time(shell_sort,10,array,n);
        double shuffled_time_qsort = measure_time(qsort_sort,10,array,n);
        printf("[shuffled]\r\n\tinsertion sort:%e\r\n\tquicksort:%e\r\n\tshell:%e\r\n\tqsort:%e\r\n",shuffled_time_ins,shuffled_time_q,shuffled_time_shell,shuffled_time_qsort);
        free(array);
    }
    return 0;
}