#include <stdio.h>

int main(void){
    float v,a,t,s;
    printf("Enter v0,a,t (using space):\n");
    scanf("%f%f%f", &v,&a,&t);
    s = v*t+a*t*t/2;
    printf("s = %f\n",s);
    return 0;
}
