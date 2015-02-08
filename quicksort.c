#include <stdio.h>

void swap (int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition (int a[], int p, int r) {
	int i,j,x;
	x = a[r];
	i = p-1;
	for (j=p; j<r; j++) {
		if (a[j] <= x) {
			i++;
			swap (&a[i], &a[j]);
		}
	}
	swap (&a[i+1],&a[r]);
	return i+1;
}

void quicksort (int a[], int p, int r) {
	int q;
	if (p<r) {
		q = partition (a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r); 
	}
}

int main() {
	int a[20], n, i;
	printf ("Enter the no. of elements: ");
	scanf (" %d", &n);
	printf ("Enter the array: ");
	for (i=0; i<n; i++) {
		scanf (" %d", &a[i]);
	}
	quicksort(a,0,n-1);
	printf ("Sorted array is: ");
	for (i=0; i<n; i++) {
		printf ("%d ", a[i]);
	}
	return  0;
}
