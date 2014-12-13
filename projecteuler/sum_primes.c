#include <stdio.h>
#include <math.h>
int isPrime(int n) {
	int i;
	for (i=3; i<=sqrt(n); i+=2) {
		if (n%i==0)
			return 0;
	}
	return 1;
}

int main() {
	long sum = 2, n=3;
	while (n < 2000000) {
		if (isPrime(n))
			sum+=n;
		n+=2;
	}	
	printf ("Sum: %ld\n", sum);
	return 0;
}
