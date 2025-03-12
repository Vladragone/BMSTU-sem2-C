#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main(void){
    float a,b,c,s;
    printf("Enter two sides and corner (using space):\n");
    scanf("%f%f%f", &a,&b,&c);
    s = a*b*sin(PI*c/180)/2;
    printf("s = %f\n",s);
    return 0;
}
