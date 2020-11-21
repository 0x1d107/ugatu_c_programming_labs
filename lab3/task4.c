#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* gen_array(unsigned int len,int range_start,int range_end){
    
    int* array = malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
        array[i]=rand()%(range_end - range_start + 1) + range_start;

    }
    return array;
}
void insertion_sort_desc(int* array,unsigned int len){
    for(int i=1;i<len;i++){
        int k = array[i];
        int j = i;
        while(--j>=0 && array[j]<k){
            array[j+1]=array[j];
        }
        array[j+1]=k;
    }
}
int main(){
    unsigned int len;
    printf("Array length: ");
    scanf("%u",&len);
    int range_start,range_end;
    printf("Start: ");
    scanf("%d",&range_start);
    printf("End: ");
    scanf("%d",&range_end);
    srand(time(0));
    int* array = gen_array(len,range_start,range_end);
    printf("Generated array: ");
    for(int i=0;i<len;i++)
        printf("%d ",array[i]);
    printf("\b\r\n");
    insertion_sort_desc(array,len);
    printf("Sorted array: ");
    for(int i=0;i<len;i++)
        printf("%d ",array[i]);
    printf("\b\r\n");
    return 0;
    
}
