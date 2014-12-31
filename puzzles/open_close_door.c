#include <stdio.h>

#define DOORS 12

int main() {
	int a[DOORS], i, j;
	for (i=0; i<DOORS; i++)
		a[i] = 0;
	for (i=0; i<DOORS; i++) {
		for (j=i; j<DOORS; j=j+i+1) {
			if (a[j]==0)
				a[j]=1;
			else
				a[j]=0;
		}
	}
	for (i=0; i<DOORS; i++) 
		printf ("%d ", a[i]);
	printf ("\n");	
	return 0;
}
