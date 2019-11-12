#include<stdio.h>
#include<stdlib.h>

float lagrange(int , int , float , float [], float []);

int main()
{
    int n = 4;
    float x[n],xt[n],y[n];

    x[0] = -1;
    x[1] = 0;
    x[2] = 1;
    x[3] = 2;

    y[0] = 5;
    y[1] = 1;
    y[2] = 1;
    y[3] = 11;

    float xi = 1.5;

    int l = 0 ,m = n-1;
    float res;

    res = lagrange(l,m,xi,x,y);

    printf("The value is %f", res);

return 0;
}

float lagrange(int l, int m, float xi,float x[], float y[])
{
    float term;
    if(l!=m)
    term = ((xi - x[l])*(lagrange(l+1,m,xi,x,y)) - (xi - x[m])*(lagrange(l,m-1,xi,x,y)))/(m-l);   

    else
    term = y[l];

    return term;
}
