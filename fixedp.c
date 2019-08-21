//Program to find fix point of a function.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

float fun (float [], int , float );

int main()
{

double total_time;
clock_t start, end;

int o;
int res = 0;
int count = 0;

printf("Enter order of the polynomial \n");
scanf("%d",&o);

float cofs[o];
float den,p;
float cofsf[o];
float f=0;
float x;

printf("Enter the %d coefficients:", o+1);

for(int i=0;i<=o;i++)
    scanf("%f", &cofs[i]);

for(int i=o-1;i>=0;i--)
{
if(cofs[i]!=0)
{
den = cofs[i];
p = (float) o-i;
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

printf("Enter the initial value: ");
scanf("%f",&x);

start = clock();
while(1)
{
f = pow((fun(cofsf,o,x)/(-1*den)),(1/p));

if(fabs(x-f)<0.00001)
break;
x=f;

count++;
}

end = clock(); //time count stops 
printf("Iterations taken: %d \n",count);
printf("The root is: %f \n",x);

total_time = ((double) (end - start)) /  CLOCKS_PER_SEC; //calculating total time
	
	printf("\nTime taken: %f", total_time);

return 0;

}

float fun (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i)*(arr[b-i]) + res;
    
    return res;
}
