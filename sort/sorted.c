#include <stdio.h>
#include "sort.h"
const int N = 100;
int main(){
    int* array = generate_array(N);
    
    double sorted_time_ins = measure_time(insertion_sort,10,array,N);
    double sorted_time_q = measure_time(quick_sort,10,array,N);
    double sorted_time_shell = measure_time(shell_sort,10,array,N);
    double sorted_time_qsort = measure_time(qsort_sort,10,array,N);
    printf("[sorted]\r\n\tinsertion sort:%e\r\n\tquicksort:%e\r\n\tshell:%e\r\n\tqsort:%e\r\n",sorted_time_ins,sorted_time_q,sorted_time_shell,sorted_time_qsort);
    reverse(array,N);
    double reverse_time_ins = measure_time(insertion_sort,10,array,N);
    double reverse_time_q = measure_time(quick_sort,10,array,N);
    double reverse_time_shell = measure_time(shell_sort,10,array,N);
    double reverse_time_qsort = measure_time(qsort_sort,10,array,N);
    printf("[reverse]\r\n\tinsertion sort:%e\r\n\tquicksort:%e\r\n\tshell:%e\r\n\tqsort:%e\r\n",reverse_time_ins,reverse_time_q,reverse_time_shell,reverse_time_qsort);
    shuffle(array,N);
    double shuffled_time_ins = measure_time(insertion_sort,10,array,N);
    double shuffled_time_q = measure_time(quick_sort,10,array,N);
    double shuffled_time_shell = measure_time(shell_sort,10,array,N);
    double shuffled_time_qsort = measure_time(qsort_sort,10,array,N);
    printf("[shuffled]\r\n\tinsertion sort:%e\r\n\tquicksort:%e\r\n\tshell:%e\r\n\tqsort:%e\r\n",shuffled_time_ins,shuffled_time_q,shuffled_time_shell,shuffled_time_qsort);
    return 0;
}