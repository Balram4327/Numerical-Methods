//Program to find fix point of a function.
#include<stdio.h>

int main()
{
int o,res = 0;

printf("Enter order of the polynomial \n");
scanf("%d",&o);

float cofs[o];
float den,p;
float cofsf[o];

printf("Enter the %d coefficients:", o+1);

for(int i=0;i<=o;i++)
    scanf("%f", &cofs[i]);

for(int i=0;i<=o;i++)
    printf("%f \n", cofs[i]);

for(int i=o-1;i>=0;i--)
{
if(cofs[i]!=0)
{
den = cofs[i];
p = 1/(o-i);
res = i;
break;
}
}

for(int j=0;j<=o;j++)
{
if(j!=res)
    cofsf[j]=cofs[j];     
else
    cofsf[j]=0;    
}

printf("%d \n",res);
for(int i=0;i<=o;i++)
    printf("%f \n", cofsf[i]);

return 0;

}

