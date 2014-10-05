#include <stdio.h>

int recur (int n) {
	if (n==1)
		return 1;
	else if (n==0)
		return 0;
	else
		return recur(n-1) + recur(n-2);
}

int main() {
	int n;
	printf ("Enter an n : ");
	scanf (" %d", &n);
	printf ("%dth term is : %d\n", n+1, recur(n));
	return 0;
}
