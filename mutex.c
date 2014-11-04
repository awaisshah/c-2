#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int count = 0;
pthread_mutex_t mutex_var = PTHREAD_MUTEX_INITIALIZER;

void* func1() {
	while (count<10) {
		if (count%2==0) {
			pthread_mutex_lock(&mutex_var);
			count++;
			printf ("t1: %d\n", count);
			pthread_mutex_unlock(&mutex_var);
		}
	}
	exit(0);
}

void* func2() {
	while (count<10) {
		if (count%2) {
			pthread_mutex_lock(&mutex_var);
			count++;
			printf ("t2: %d\n", count);
			pthread_mutex_unlock(&mutex_var);
		}
	}
	exit(0);
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);	
	return 0;
}
