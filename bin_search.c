#include <stdio.h>

int main() {
	int a[100], i, n, key, mid, high, low = 0;
	printf ("Enter the no. of elements in the array : ");
	scanf (" %d", &n);
	printf ("Enter the array in sorted order : ");
	for (i=0; i<n; i++) {
		scanf (" %d", &a[i]);
	}
	high = n-1;
	printf ("Enter the value to be searched : ");
	scanf (" %d", &key);
	while (low <= high) {
		mid = (low+high)/2;
		if (key == a[mid])
			break;
		else if (key < a[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	printf ("Element found at position : %d\n", mid);
	return 0;
}
