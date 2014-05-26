#include <stdio.h>
#include <string.h>

void copystring (char *a, char *b, char* (*cp)(const char*, const char*));

int main()
{
   char s1[80], s2[80];
   char* (*p)();
   
   p = strcpy;
   
   fgets (s1, 100, stdin);
   copystring(s1,s2, p);
   printf("%s\n",s2);
}

void copystring(char* a, char *b, char* (*cp)(const char* a, const char* b))
{
   int i=0;
   printf("\nRunning the copystring function\n");
   for (i=0;*(a+i)!='\0';i++) {
	*(b+i) = *(a+i);   	
   }	 
   *(b+i) = '\0';
}
 
