#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int n, c, a=0, b=1, i=0;
	pid_t pid;
	if (argc == 2)
		n = atoi (argv[1]);
	else {
		printf ("Usage : ./(executable) (no. of terms)\n");
		exit (1);
	}
	pid = fork ();
	if (pid <0) {
		fprintf (stderr, "Fork failed\n");	
		return 1;
	}
	else if (pid == 0) {
		printf ("Enter the no. of terms in the sequence : ");
		fscanf (stdin , "%d", &n);
		if (n == 1)
		  printf ("%d ", a);
		else if (n == 2)
		  printf ("%d %d ",a,b);
		else {
		  printf ("%d %d ", a, b);
		  c = a + b;
		  for (i=0;i<n-2;i++) {
			printf ("%d ", c);
			a = b;
			b = c;
			c = a + b;
		  }
		}
	}
	else {
		printf ("\nI am the parent!\n");
	}
}			 	
