#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	pid_t pid;
	char *message;
	int n;
	
	pid = fork();
	switch (pid) {
		case -1 : printf ("Error!\n");
				break;

		case 0 : message = "This is child\n";
				n=3;
				break;

		default : message = "This is parent\n";
				n=30;
				break;

	}
	while (n>0) {
		printf ("%s", message);
		n--;
		sleep (1);
	}
	if (pid != 0) {
		int stat_val;
		pid_t child_pid;

		child_pid = wait (&stat_val);
		printf ("Child has finished executing with PID : %d\n", child_pid);

		if (WIFEXITED (stat_val))
			printf ("Child exited with code %d\n", WEXITSTATUS (stat_val));
		else 
			printf ("Child terminated abnormally\n");
	}
	return 0;
}
