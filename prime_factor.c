#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void factor (int n) {
	int i;
	for (i=2; i<=sqrt(n); i++) {
		while (n%i==0) {
			printf ("%d ", i);
			n/=i;
		}
	}
	if (n>1)
		printf ("%d\n", n);
	else
		printf ("\n");
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf ("Input form: ./[exe] [number]");
		return 1;
	}
	factor (atoi(argv[1]));
	return 0;
}
