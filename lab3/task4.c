#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char* gen_array(unsigned int len,char range_start,char range_end){
    
    char* array = malloc(len*sizeof(char));
    for(int i=0;i<len;i++){
        array[i]=rand()%(range_end - range_start + 1) + range_start;

    }
    return array;
}
void insertion_sort_desc(char* array,unsigned int len){
    for(int i=1;i<len;i++){
        char k = array[i];
        int j = i;
        while(--j>=0 && array[j]<k){
            array[j+1]=array[j];
        }
        array[j+1]=k;
    }
}
int main(){
    unsigned int len; 
    char range_start,range_end;
    printf("Range: ");
    scanf("%c %c",&range_start,&range_end);
    printf("Array length: ");
    scanf("%u",&len);
  
    


    srand(time(0));
    char* array = gen_array(len,range_start,range_end);
    printf("Generated array: ");
    for(int i=0;i<len;i++)
        printf("%c ",array[i]);
    printf("\b\r\n");
    insertion_sort_desc(array,len);
    printf("Sorted array: ");
    for(int i=0;i<len;i++)
        printf("%c ",array[i]);
    printf("\b\r\n");
    return 0;
    
}
