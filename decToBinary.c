#include <stdio.h>

int decToBinary (int n) {
	int result =0;
	int mult = 1;

	while (n) {
		result+=(n%2)*mult;
		mult=mult*10;
		n/=2;
	}
	
	return result;
}

int main() {
	int n;
	printf ("Enter a decimal to be converted to binary: ");
	scanf ("%d", &n);
	printf ("Binary form of %d is %d\n", n, decToBinary(n));
	return 0;
}
