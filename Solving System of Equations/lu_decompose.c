#include<stdio.h>

int main()
{
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d",&n);
    float A[n][n];
    float L[n][n];
    float U[n][n];

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

printf("L Matrix: \n");
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",L[i][j]);
        }
        printf("\n");
    }

printf("U Matrix: \n");
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",U[i][j]);
        }
        printf("\n");
    }    
}
