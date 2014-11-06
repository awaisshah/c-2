#include <stdio.h>
#include <stdlib.h>
struct hash {
	int data;
	struct hash* next;
};

struct hash ht[11];

void display (int n) {
	struct hash* node = &ht[n%11];
	while (node != NULL) {
		printf ("%d ", node->data);
		node = node->next;
	}
	printf ("\n");
}

int main() {
	int n = 1, i;
	for (i=0; i<11; i++) {
		ht[i].data=-1;
		ht[i].next = NULL;
	}
	while (n) {
	printf ("Enter an element : ");
	scanf ("%d", &n);
	if (ht[n%11].data == -1) {
		ht[n%11].data = n;
		ht[n%11].next = NULL;
	}
	else {
		struct hash *node;
		node = malloc(sizeof(struct hash));
		node->data = ht[n%11].data;
		node->next =  ht[n%11].next;
		ht[n%11].data = n;
		ht[n%11].next = node;
		display(n);
	}
	}
	return 0; 	
}
