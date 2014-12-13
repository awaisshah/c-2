#include <stdio.h>
#include <math.h>

float sqroot(float num) {
	float low, mid, high;
	low = 0.0;
	high = num;

	while (low <= high)	{
		mid = (low+high)/2;
		if (fabs(mid*mid - num) <= 0.0001) 
			return mid;
		else if (mid*mid < num) 
			low = mid;
		else
			high = mid;
	}
	return -1;
} 

int main() {
	float a;
	printf ("Enter a number: ");
	scanf ("%f", &a);
	printf ("The square root is: %f\n", sqroot(a));
	return 0;
}
