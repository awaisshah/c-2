#include <stdio.h>
#include <stdlib.h>

int main() {
	char * line;
	while (1) {
		printf ("$ ");
		fgets (line, 10, stdin);
		system (line);
	}
	return 0;
}
