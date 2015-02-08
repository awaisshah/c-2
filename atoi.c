#include <stdio.h>

int atoi (char *s) {
	int x=0, i=0;
	while (*(s+i)) {
		x = x*10 + (*(s+i)-'0');
		i++;
	}
	return x;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf ("Input Format: ./[exe] [string to be converted]\n");
		return 1;
	}
	printf ("The number is: %d\n", atoi(argv[1]));
	return 0;
}
