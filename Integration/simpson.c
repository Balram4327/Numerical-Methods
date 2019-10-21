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

    float ftemp1, ftemp2, inte;

    ftemp2 = 0;
    ftemp1 = 0;
    for(int i=1;i<=(m/2)-1;i++)
    ftemp2 = ftemp2 + fun(cofs,o,a+(2*i*h));

    for(int i=1;i<(m/2);i++)
    ftemp1 = ftemp1 + fun(cofs,o,a+((2*i-1)*h));

    ftemp1 = 2*ftemp1;
    ftemp2 = 4*ftemp2;

    inte = (h/3) * (fun(cofs,o,a) + ftemp1 + ftemp2 + fun(cofs,o,b));
   
    printf("Integration of the function is: %f  \n", inte);
    
}

float fun (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i)*(arr[b-i]) + res;
    
    return res;
}