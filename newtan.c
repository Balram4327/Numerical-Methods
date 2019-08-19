//Newton Rapson Method for a particular trigonometric function
#include<stdio.h>
#include<math.h>
#include<time.h>

float fun(float [], int, float );
float derivate(float [], int, float );

int main()
{

double total_time;
clock_t start, end;

float a,b; //range vaules 
float c; //root value

int o; //order of the polynomial

float f = 0;
float df = 0;

int res=0;
int count=0;
int n;

/*
printf("Enter order of the polynomial \n");
scanf("%d",&o);

float cofs[o];

printf("Enter the %d coefficients:", o+1);

for(int i=0;i<=o;i++)
    scanf("%f", &cofs[i]);  */
     
start = clock();

printf("Enter the initial value \n");
scanf("%f",&c);

printf("Enter the number of iterations \n");
scanf("%d",&n);


while(count<n)
    {
        df = (pow(cos(3.14*c),-2)*3.14) - 1;
        f = tan(3.14*c) - c - 6;

        c = c - (f / df);
        
        count++;
    }

printf("Root value is: \n %f",c);

end = clock();
	//time count stops 
	total_time = ((double) (end - start)) /  CLOCKS_PER_SEC;
	//calulate total time
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