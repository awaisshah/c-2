#include <stdio.h>

int partition () {

}

void quicksort () {

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
	return  0;
}
