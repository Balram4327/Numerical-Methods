////Newton Rapson Method for finding root of a polynomial entered by user. 
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

float fun(float [], int, float );
float derivate(float [], int, float );

int main()
{

double total_time;
clock_t start, end;

float a,b; //range vaules 
float c; //root value

int o; //order of the polynomial

float f=0.0;
int res=0;
int count=0;
int n;

printf("Enter order of the polynomial \n");
scanf("%d",&o);

float cofs[o];

printf("Enter the %d coefficients:", o+1);

for(int i=0;i<=o;i++)
    scanf("%f", &cofs[i]);

float df = 0;
     

/*
while(res==0)
    {
        printf("Enter lower limit: \n");
        scanf("%f",&a);

        printf("Enter upper limit: \n");
        scanf("%f",&b);

        if(fun(cofs,o,a)*fun(cofs,o,b)<0)
            res=1;
        else
            printf("Enter the limits again! \n");
    }

c = (a + b)/2; */

printf("Enter the initial value \n");
scanf("%f",&c);

//printf("Enter the number of iterations \n");
//scanf("%d",&n);

res=0;
start = clock();
while(res==0)
    {
        df = derivate(cofs,o,c);
        f = fun(cofs,o,c);

        c = c - (f / df);
   
         if(abs(f)<0.00001)
        res=2;

        count++;
    }
end = clock(); //time count stops 

printf("Number of iteratino %d \n",count);
printf("Root value is: \n %f",c);


	
	total_time = ((double) (end - start)) /  CLOCKS_PER_SEC; //calculating time taken
	
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

float derivate (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        res = pow(c,i-1)*(i)*(arr[b-i]) + res;
    
    return res;
}