#include <stdio.h>
#include <sys/time.h>

void print() {
	int i=0;
	for (i=0; i<100; i++) {
	//printf ("This is me\n");
	}
}

int main() {
	struct timeval s1, s2;
	gettimeofday (&s1, NULL);
	print();
	gettimeofday (&s2, NULL);
	printf ("%d\n", s2.tv_usec - s1.tv_usec);	
	return 0;
}
