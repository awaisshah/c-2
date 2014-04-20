#include <stdio.h>
#include <string.h>

void check (char *a, char *b, int (*cmp)(const char*, const char*));

int main()
{
   char s1[10],s2[10];
   int (*p)();
   p=strcmp;
   fgets(s1, sizeof(s1), stdin);
   fgets(s2, sizeof(s2), stdin);
   check (s1,s2,p);
   return 0;
}

void check(char *a, char *b, int (*cmp)(const char*, const char*))
{
   printf ("Check for equality \n");
   if (!(*cmp)(a,b))
     printf("Equal\n");
   else
     printf ("Not equal\n");
}
