#include <stdio.h>
#include <stdlib.h>

void reverse (char *begin, char *end) {
	char temp;
	while (begin < end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

int main() {
	char *s, *temp;
	s = malloc(100);
	printf ("Enter a string : ");
	fgets(s, 100, stdin);
	temp = s;
	while (*temp) {
		temp++;
	}
	*(--temp) = '\0';
	reverse (s, temp-1);
	printf ("Reversed string is : %s\n", s);
}
