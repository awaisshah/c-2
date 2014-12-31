/* Largest Pandigital Prime */
/* 2,3,5,6,8,9-digit numbers cannot be prime */
/* Since we have to find the largest n-digit prime, we only need
   to check for 7-digit numbers */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPandigital(int n) {
	int i, count = 0, sum = 0, flag=0;
	int a[10];
	for (i=0; i<10; i++)
		a[i]=0; 
	int expec_sum;
	while (n) {
		count++;
		a[(n%10)+1]++;
		sum = sum + (n%10);
		n/=10;
	}	
	for (i=0; i<10; i++) {
		if (a[i]>1) {
			flag=1;
			break;
		}
	}
	expec_sum = count*(count+1)/2;
	if ((sum == expec_sum)&&(!flag))
		return 1;
	return 0;
}


int isPrime(int n) {
	int i;
	if (n%2 == 0)
		return 0;
	for (i=3; i <= sqrt(n); i+=2) {
		if (n%i==0)
			return 0;	
	}
	return 1;
}

int main() {
	int i;
	for (i=7654321; i>=1234567; i-=2) {
		if (isPandigital(i)) {
			if (isPrime(i)) {
				printf ("The largest pandigital prime is: %d\n", i);
				break;
			}
		}
	}
	return 0;
}
