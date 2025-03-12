#include <stdio.h>

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    int rc;
    rc = scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (rc == 8)
    {
        if (((x1 == x2) && (y1 == y2)) || ((x3 == x4) && (y3 == y4)))
        {
            printf("Invalid out");
            return 1;
        }
        double v1x = x2 - x1;
        double v1y = y2 - y1;
        double v2x = x4 - x3;
        double v2y = y4 - y3;
        double d1 = v1x * (y3 - y1) - v1y * (x3 - x1);
        double d2 = v1x * (y4 - y1) - v1y * (x4 - x1);
        double d3 = v2x * (y1 - y3) - v2y * (x1 - x3);
        double d4 = v2x * (y2 - y3) - v2y * (x2 - x3);
        if ((d1 * d2 < 0) && (d3 * d4 < 0))
        {
            printf("1");
            return 0;
        } 
        else
        {
            printf("0");
            return 0;
        }
    } 
    else
    {
        printf("Invalid out");
        return 1;
    }
}
