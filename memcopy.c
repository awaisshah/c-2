#include <stdio.h>
#include <stdlib.h>

void memcopy (void *src, void *dst, int size) {
	char *csrc = (char*) src;
	char *cdst = (char*) dst;
	
	char *temp = malloc(size);

	int i;

	for (i=0; i<size; i++) {
		temp[i] = csrc[i];
	}

	for (i=0; i<size; i++) {
		cdst[i] = temp[i];
	}
}

int main() {
	int src[] = {1,2,3,4,5}, i;
	int n = sizeof(src) / sizeof(src[0]);
	int *dst = malloc(n*sizeof(src[0]));
	memcopy((void*)src,(void*)dst,sizeof(src));
	printf ("Destination is: ");
	for (i=0; i<n; i++) {
		printf ("%d ", dst[i]);
	}
	printf ("\n");
	free(dst);
	return 0;
}
