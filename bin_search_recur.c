#include <stdio.h>

int bin (int a[], int x, int low, int high) {
	if (low > high)
		return -1;
	int mid = (low+high)/2;
	if (a[mid]==x) 
		return mid;
	else if (a[mid] < x)
		return bin(a,x,low+1,high);
	else
		return bin(a,x,low,high-1);
	return -1;
}

int main() {
	int a[50];
	int i,n;
	int pos,x;
	printf ("Enter n: ");
	scanf (" %d", &n);
	printf ("Enter the array: ");
	for (i=0;i<n;i++) {
		scanf (" %d", &a[i]);
	}
	printf ("Enter the element to be searched for: ");
	scanf (" %d", &x);
	pos = bin(a,x,0,n-1);
	printf ("Position is: %d\n", pos);
	return 0;
}
