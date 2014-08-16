#include <stdio.h>
#include <stdlib.h>

struct queue {
	int n;
	struct queue *next;
} *head, *tail, *node, *temp;

void push();
void pop();
void view();

int main() {
	int i,j;
	char c;
	head = NULL;
    while (c != 'd') {
        printf ("\na. Add an element\n");
        printf ("b. Delete an element\n");
        printf ("c. View nth element\n");
        printf ("d. Exit\n");
        printf ("Enter a choice : ");
        scanf (" %c", &c);
        if (c == 'a')
            push();
        else if (c == 'b')
            pop();
        else if (c == 'c')
            view();
    }
}

void push () {
	int val;
	printf ("Enter the value to be pushed : ");
	scanf (" %d", &val);
	if (head == NULL) {
		node = malloc (sizeof (struct queue));
		node->n = val;
		node->next = NULL;
		head = node;
		tail = node;
	}
	else {
		node = malloc (sizeof (struct queue));
		node->n = val;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
	
}

void pop() {
	if (head == NULL) {
		printf ("\nOverflow!!!\n");
		exit (0);
	}
	else {
		printf ("\nValue being popped is : %d\n", head->n);
		temp = head;
		head = head->next;
		free (temp);
	}
}

void view() {
	node = head;
	printf ("\nThe elements are : ");
	while (node != NULL) {
		printf ("%d ", node->n);
		node = node->next;
	}
	printf ("\n");
}
