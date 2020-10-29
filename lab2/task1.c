#include <stdio.h>

void output(double result){
    printf("%.2lf\r\n",result);

}
double p_volume(double base_area,double height);
int main(){
    double area,height;
    printf("Area: ");
    scanf("%lf",&area);
    printf("Height: ");
    scanf("%lf",&height);
    output(p_volume(area,height));
    return 0;
}
double p_volume(double base_area, double height){
    return base_area*height;
}