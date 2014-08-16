#include <stdio.h>
#include <stdlib.h>
struct list {
	int n;
	struct list *next;
} *head, *node, *temp;

void addn();
void deleten();
void viewn();
void view();
void deletenth();

int main() {
	char c;
	head = NULL;
	while (c != 'f') {	
		printf ("\na. Add an element\n");
		printf ("b. Delete an element\n");
		printf ("c. View nth element\n");
		printf ("d. View all elements\n");
		printf ("e. Delete nth element\n");
		printf ("f. Exit\n");
		printf ("Enter a choice : ");
		scanf (" %c", &c);
		if (c == 'a')
			addn();
		else if (c == 'b')
			deleten();
		else if (c == 'c')
			viewn();
		else if (c == 'd')
			view();
		else if (c == 'e')
			deletenth();
	}
}

void addn () {
	int val;
	printf ("Enter the value to be added to the list : ");
	scanf (" %d", &val);
	node = (struct list *) malloc(sizeof(struct list));
	node->n = val;
	node->next = head;
	head = node;
	printf ("Element %d added to the list\n", head->n);
}

void deleten() {
	printf ("Element being deleted : %d", head->n);
	temp = head;
	head = head->next;
	free (temp);
}

void viewn() {
	int i, pos;
	node = head;
	printf ("Enter the position of element to be viewed : ");
	scanf (" %d", &pos);
	for (i=0; i<pos-1 && node!=NULL; i++) {
		node = node->next;
	}
	printf ("Value is : %d\n", node->n);
}

void view () {
	printf ("The elements in the list are : ");
	node = head;
	while (node != NULL) {
		printf ("%d ", node->n);
		node = node->next;
	}
	printf ("\n");
}

void deletenth () {
	int i, pos;
	printf ("Enter the position of the element to be deleted : ");
	node = head;
	scanf (" %d", &pos);
	if (pos == 1) {
		temp = node;
		node = node->next;
		head = node;
		free (temp);
	}
	else {
		for (i=0;i<pos-2; i++) {
			node = node->next;
		}
		temp = node->next;
    	node->next = (node->next)->next;
    	free (temp);
	}
	node = head;
	while (node != NULL) {
        printf ("%d ", node->n);
        node = node->next;
    }
    printf ("\n");
	
}
