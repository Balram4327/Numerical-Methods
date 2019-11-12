//Gauss Seidel Method to solve system of linear equations
#include<stdio.h>

int main()
{
    int n;

    printf("Enter the order: ");
    scanf("%d",&n);

    float A[n][n];
    float B[n];
    float X[n];
    float sum;

    printf("Enter the matrix(A): \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }

    printf("Enter the solution matrix(B): \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&B[i]);
        X[i] = 0.0;
    }

    for(int k=0;k<10;k++)
    {
    for(int i=0;i<n;i++)
    {   
        sum = 0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            sum = sum + (A[i][j]*X[j]);
        }
        X[i] = (B[i] - sum)/A[i][i];
        printf("%f ",X[i]);
    }    
    printf("\n");
    }

    printf("Final Solution: \n");
    for(int i=0;i<n;i++)
    printf("%f ",X[i]);

return 0;
}