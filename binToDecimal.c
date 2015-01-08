#include <stdio.h>

int toDecimal(int n) {
	int result=0;
	int mult=1;
	int b=2;

	while (n) {
		result+= (n%10) * mult;
		mult*=b;
		n/=10;
	}

	return result;
}

int main() {
	int n;
	printf ("Enter a binary integer: ");
	scanf ("%d", &n);
	printf ("Decimal form of %d is %d\n", n, toDecimal(n));
	return 0;
}
