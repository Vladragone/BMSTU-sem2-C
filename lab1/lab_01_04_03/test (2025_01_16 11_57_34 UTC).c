#include <stdio.h>
#include <math.h>

int main(void){
    int a,first,second,third,s;
    printf("Enter a:\n");
    scanf("%d", &a);
    third = a%10;
    first = a/100;
    second = (a%100)/10;
    s = first*second*third;
    printf("number = %d\n",s);
    return 0;
}
