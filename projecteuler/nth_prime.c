#include <stdio.h>
#include <math.h>

int isPrime(long n) {
	long i;
	for (i=3; i<=sqrt(n); i+=2) {
		if (n%i==0)
			return 0;
	}
	return 1;
}

int main() {
	int count=1;
	long n;
	for (n=3; count<=10001; n+=2) {
		if (isPrime(n)) 
			count++;
		if (count == 10001) {
			printf ("10001st prime: %ld\n", n);
			break;
		}
	}
	printf ("Count: %d\n", count);
	return 0;
}
