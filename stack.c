#include <stdio.h>
#include <stdlib.h>

struct stack {
	int n;
	struct stack *next;
} *head, *node, *temp;

void push();
void pop();
void view();

int main() {
	char c;
	head = NULL;
    while (c !=  'd') {
        printf ("\na. Add an element\n");
        printf ("b. Delete an element\n");
        printf ("c. View elements\n");
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
	return 0;	
}

void push() {
	int val;
	printf ("\nEnter the value to be pushed to the stack : ");
	scanf (" %d", &val);
	node = malloc (sizeof(struct stack));
	node->n = val;
	if (head == NULL) {
		node->next = NULL;
		head = node;
	}
	else {
		node->next = head;
		head = node;
	}
}

void pop() {
	printf ("\nValue being popped is : %d\n", head->n);
	temp = head;
	head = head->next;
	free (temp);
}

void view() {
	printf ("\nThe nodes on the stack are : ");
	node = head;
	while (node != NULL) {
		printf ("%d ", node->n);
		node = node->next;
	}
	printf ("\n");
}
