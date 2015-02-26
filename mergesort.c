#include <stdio.h>

void merge (int a[], int low, int mid, int high) {

		int b[100];
		int i=low, j=mid+1, k=0;

		while (i<=mid && j<=high) {
			if (a[i] < a[j])
				b[k++] = a[i++];
			else
				b[k++] = a[j++];
		}
		
		while (i<=mid)
			b[k++]=a[i++];

		while (j<=high)
			b[k++]=a[j++];

		k--;	
	
		while (k>=0) {
			a[low+k] = b[k];
			k--;
		}

}

void mergesort (int a[], int low, int high) {
	
	if (low < high) {
		
		int mid = (low+high)/2;
		mergesort (a,low,mid);
		mergesort (a,mid+1,high);
		merge (a,low,mid,high);			

	}

}

int main() {
	
	int n, a[100], i;
	printf ("Enter n: ");
	scanf (" %d", &n);

	printf ("Enter array: ");
	for (i=0; i<n; i++) {
		scanf (" %d", &a[i]);
	}
	
	mergesort (a,0,n-1);

	printf ("The sorted array is: ");
	for (i=0; i<n; i++) {
		printf ("%d ", a[i]);
	}	
	printf ("\n");
	return 0;
}
