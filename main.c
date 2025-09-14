#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y;
    printf("Enter x:");
    scanf("%lf", &x);
    if (x>=-12 && x<-8)
        y = pow(2,(abs(x)+1));

    else if (x>=-3 && x<3)
        y = (fabs(cos(x))+x)/(sin(x)+1);

    else if (x>=10 && x<200)
        y = 4*x+sqrt(x*x*x-2*x);
    else
        y = 0.008;

    system("cls");
    printf("x = %lf", x);
    printf("\ny = %lf", y);
    return 0;
}
