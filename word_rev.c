#include <stdio.h>
#include <string.h>

void reverse (char *begin, char *end) {
	char temp;
	while (begin < end) {
		temp = *begin;	
		*begin++ = *end;
		*end-- = temp;
	}
}

void word_rev(char *s) {
	char *word_beg = s;
	char *temp = s;
	while (*temp) {
		temp++;
		if (*temp == '\0')
			reverse (word_beg, temp-1);
		else if (*temp == ' ') {
			reverse (word_beg, temp-1);
			word_beg = temp+1;
		}
	}
}

int main() {
	char s[] = "good guys are gods";	
	//printf ("Enter a string : ");
	//fgets (s, 100, stdin);
	word_rev(s);
	printf ("%s", s);
	return 0; 
}
