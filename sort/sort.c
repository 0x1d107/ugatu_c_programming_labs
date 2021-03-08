#include "sort.h"
#include <string.h>
int* generate_array(int len){
    int* array = calloc(len,sizeof(int));
    for( int i=0;i<len;i++){
        array[i]=i;
    }
    return array;
}
void shuffle(int*array,int len){
    srand(time(0));
    for(int i=0;i<len;i++){
        for (int j=i;j<len;j++){
            if(rand()>RAND_MAX/2){
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
            }
        }
    }
}
void reverse(int* array, int len){
    for(int i=0;i<len/2;i++){
        int t = array[len-i-1];
        array[len-1-i] =array[i];
        array[i]=t;
    }
}
double measure_time(sort_t sort,int iterations,int* array, int len){
    int** arrays_new = malloc(iterations*sizeof(int*));
    for(int i=0;i<iterations;i++)
        arrays_new[i] = malloc(len*sizeof(int));
    for(int i=0;i<iterations;i++){
        memcpy(arrays_new[i],array,len);
    }
    clock_t start = clock();
    for(int i=0;i<iterations;i++){
        sort(arrays_new[i],len);
    }
    clock_t stop = clock();
    for(int i=0;i<iterations;i++)
        free(arrays_new[i]);
    free(arrays_new);
    return ((double)(stop - start))/CLOCKS_PER_SEC/iterations;

}

void insertion_sort(int* array,int len){
    for(int i=1;i<len;i++){
        char k = array[i];
        int j = i;
        while(--j>=0 && array[j]<k){
            array[j+1]=array[j];
        }
        array[j+1]=k;
    }
}
void shell_sort(int* array,int len){
    for(int s=len/2; s>0; s/=2){
        for(int i=0; i<len; i++){
            for(int j=i+s; j<len; j+=s){
                if(array[i] > array[j]){
                    int t = array[j];
                    array[j] = array[i];
                    array[i] = t;
                }
            }
        }
    }
}

void qs(int* array,int first,int last){
    if (first < last){
        int left = first, right = last, middle = array[(left + right) / 2];
        do{
            while (array[left] < middle) left++;
            while (array[right] > middle) right--;
            if (left <= right){
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(array, first, right);
        qs(array, left, last);
    }
}
void quick_sort(int* array,int len){
    qs(array,0,len-1);
}
int qsort_cmp(const void* a, const void* b){
    int A = *(const int*)a;
    int B = *(const int*)b;
    if(A < B)
        return -1;
    if(A > B)
        return 1;
    return 0;
}
void qsort_sort(int* array,int len){
    qsort(array,len,sizeof(int),qsort_cmp);
}