#include<stdio.h>

int main()
{
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d",&n);
    float A[n][n];
    float L[n][n];
    float U[n][n];
    float sol[n];

    printf("Enter the matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&A[i][j]);

            if(i==j)
            L[i][j] = 1;

            else if(i>j)
            U[i][j] = 0;

            else
            L[i][j] = 0;
        }
    }

    printf("Enter the solution matrix: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&sol[i]);

    }


float temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            for(int k=-1;k<n;k++)
            {
                if(k==-1)
                temp = 0;

                else if(k!=j&&k!=i)
                temp = temp + L[i][k]*U[k][j];
            }

            if(i>j)
            {
            L[i][j] = (A[i][j] - temp)/(U[j][j]);
            }

            else
            {
            U[i][j] = (A[i][j] - temp)/(L[i][i]);
            }
         
        }
    }

printf("\n L Matrix: \n");
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",L[i][j]);
        }
        printf("\n");
    }

printf("\n U Matrix: \n");
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",U[i][j]);
        }
        printf("\n");
    } 

float Y[n],X[n];
float sum;
Y[0] = sol[0];

for(int i=1;i<n;i++)
{
    sum = 0;
    for(int j=0;j<i;j++)
    {
        sum = L[i][j]*Y[j] + sum;
    }
    Y[i] = sol[i] - sum;
}

X[n-1] = Y[n-1]/U[n-1][n-1];
for(int i=n-2;i>-1;i--)
{
    sum = 0;
    for(int j=n-1;j>i;j--)
    {
        sum = U[i][j]*X[j] + sum;
    }
    X[i] = (Y[i] - sum)/U[i][i];
}

printf("Solution: ");
for(int i=0;i<n;i++)
printf("%f ",X[i]);
}
