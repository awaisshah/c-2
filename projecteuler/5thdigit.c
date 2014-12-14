#include <stdio.h>
#include <math.h>

int sum5th (int n) {
	int sum=0;
	while (n) {
		sum+= (n%10)*(n%10)*(n%10)*(n%10)*(n%10);
		n/=10;
	}
	return sum;
}

int main() {
	int n, sumnum, sum=0;
	for (n=2; n<1000000; n++) {
		sumnum = sum5th(n);
		if (sumnum == n) {
			sum+=n;
			printf ("n: %d\n", n);
		}
	}
	printf ("Sum: %d\n", sum);
	return 0;
}
