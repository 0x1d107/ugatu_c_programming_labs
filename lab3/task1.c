#include <stdio.h>
#include <math.h>
#define SQ(x) ((x)*(x))
typedef struct point {
    double x,y,z;
} point_t;

point_t p_minus(point_t a, point_t b){
    point_t c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}
double triple_product(point_t a, point_t b, point_t c){
    return c.x*b.y*a.z + c.y*b.z*a.x + b.x*a.y*c.z - c.z*b.y*a.x - c.y*b.x*a.z - c.x*b.z*a.y;
}
double sq_cross_len(point_t a, point_t b){
    return SQ(b.y*a.z - b.z*a.y) + SQ(b.z*a.x - b.x*a.z) + SQ(b.x*a.y - b.y*a.x);
}
double triangle_area(point_t a, point_t b,point_t c){
    return sqrt(sq_cross_len(p_minus(b,a),p_minus(c,a)))/2.0;
}
void calculate(point_t* points, double* volume,double * area){
    point_t a=points[0],b = points[1],c = points[2],d = points[3];
    *volume = fabs(triple_product(p_minus(b,a),p_minus(c,a),p_minus(d,a)))/6.0;
    *area =   triangle_area(a,b,c)
            + triangle_area(a,b,d)
            + triangle_area(b,c,d)
            + triangle_area(a,c,d);
}
int main(){
    point_t points[4];
    double volume,area;
    for (int i=0;i<4;i++){
        printf("Point %d (x,y,z):",i);
        scanf("%lf%lf%lf",&points[i].x,&points[i].y,&points[i].z);
    }
    calculate(points,&volume,&area);
    printf("volume: %lf\r\narea: %lf\r\n",volume,area);
    return 0;
}