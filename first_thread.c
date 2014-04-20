#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void * print (void *);

int main()
{
   pthread_t thread1, thread2;
   const char *msg1 = "Thread 1";
   const char *msg2 = "Thread 2";
   int t1,t2;
   t1 = pthread_create(&thread1, NULL, print, (void*)msg1);
   t2 = pthread_create(&thread2, NULL, print, (void*)msg2);
   printf("Thread 1 returns : %d\n", t1);
   printf("Thread 2 returns : %d\n", t2);
   pthread_join (thread1, NULL);
   pthread_join (thread2, NULL);
   return (0);
}

void * print (void *ptr)
{
   char * message;
   message = (char*) ptr;
   printf ("Printing message on : %s\n",message);

}
