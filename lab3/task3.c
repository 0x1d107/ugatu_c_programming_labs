#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printMatrix(int** matrix,unsigned int rows,unsigned int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%i ",matrix[i][j]);
        }
        printf("\b\r\n");
    }
}
int main(){
    srand(time(0));
    unsigned int rows=0u,cols=0u;
    printf("Row count: ");
    scanf("%u",&rows);
    printf("Column count: ");
    scanf("%u",&cols);
    int** matrix = calloc(rows,sizeof(int*));
    if(!matrix) return -1;
    int * row;
    for(int i=0;i<rows;i++)
        if(row=calloc(cols,sizeof(int)))
            matrix[i]=row;
        else
            return -1;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            matrix[i][j]=rand()%101;
    printf("Generated matrix:\r\n");
    printMatrix(matrix,rows,cols);
    for(int i=0;i<rows/2;i++){
        int j = rows - 1 - i;
        int* t = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = t;
    }
    printf("Mirrored matrix:\r\n");
    printMatrix(matrix,rows,cols);
    for(int i=0;i<rows;i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}
