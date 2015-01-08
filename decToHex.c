#include <stdio.h>
#include <string.h>

void decToHex (int n) {
	char a[] = "0123456789ABCDEF";
	char hex[20];
	int i=0;
	while (n) {
		hex[i++] = a[n%16];
		n=n/16;
	}
	hex[i] = '\0';
	for (i=strlen(hex)-1; i>=0; i--) {
		printf ("%c", hex[i]);
	}
	printf ("\n");
}

int main() {
	int n;
	printf ("Enter a decimal to be converted to hex: ");
	scanf ("%d", &n);
	printf ("Hex of %d is ", n);
	decToHex(n);
	return 0;
}
