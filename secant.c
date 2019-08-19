//Secant Method for finding root of a polynomial entered by user. 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

float fun(float [], int, float ); 

int main()
{

    double total_time;
clock_t start, end;


float arr[3];

int o; //order of the polynomial
int n; //number of iterations

float f = 0; //value of f
int count = 0; 

printf("Enter order of the polynomial \n");
scanf("%d",&o);

float cofs[o];

printf("Enter the %d coefficients:", o+1);

for(int i=0;i<=o;i++)
    scanf("%f", &cofs[i]);

        printf("Enter lower limit: \n");
        scanf("%f",&arr[0]);

        printf("Enter upper limit: \n");
        scanf("%f",&arr[1]);

printf("Enter the number of iterations \n");
scanf("%d",&n);
start = clock();

if(abs(fun(cofs,o,arr[0]))<abs(fun(cofs,o,arr[1])))
    {
        f = arr[0];
        arr[0]=arr[1];
        arr[1]=f;
    }

while(count<n)
    {
        arr[2] = arr[1] - ((fun(cofs,o,arr[1]))*(arr[1]-arr[0]))/(fun(cofs,o,arr[1])-fun(cofs,o,arr[0]));
        f = fun(cofs,o,arr[2]);
        count++;
        printf("%f ", arr[2]);

        arr[0]=arr[1];
        arr[1]=arr[2];


    }
end = clock();
total_time = ((double) (end - start)) /  CLOCKS_PER_SEC;
	//calulate total time
	

printf("Number of iterations %d \n", count);

printf("Root value is: \n %f",arr[2]);
printf("\nTime taken: %f", total_time);    

    return 0;

}

float fun (float arr[], int b, float c)
{
    float res=0;
    for(int i=b;i>=0;i--)
        {
            res = pow(c,i)*(arr[b-i]) + res;
        }
    return res;
}