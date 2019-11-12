//Program for Lagrange Interpolation
#include<stdlib.h>
#include<stdio.h>

float interpolate(float [], int, int, float);

int main()
{
	int n;
	n=7; //Default number
	float data[n];

//Default data
	data[0] = 0.0;
	data[1] = 1.6;
	data[2] = 3.8;
	data[3] = 4.5;
	data[4] = 6.3;
	data[5] = 9.2;
	data[6] = 10.0;
	
	int j=3;

	float res, dp;

	dp = 1;

	res = interpolate(data, j, n, dp);

	printf("The value at 1 is: %f",res);

	return 0;
}

float interpolate(float data[], int j, int n, float dp)
{
	float num = 1, den =1;

	for( int i=0;i<=n;i++)
		if(i!=j)
		num = num * (dp - data[i]);

	for( int i=0;i<=n;i++)
		if(i!=j)
		den = den * (data[j] - data[i]);

	return num/den;
}