#include <stdio.h>

int main() {
	int i, sum=0, ssum=0;
	for (i=1; i<=100; i++) {
		sum+=i*i;
		ssum+=i;
	}
	printf ("Sum Difference: %d\n", (ssum*ssum)-sum);
	return 0;
}
