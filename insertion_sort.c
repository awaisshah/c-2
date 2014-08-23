#include <stdio.h>

int main() {
	int a[100], i, temp, n, key, j;
	printf ("Enter the no. of elements : ");
	scanf (" %d", &n);
	printf ("Enter the array : ");
	for (i=0; i<n; i++)
		scanf (" %d", &a[i]); 	
	/* Insertion Sort */ 
	for (i=1; i<n; i++) {
		key = a[i];
        for (j=i-1; j>=0 && (a[j] > key); j--) {
			temp = a[j+1];
			a[j+1] = a[j];
			a[j] = temp;
		}
	}
	printf ("The sorted array is : ");
	for (i=0; i<n; i++) {
		printf ("%d ", a[i]);
	}
	printf ("\n");
	return 0;
}
