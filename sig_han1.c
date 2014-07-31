#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void err (int sig) {
	printf ("Signal %d received\n", sig);
	(void) signal (SIGINT, SIG_DFL);
}

int main() {
	(void) signal (SIGINT, err);
	while (1) {
		printf ("Hello!\n");
		sleep (1);
	}	
}
	
