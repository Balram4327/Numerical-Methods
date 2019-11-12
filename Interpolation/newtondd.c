#include<stdio.h>
#include<stdlib.h>

float lagrange(int , int , float [], float []);

int main()
{
    int n = 4;
    float x[n],xt[n],y[n];

//Default data

    x[0] = -1;
    x[1] = 0;
    x[2] = 1;
    x[3] = 2;

    y[0] = 5;
    y[1] = 1;
    y[2] = 1;
    y[3] = 11;

    float xi = 1.5;

    float xo[n];

    int l = 0 ,m = n-1;
    float res = 0, pro;

    for(int i=0;i<n;i++)
    {
     xo[i] = lagrange(l,i,x,y);
    }

    for(int i=0;i<n-1;i++)
    {   
        pro = 1;
        for(int j=1;j<n-i;j++)
            pro = pro * (xi - x[j-1]);

        printf("%f \n",pro);
        res = res + pro * xo[n-i-1];
    }

    res = res + xo[0];

    printf("The value is %f", res);

return 0;
}

float lagrange(int l, int m, float x[], float y[])
{
    float term;
    if(l!=m)
    term = ((lagrange(l+1,m,x,y)) - (lagrange(l,m-1,x,y)))/(m-l);   

    else
    term = y[l];

    return term;
}
