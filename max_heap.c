#include <stdio.h>
#include <stdlib.h>

int left (int i) {
	return 2*i+1;
}

int right (int i) {
	return 2*i+2;
}

int parent (int i) {
	return (i-1)/2;
}

void swap (int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void max_heapify (int a[], int n, int i) {
	int l,r;
	int largest;
	l = left(i);
	r = right(i);
	
	if ((l < n) && a[l]>a[i]) 
		largest = l;
	else 
		largest = i;

	if ((r < n) && a[r]>a[largest]) 
		largest = r;

	if (largest != i) {
		swap (&a[i], &a[largest]);
		max_heapify(a,n,largest);
	}
	
}

void build_heap (int a[], int n) {
	int i;
	for (i=n/2; i>=0; i--) {
		max_heapify (a,n,i);
	}
}

int extract_max (int a[], int *n) {
	int max = a[0];
	a[0] = a[*n-1];
	(*n)--;
	max_heapify (a,*n,0);
	return max;
}

int main() {
	int *a;
	int n,i;	
	printf ("Enter the size of heap: ");
	scanf (" %d", &n);
	a = malloc (n*sizeof(int));
	printf ("Enter %d elements: ", n);

	for (i=0; i<n; i++) {
        scanf (" %d", &a[i]);
    }

	build_heap(a,n);
	printf ("After build_heap: ");
	for (i=0; i<n; i++)
        printf ("%d ", a[i]);
	
	printf ("\nMax: %d\n", extract_max(a,&n));
	printf ("Max: %d\n", extract_max(a,&n));
	printf ("Max: %d\n", extract_max(a,&n));
	printf ("Max: %d\n", extract_max(a,&n));

	// Heap after extract_max
	for (i=0; i<n; i++)
        printf ("%d ", a[i]);
	printf ("\n");
	free(a);
	return 0;
}
