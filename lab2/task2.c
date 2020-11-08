#include <stdio.h>
#include <math.h>
#define RING_AREA(r1,r2) (M_PI*((r2)*(r2)-(r1)*(r1)))
double ring_area(r1,r2){
    return M_PI*(r2*r2-r1*r1);
}
int main(){

    double r2,r1;
    printf("Inner radius:");
    scanf("%lf",&r1);
    printf("Outer radius:");
    scanf("%lf",&r2);
    if(r1>=r2||r1<=0||r2<=0){
        printf("Wrong radius\n");
        return 0;
    }
    printf("macro: %.2lf\r\n",RING_AREA(r1,r2));
    printf("function: %.2lf\r\n",ring_area(r1,r2));
    

    return 0;
}
