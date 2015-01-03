#include <stdio.h>
#include <string.h>

char p[20], q[20];

void encode (char* p) {
	int i;
	for (i=0; p[i]!='\0'; i++) {
		if (i<1) {
			q[i] = p[i] + p[i+1] - 48;
		}
	
		else if (i == strlen(p)-2) {
			q[i] = p[i-1] + p[i] - 48;
		}

		else
			q[i] = p[i-1] + p[i] + p[i+1] - 96;
	}
	q[i] = '\0';
}

void decode(char* q, int f) {
	int i;
	p[0] = f+48;
	p[1] = q[0] - p[0] + 48;
	if (p[1]<48 || p[1]>57) {
		strcpy(p, "NONE");
		return;
	}
	
	p[strlen(q)-1] = '\0';
	for (i=1; i<strlen(q)-2; i++) {
		p[i+1] = q[i] - p[i-1] - p[i] + 96;
		if (p[i+1]<48 || p[i+1]>57) {
			strcpy (p, "NONE");
			return;
		}
	}
}

int main() {
	int i;
	printf ("Enter a binary string: ");
	fgets (p, 20, stdin);
	encode(p);
	printf ("Encoded string is: %s\n", q);
	decode (q,0);
	printf ("Decoded string with first digit 0: %s\n", p);	
	decode (q,1);
	printf ("Decoded string with first digit 1: %s\n", p);
	return 0;
}
