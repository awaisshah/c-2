#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void primes(int n) {
	int i, k;
	int *a;
	a = malloc((n+1)*sizeof(int));
	for (i=0; i<n; i++) {
		a[i] = 1;
	}
	a[0] = 0;
	a[1] = 0;
	for (i=2; i<=sqrt(n); i++) {
		if (a[i]) {
			for (k=i*i; k<=n; k+=i) {
				a[k] = 0;
			}
		}
	}
	for (i=2; i<=n; i++) {
		if (a[i])
			printf ("%d ", i);
	}
	printf ("\n");
	free(a);
}

int main() {
	int n;
	printf ("Print primes till: ");
	scanf (" %d", &n);
	primes(n);
	return 0;
}
