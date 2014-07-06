#include <stdio.h>

int main ()
{
   char string[100];
   char* str = string;
   int i = 0, j = 0, k=0;
   char temp;
   printf ("Enter a string : ");
   fgets (string, sizeof(string), stdin);
   for (i=0; *(str+i)!='\0';i++)
	j++;
   j--;
   printf ("String length : %d\n", j);
   for (i=0, k=j-1;i<j/2;i++,k--)
   {
	temp = *(str+i);
	*(str+i) = *(str+k);
	*(str+k) = temp;
   }
   *(str+j)='\0';
   printf ("Reversed string is : %s\n",str);
}	   	
