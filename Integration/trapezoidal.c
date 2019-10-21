#include<stdlib.h>
#include<math.h>
#include<stdio.h>

float fun(float [], int, float );

int main()
{
    int o;
    printf("Enter order of the polynomial \n");
    scanf("%d",&o);

    float cofs[o];

    printf("Enter the %d coefficients:", o+1);
    for(int i=0;i<=o;i++)
    scanf("%f", &cofs[i]);

    float a,b,m;
 
    printf("Enter the lower limit (a) \n");
    scanf("%f",&a);
    printf("Enter the upper limit (b) \n");
    scanf("%f",&b);

    printf("Enter the number of subintervals \n");
    scanf("%f",&m);

    float h;
    h = (b-a)/m;

    float ftemp, inte;

    ftemp = 0;
    for(int i=1;i<m;i++)
    ftemp = ftemp + fun(cofs,o,a+(i*h));

    ftemp = 2*ftemp;

    inte = (h/2) * (fun(cofs,o,a) + ftemp + fun(cofs,o,b));
   
    printf("Integration of the function is: %f  \n", inte);
    
}

float fun (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i)*(arr[b-i]) + res;
    
    return res;
}