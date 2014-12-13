#include <stdio.h>

int main() {
	long sum = 0;
	int f=1, s=1;
	int t;
	while (t <= 4000000) {
		t = f+s;
		f=s;
		s=t;
		if (t%2==0)
			sum+=t;
	}
	printf ("Sum: %d\n", sum);
	return 0;
}
