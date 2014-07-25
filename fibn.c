/* Program to print nth element using recursive function */
#include <stdio.h>

int fib (int n)
{	
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else
		return  fib(n-1)+fib(n-2);
}

int main()
{
	int n, sum=0;
	printf ("Enter the no. of elements : ");
	scanf ("%d", &n);	
	printf ("The sum of the elements is : ");
	sum = fib(n);
	printf ("%d\n", sum);
	return 0;
}
